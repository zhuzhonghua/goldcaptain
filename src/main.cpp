#include "goldcaptain.h"

int main(int argc, char** argv)
{
	GoldCaptain gd;
	gd.init();

	gd.run();
	
	gd.finish();
  return 0;
}
