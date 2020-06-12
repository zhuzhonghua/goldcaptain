#include "goldcaptain.h"
#include "mainscene.h"

int main(int argc, char** argv)
{
  GoldCaptain gc;
  gc.init();
  gc.switchScene(new MainScene());
  gc.run();
  
  return 0;
}
