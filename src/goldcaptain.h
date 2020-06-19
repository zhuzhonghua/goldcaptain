#pragma once

#include "game.h"

class GoldCaptain : public Zengine::Game{
public:
  GoldCaptain();

  virtual void init();
protected:
  virtual void update();

protected:
};