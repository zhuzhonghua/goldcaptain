#include "zengine.h"

#include "mainscene.h"
#include "image.h"
#include "button.h"
#include "bitmaptext.h"
#include "texturecache.h"
#include "camera.h"
#include "game.h"
#include "inputmanager.h"

// Minimum virtual display size for portrait orientation

float MainScene::defaultZoom = 0;
float MainScene::minZoom;
float MainScene::maxZoom;

using namespace Zengine;

Camera* MainScene::uiCamera;

MainScene::MainScene()
{
}

MainScene::~MainScene()
{

}

void MainScene::init()
{
	//Image* img = new Image("./test.jpg");
	//add(img);

	//Button* btn = new Button("./test.jpg");
	//add(btn);

	BitmapText* bt = new BitmapText("hello");
	add(bt);

	Texture* tx = TextureCache::createSolid(255, 255, 255, 255);
	Rect rect;
	rect.x = 100;
	rect.y = 100;
	rect.w = 10;
	rect.h = 10;
	
	for (int i = 0; i < 9; i++)
	{
		Image* img = new Image(tx);
		testImgs.push_back(img);
		add(img);

		img->setRect(rect);
		rect.x += 20;
	}
	
}

void MainScene::update()
{
	InputManager* inputMgr = Game::inst()->getInputMgr();

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