#include "stdafx.h"
#include "game.h"
#include "util.h"
#include "dungeonmap.h"

Game::Game()
{
  _width = 960;
  _height = 640;

  _gameExit = false;

  _cellSize = 100;
}

SDL_Texture* Game::createSolid()
{
  Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
  rmask = 0xff000000;
  gmask = 0x00ff0000;
  bmask = 0x0000ff00;
  amask = 0x000000ff;
#else
  rmask = 0x000000ff;
  gmask = 0x0000ff00;
  bmask = 0x00ff0000;
  amask = 0xff000000;
#endif

  SDL_Surface* img = SDL_CreateRGBSurface(0, 2, 1, 32, rmask, gmask, bmask, amask);

  // white
  r1.x = 0;
  r1.y = 0;
  r1.w = 1;
  r1.h = 1;  
  SDL_FillRect(img, &r1, SDL_MapRGB ( img->format, 255, 255, 255 ));

  // black
  r2 = r1;
  r2.x = 1;
  SDL_FillRect(img, &r2, SDL_MapRGB ( img->format, 0, 0, 0 ));
  
  SDL_Texture* tex = SDL_CreateTextureFromSurface(_renderer, img);
  
  SDL_FreeSurface(img);

  return tex;
}

void Game::init()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  _window = SDL_CreateWindow( "Gold Captain", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
  _renderer = SDL_CreateRenderer(_window, -1, 0);

  _texture = createSolid();
  _fpsLimiter.setMaxFPS(60.0f);

  _map = new DungeonMap();
  _map->initRooms();
}

void Game::run()
{
  SDL_StartTextInput();	
  while(_gameExit == false){
    _fpsLimiter.begin();

    SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);
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
    
  }
  SDL_Rect dst;
  dst.x = 100;
  dst.y = 100;
  dst.w = _cellSize;
  dst.h = _cellSize;      
  SDL_RenderCopy(_renderer, _texture, &r1, &dst);

  dst.x = 100+_cellSize;
  SDL_RenderCopy(_renderer, _texture, &r2, &dst);  
}

void Game::update()
{    
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
