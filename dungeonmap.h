#pragma once

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

class Rect {
public:
  int left() const { return _data.x; }
  int top() const { return _data.y; }
  int right() const { return _data.z; }
  int bottom() const { return _data.w; }

  int width() const { return right() - left(); }
  int height() const { return bottom() - top(); }

  Rect(int l, int t, int r, int b) : _data(l,t,r,b) {}
  Rect() {}
protected:
  // left x
  // top y
  // right z
  // bottom w
  glm::ivec4 _data;
};

class Room {
public:
  Room() {}
  void setRect(const Rect& rect) { _bounds = rect; }
protected:
  Rect _bounds;
};

class DungeonMap {
public:
  void initRooms();
  void split(const Rect& rect);
  std::set<Room*> getRooms() { return rooms; }
protected:
  std::set<Room*> rooms;
};
