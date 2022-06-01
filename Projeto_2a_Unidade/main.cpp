#include "sculptor.h"
#include <iostream>
using namespace std;
int main()
{
  Sculptor casa(80, 80, 80);
  casa.setColor(0.0, 1.0, 0.0, 1.0);
  casa.putBox(0, 50, 0, 1, 0, 50);
  casa.setColor(0.58, 0.29, 0, 1);
  casa.putBox(10, 40, 1, 15, 10, 40);
  casa.cutBox(11, 39, 1, 15, 11, 39);

  casa.setColor(0.86, 0.44, 0.35, 1);
  for (int i = 13; i < 30; i++)
  {
    casa.putBox(7, 43, i, i + 1, i - 5, i - 4);
  }

  for (int i = 13; i < 30; i++)
  {
    casa.putBox(7, 43, i, i + 1, 54 - i, 55 - i);
  }
  casa.setColor(0.58, 0.29, 0, 1);
  casa.putBox(10, 11, 10, 30, 10, 40);
  casa.putBox(39, 40, 10, 30, 10, 40);

  for (int k = 10; k < 24; k++)
  {
    for (int i = 16; i < 30; i++)
    {
      casa.cutVoxel(10, i + (k - 10), k);
      casa.cutVoxel(39, i + (k - 10), k);
    }
  }

  for (int i = 0; i < 14; i++)
  {
    for (int k = 26; k < 40; k++)
    {
      casa.cutVoxel(10, 29 - i, k + i);
      casa.cutVoxel(39, 29 - i, k + i);
    }
  }

  // colocar putBox e alterar a cor para madeira de porta
  // casa.setColor(0.87, 0.72, 0.52, 1);
  casa.cutBox(10, 11, 1, 8, 23, 27);

  // Vidro
  casa.setColor(0.65, 0.80, 0.84, 0.1);
  casa.putBox(10, 11, 6, 11, 13, 20);
  casa.putBox(10, 11, 6, 11, 30, 37);

  casa.writeOFF("casa.off");
}