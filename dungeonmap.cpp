#include "stdafx.h"

#include "dungeonmap.h"

void Room::addNeighbour(Room* room)
{
  Rect rect = this->intersect(room->bound);
  if ((rect.w == 0 && rect.h >= 3) || 
      (rect.h == 0 && rect.w >= 3))
  {
    neigbours.insert(room);
    room->neigbours.insert(this);
  }
}

Room::Room()
{
  price = 1;
  distance = std::numeric_limits<int>::max();
}

Rect Room::intersect(Rect other)
{
  Rect inter;
  inter.x = std::max(bound.x, other.x);
  inter.y = std::max(bound.y, other.y);

  int rx1 = bound.x+bound.w;
  int ry1 = bound.y+bound.h;

  int rx2 = other.x+other.w;
  int ry2 = other.y+other.h;

  int rx = std::min(rx1, rx2);
  int ry = std::min(ry1, ry2);

  inter.w = rx-inter.x;
  inter.h = ry-inter.y;

  return inter;
}

void DungeonMap::init()
{
  initRooms();

  //do {
  //  enter = randomRoom();
  //} while (enter->getRect().w < 4 || enter->getRect().h < 4);
  //
  //do {
  //  exit = randomRoom();
  //} while (exit == enter || exit->getRect().w < 4 || exit->getRect().h < 4);
  //
  //buildDistanceMap(exit);
}

void DungeonMap::initRooms()
{
  enter = NULL;
  exit = NULL;
  
  Rect rect = {32, 32, 32, 32};
  split(rect);

  //std::vector<Room*> ra(rooms.begin(), rooms.end());
  //for (int i = 0; i < ra.size() - 1; i++) 
  //{
  //  for (int j = i + 1; j < ra.size(); j++) 
  //  {
  //    ra[i]->addNeighbour(ra[j]);
  //  }
  //}
}

void DungeonMap::split(const Rect rect)
{
  int maxRoomSize = 9;
  int minRoomSize = 7;

  int w = rect.w;
  int h = rect.h;
  
  int x = rect.x;
  int y = rect.y;

  int square = w*h;
  
  SimpleRand rndDouble;
  
  if (w > maxRoomSize && h < minRoomSize) {
    SimpleRand rnd(3, w-3);
    int w2 = rnd.getIntRnd();
    
    split({x, y, w2, h});
    split({x+w2, y, w-w2, h});
  }
  else if (h > maxRoomSize && w < minRoomSize) {
    SimpleRand rnd(3, h-3);
    int h2 = rnd.getIntRnd();
    
    split({x, y, w, h2});
    split({x, y+h2, w, h-h2});
  }
  else if ((rndDouble.getDoubleRnd() < minRoomSize*minRoomSize/(double)square && w < maxRoomSize && h < maxRoomSize) || w < minRoomSize || h < minRoomSize){
    Room* r = new Room();
    r->setRect(rect);
    rooms.insert(r);
  }
  else {
    if (rndDouble.getDoubleRnd() < (double)(w - 2) / (w + h - 4)) {
      SimpleRand rnd(3, w-3);
      int w2 = rnd.getIntRnd();
    
      split({x, y, w2, h});
      split({x+w2, y, w-w2, h});
    }
    else {
      SimpleRand rnd(3, h-3);
      int h2 = rnd.getIntRnd();
    
      split({x, y, w, h2});
      split({x, y+h2, w, h-h2});      
    }
  }
}

void DungeonMap::buildDistanceMap(Room* focus)
{
  for (std::set<Room*>::iterator itr = rooms.begin();
       itr != rooms.end(); itr++)
  {
    (*itr)->setDistance(std::numeric_limits<int>::max());
  }

  std::list<Room*> queue;

  focus->setDistance(0);
  queue.push_back(focus);

  while (!queue.empty()) 
  {
    Room* room = queue.front();
    queue.pop_front();

    int distance = room->getDistance();
    int price = room->getPrice();

    std::set<Room*> edges = room->edges();
    for (std::set<Room*>::iterator itr = edges.begin();
	 itr != edges.end(); itr++)
    {
      Room* edge = *itr;
      if (edge->getDistance() > distance + price) 
      {
	queue.push_back(edge);
	edge->setDistance(distance + price);
      }
    }
  }
}

Room* DungeonMap::randomRoom()
{
  SimpleRand rnd(0, rooms.size()-1);
  int count = rnd.getIntRnd();

  std::set<Room*>::iterator itr = rooms.begin();
  while(count-- > 0) {
    itr++;
  }

  return *itr;
}
