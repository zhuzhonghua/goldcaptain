#include "stdafx.h"
#include "game.h"
#include "util.h"
#include "dungeonmap.h"
#include "imageutil.h"
#include "camera.h"

Game::Game()
{
  _width = 960;
  _height = 640;

  _gameExit = false;
}

void Game::init()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  _window = SDL_CreateWindow( "Gold Captain", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
  _renderer = SDL_CreateRenderer(_window, -1, 0);

  _fpsLimiter.setMaxFPS(60.0f);

  _map = new DungeonMap();
  _map->init();

  // black wall
  _wall = ImageUtil::createSolid(_renderer, 2, 2, 0, 0, 0, 255);
  camera = new Camera();
  Camera::setMain(camera);
}

void Game::run()
{
  SDL_StartTextInput();	
  while(_gameExit == false){
    _fpsLimiter.begin();

    SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
    SDL_RenderClear(_renderer);
    
    _inputMgr.update();
    
    processInput();
    update();
    draw();
    
    SDL_RenderPresent(_renderer);
    
    _fps = _fpsLimiter.end();
  }
  SDL_StopTextInput();

  SDL_DestroyWindow(_window);
  SDL_DestroyRenderer(_renderer);
  SDL_Quit();
}

void Game::draw()
{
  std::set<Room*> rooms = _map->getRooms();
  for (std::set<Room*>::iterator it = rooms.begin();
       it != rooms.end(); it++) {
    Room* room = *it;
    Rect rect = room->getRect();

    rect.x += 1;
    rect.y += 1;
    rect.w -= 1;
    rect.h -= 1;
    
    Rect dst = camera->worldToScreenRect(rect);    
    
    SDL_RenderCopy(_renderer, _wall, NULL, &dst); 
  }
}

void Game::update()
{
  if (_inputMgr.isKeyDown(SDLK_a)) {
    Point point = camera->getPos();
    point.x -= 1;
    camera->setPos(point);
  }
  else if (_inputMgr.isKeyDown(SDLK_d)) {
    Point point = camera->getPos();
    point.x += 1;
    camera->setPos(point);
  }
  else if (_inputMgr.isKeyDown(SDLK_w)) {
    Point point = camera->getPos();
    point.y -= 1;
    camera->setPos(point);
  }
  else if (_inputMgr.isKeyDown(SDLK_s)) {
    Point point = camera->getPos();
    point.y += 1;
    camera->setPos(point);
  }
  else if (_inputMgr.isKeyDown(SDLK_EQUALS)) {
    camera->zoomIn(0.1);
  }
  else if (_inputMgr.isKeyDown(SDLK_MINUS)) {
    camera->zoomOut(0.1);
  }
}

void Game::processInput()
{
  SDL_Event e;
  while(SDL_PollEvent(&e) != 0){
    switch(e.type){
    case SDL_QUIT:
      _gameExit = true;
      break;
    case SDL_MOUSEMOTION:
      _inputMgr.setMouseCoords(e.motion.x, e.motion.y);
      break;
    case SDL_KEYDOWN:
      _inputMgr.pressKey(e.key.keysym.sym);
      break;
    case SDL_KEYUP:
      _inputMgr.releaseKey(e.key.keysym.sym);
      break;
    case SDL_MOUSEBUTTONDOWN:
      _inputMgr.pressKey(e.button.button);
      break;
    case SDL_MOUSEBUTTONUP:
      _inputMgr.releaseKey(e.button.button);
      break;
    }
  }
}
