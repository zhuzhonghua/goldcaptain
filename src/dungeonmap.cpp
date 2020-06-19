#include "zengine.h"
#include "util.h"
#include "game.h"
#include "dungeonmap.h"

using namespace Zengine;

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
  
  Rect rect = {0, 0, Game::getWidth(), Game::getHeignt()};
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

void DungeonMap::split(Rect rect)
{
  int roomSizeLimit = 9;

  int x = rect.x;
  int y = rect.y;
  int w = rect.w;
  int h = rect.h;

  Rect rect1;
  Rect rect2;
    
  if (rect.w > roomSizeLimit && rect.h > roomSizeLimit) {
    DoubleRand dbleRnd;
    double rndNum = dbleRnd.getDouble();
    if (rndNum > 0.5f) {
      IntRand rnd(3, h-3);
      int h2 = rnd.getInt();
      rect1 = Utils::rect(x, y, w, h2);
      rect2 = Utils::rect(x, y+h2, w, h-h2);
    } else {
      IntRand rnd(3, w-3);
      int w2 = rnd.getInt();
      rect1 = Utils::rect(x, y, w2, h);
      rect2 = Utils::rect(x+w2, y, w-w2, h);
    }
  } else if (w > roomSizeLimit) {
    IntRand rnd(3, w-3);
    int w2 = rnd.getInt();
    rect1 = Utils::rect(x, y, w2, h);
    rect2 = Utils::rect(x+w2, y, w-w2, h);
  } else if (h > roomSizeLimit) {
    IntRand rnd(3, h-3);
    int h2 = rnd.getInt();
    rect1 = Utils::rect(x, y, w, h2);
    rect2 = Utils::rect(x, y+h2, w, h-h2);
  } else {
    ASSERT(h >= 3);
    ASSERT(w >= 3);

    int h2;
    if (h-1 > 3) {
      IntRand rnd(3, h-1);
      h2 = rnd.getInt();
    } else {
      h2 = 3;
    }

    int w2;
    if (w-1 > 3) {
      IntRand rnd2(3, w-1);
      w2 = rnd2.getInt();
    } else {
      w2 = 3;
    }    

    Rect rec = {x+(w-w2)/2, y+(h-h2)/2,w2, h2};
    Room* r = new Room();
    r->setRect(rec);
    rooms.insert(r);
    return;
  }

  split(rect1);
  split(rect2);
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
  //SimpleRand rnd(0, rooms.size()-1);
  //int count = rnd.getIntRnd();

  //std::set<Room*>::iterator itr = rooms.begin();
  //while(count-- > 0) {
  //  itr++;
  //}
//
  //return *itr;
  return NULL;
}
