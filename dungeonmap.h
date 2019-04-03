#pragma once

#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>

typedef SDL_Rect Rect;

class Room {
public:
  Room() {}
  void setRect(const Rect& rect) { _bound = rect; }
  Rect getRect() { return _bound; }
protected:
  Rect _bound;
};

class DungeonMap {
public:
  void initRooms();
  void split(const Rect rect);
  std::set<Room*> getRooms() { return rooms; }
protected:
  std::set<Room*> rooms;
};
