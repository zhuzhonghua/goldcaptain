#pragma once

#include "timing.h"
#include "inputmanager.h"

class DungeonMap;
class Camera;

class Game{
public:
  Game();
  void init();
  void run();

  Camera* getCamera() { return camera; }
protected:
  void update();
  void draw();
  void processInput();
  
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

  Camera* camera;
  
  DungeonMap* _map;
  SDL_Texture* _wall;
};
