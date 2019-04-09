#pragma once

#include "util.h"

class Camera{
public:
  Point getPos();
  void setPos(Point p);

  Point screenToWorld(Point p);
  Point worldToScreen(Point p);
protected:
  Point pos;
};
