#pragma once

#include "util.h"

class Camera{
public:
  Point getPos();
  void setPos(Point p);
  void update();
protected:
  Point _pos;
};
