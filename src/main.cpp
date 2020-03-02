#include "goldcaptain.h"
#include "captainscene.h"

int main(int argc, char** argv)
{
	GoldCaptain gd;
	gd.init();

	gd.switchScene(new CaptainScene());
	gd.run();
	
	gd.finish();
  return 0;
}
