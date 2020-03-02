#pragma once

#include "scene.h"

class Camera;
class CaptainScene : public Zengine::Scene{
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

	static Camera* uiCamera;
public:
	CaptainScene();
	~CaptainScene();

	virtual void init();
};
