#pragma once

class SimpleRand{
public:
  SimpleRand(int min, int max);
  SimpleRand();
  
  int getIntRnd();
  double getDoubleRnd();
protected:
  boost::random::mt19937 _randEngine;
  boost::random::uniform_int_distribution<> _rndInt;
  boost::random::uniform_real_distribution<> _rndDouble;
};

class Point{
public:
  Point();
protected:
  void init(float xp, float yp);
public:
  float x;
  float y;
};
