#include "stdafx.h"

#include "camera.h"

Point Camera::getPos()
{
  return pos;
}

void Camera::setPos(Point p)
{
  pos = p;
}

Point Camera::screenToWorld(Point p)
{
  Point ret = p;
  ret.x += pos.x;
  ret.y += pos.y;

  return ret;
}

Point Camera::worldToScreen(Point p)
{
  Point ret = p;
  ret.x -= pos.x;
  ret.y -= pos.y;

  return ret;
}
