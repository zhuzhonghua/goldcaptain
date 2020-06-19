#include "zengine.h"

#include "mainscene.h"
#include "image.h"
#include "button.h"
#include "bitmaptext.h"
#include "texturecache.h"
#include "camera.h"
#include "game.h"

#include "dungeonmap.h"

// Minimum virtual display size for portrait orientation

float MainScene::defaultZoom = 0;
float MainScene::minZoom;
float MainScene::maxZoom;

using namespace Zengine;

Camera* MainScene::uiCamera;

MainScene::MainScene()
{
	dgnMap = new DungeonMap();
}

MainScene::~MainScene()
{

}

void MainScene::init()
{
  dgnMap->init();
	//Image* img = new Image("./test.jpg");
	//add(img);

	//Button* btn = new Button("./test.jpg");
	//add(btn);

	//BitmapText* bt = new BitmapText("hello");
	//add(bt);

	//Texture* tx = TextureCache::createSolid(255, 255, 255, 255);
	//Rect rect;
	//rect.x = 100;
	//rect.y = 100;
	//rect.w = 10;
	//rect.h = 10;
	//
	//for (int i = 0; i < 9; i++)
	//{
	//	Image* img = new Image(tx);
	//	testImgs.push_back(img);
	//	add(img);
//
	//	img->setRect(rect);
	//	rect.x += 20;
	//}
	
  Texture* tx = TextureCache::createSolid(255, 255, 255, 255);
  std::set<Room*> rooms = dgnMap->getRooms();
  for (std::set<Room*>::iterator itr = rooms.begin(); 
        itr != rooms.end(); itr++) {
    Room* room = *itr;

    Image* img = new Image(tx);
		testImgs.push_back(img);
		add(img);
    img->setRect(room->getRect());
  }
}

void MainScene::update()
{	
}