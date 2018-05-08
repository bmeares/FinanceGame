#ifndef AUCTION_H
#define AUCTION_H 1

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "includes.h"
#include <sstream>
#include "objects/Good.h"
#include "Canvas/Canvas.h"

using namespace std;

class Auction{
  private:
    static Good phone, car, bike, game, food, clothing;
    static vector<Good> GOODS;

  public:
    static void auction();
    static void printOptions();
    static string itemName(int seed);
    static uint64_t roundPrice();
  };

#endif
