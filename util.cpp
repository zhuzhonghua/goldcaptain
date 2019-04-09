#include "stdafx.h"
#include "util.h"


SimpleRand::SimpleRand()
  :_rndDouble(0, 1)
{
}

SimpleRand::SimpleRand(int min, int max)
  :_rndInt(min, max)
{
}

double SimpleRand::getDoubleRnd()
{
  return _rndDouble(_randEngine);
}

int SimpleRand::getIntRnd()
{
  return _rndInt(_randEngine);
}
