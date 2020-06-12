#pragma once

#include "scene.h"

namespace Zengine{
class Camera;
class Image;
};

class MainScene : public Zengine::Scene{
public:
	// Minimum virtual display size for portrait orientation
	const float MIN_WIDTH_P = 128;
	const float MIN_HEIGHT_P = 224;

	// Minimum virtual display size for landscape orientation
	const float MIN_WIDTH_L = 224;
	const float MIN_HEIGHT_L = 160;

	static float defaultZoom;
	static float minZoom;
	static float maxZoom;

	static Zengine::Camera* uiCamera;

	std::vector<Zengine::Image*> testImgs;
public:
	MainScene();
	~MainScene();

	virtual void update();
	virtual void init();
};
