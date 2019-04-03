#pragma once
#include "util.h"

class ImageUtil{
public:
  static SDL_Texture* createSolid(SDL_Renderer* render, int width, int height, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};
