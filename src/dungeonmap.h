#pragma once

class Room {
public:
  Room();
  void setRect(const Rect& rect) { bound = rect; }
  Rect getRect() { return bound; }
  void addNeighbour(Room* room);
  std::set<Room*> edges() { return neigbours; }
  
  void setDistance(int dist) { distance = dist; }

  int getDistance() { return distance; }
  int getPrice() { return price; }
  
protected:
  Rect intersect(Rect other);
protected:
  Rect bound;

  std::set<Room*> neigbours;

  int distance;
  int price;
};

class DungeonMap {
public:
  void init();

  std::set<Room*> getRooms() { return rooms; }
protected:
  void split(const Rect rect);
  void initRooms();
  void buildDistanceMap(Room* focus);
  Room* randomRoom();
protected:
  std::set<Room*> rooms;

  Room* enter;
  Room* exit;
};
