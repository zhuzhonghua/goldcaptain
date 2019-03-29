#pragma once

#include "timing.h"
#include "inputmanager.h"

class DungeonMap;

class Game{
public:
  Game();
  void init();
  void run();

protected:
  void update();
  void draw();
  void processInput();

  SDL_Texture* createSolid();
  
protected:
  bool _gameExit;
  FPSLimiter _fpsLimiter;

  float _fps;
protected:
  int _width;
  int _height;
  
  SDL_Window* _window;
  SDL_Renderer* _renderer;

  InputManager _inputMgr;

  DungeonMap* _map;
  SDL_Texture* _texture;
  SDL_Rect r1;
  SDL_Rect r2;

  int _cellSize;
};
