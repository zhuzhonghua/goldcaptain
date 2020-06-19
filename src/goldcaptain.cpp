#include "zengine.h"

#include "goldcaptain.h"
#include "camera.h"
#include "inputmanager.h"


using namespace Zengine;

GoldCaptain::GoldCaptain()
{
}

void GoldCaptain::init()
{
  Game::init();
}

void GoldCaptain::update()
{
	Game::update();

	InputManager* inputMgr = &_inputMgr;

	Camera* camera = Camera::getMain();
	if (inputMgr->isKeyDown(SDLK_a)) {
    Point point = camera->getPos();
    point.x -= 1;
    camera->setPos(point);
  }
  else if (inputMgr->isKeyDown(SDLK_d)) {
    Point point = camera->getPos();
    point.x += 1;
    camera->setPos(point);
  }
  else if (inputMgr->isKeyDown(SDLK_w)) {
    Point point = camera->getPos();
    point.y -= 1;
    camera->setPos(point);
  }
  else if (inputMgr->isKeyDown(SDLK_s)) {
    Point point = camera->getPos();
    point.y += 1;
    camera->setPos(point);
  }
  else if (inputMgr->isKeyDown(SDLK_EQUALS)) {
    camera->zoomIn(0.1);
  }
  else if (inputMgr->isKeyDown(SDLK_MINUS)) {
    camera->zoomOut(0.1);
  }
}