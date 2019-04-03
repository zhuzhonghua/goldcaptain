#include "stdafx.h"

#include "dungeonmap.h"

void DungeonMap::initRooms()
{
  Rect rect = {0, 0, 960, 640};
  split(rect);
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
