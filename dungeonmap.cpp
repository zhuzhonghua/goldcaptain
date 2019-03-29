#include "stdafx.h"

#include "dungeonmap.h"

void DungeonMap::initRooms()
{
  Rect rect(0, 0, 960, 640);
  split(rect);
}

void DungeonMap::split(const Rect& rect)
{
  int maxRoomSize = 10;
  int minRoomSize = 3;

  int w = rect.width();
  int h = rect.height();
  
  int l = rect.left();
  int t = rect.top();
  int r = rect.right();
  int b = rect.bottom();

  int square = w*h;
  
  SimpleRand rndDouble;
  
  if (w > maxRoomSize && h < minRoomSize) {
    SimpleRand rnd(l+3, r-3);
    int w2 = rnd.getIntRnd();
    
    split(Rect(l, t, w2, b));
    split(Rect(w2, t, r, b));
  }
  else if (h > maxRoomSize && w < minRoomSize) {
    SimpleRand rnd(t+3, b-3);
    int h2 = rnd.getIntRnd();
    
    split(Rect(l, t, r, h2));
    split(Rect(l, h2, r, b));
  }
  else if (w < minRoomSize || h < minRoomSize ||
	   (w < maxRoomSize && h < maxRoomSize && rndDouble.getDoubleRnd() < minRoomSize*minRoomSize/square)){
    Room* r = new Room();
    r->setRect(rect);
    rooms.insert(r);
  }
  else {
    if (rndDouble.getDoubleRnd() < (double)(w - 2) / (w + h - 4)) {
      SimpleRand rnd(l+3, r-3);
      int vw = rnd.getIntRnd();
      split(Rect(l, t, vw, b));
      split(Rect(vw, t, r, b));
    }
    else {
      SimpleRand rnd(t+3, b-3);
      int vh = rnd.getIntRnd();
      split(Rect(l, t, r, vh));
      split(Rect(l, vh, r, b));
    }
  }
}
