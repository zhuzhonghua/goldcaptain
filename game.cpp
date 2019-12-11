#include "stdafx.h"
#include "game.h"
#include "util.h"
#include "dungeonmap.h"
#include "imagemanager.h"
#include "camera.h"
#include "window.h"
#include "graphic.h"
#include "image.h"

Game::Game()
{
  _gameExit = false;
}

void Game::init()
{
	_window = new Zengine::Window("Gold Captain", 640, 960);

  _fpsLimiter.setMaxFPS(60.0f);

  _map = new DungeonMap();
  _map->init();

	_imageMgr = new Zengine::ImageManager();
	_imageMgr->setRender(_window->getRender());

	Zengine::Graphic::setRender(_window->getRender());
	
  // black wall
  _wall = _imageMgr->getSolid(2, 2, 0, 0, 0, 255);
  camera = new Camera();
  Camera::setMain(camera);
}

void Game::run()
{
  _window->start();
	
  while(_gameExit == false){
    _fpsLimiter.begin();

		Zengine::Graphic::setDrawColor(255, 255, 255, 255);
		Zengine::Graphic::clearRender();
    
    _inputMgr.update();
    
    processInput();
    update();
    draw();
    
    _window->renderPresent();
    
    _fps = _fpsLimiter.end();
  }
	
  _window->end();
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

		Zengine::Graphic::renderCopy(_wall, NULL, &dst);
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
