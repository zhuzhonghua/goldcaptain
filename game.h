#pragma once

#include "timing.h"
#include "inputmanager.h"

class DungeonMap;
class Camera;

namespace Zengine{
class Window;
class ImageManager;
};

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
	Zengine::Window* _window;
	Zengine::ImageManager* _imageMgr;
	
	Zengine::InputManager _inputMgr;

  Camera* camera;
  
  DungeonMap* _map;
  SDL_Texture* _wall;
};
