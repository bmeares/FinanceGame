#ifndef CANVAS_H
#define CANVAS_H 1

#include <iostream>
#include <string>
//#include "../objects/Player.h"
//#include "../auction.h"
// #include "../sell.h"
// #include "../invest.h"
#include "../includes.h"
#include <iostream>
#include <vector>

using namespace std;

class Canvas{
  private:

  public:
    static void clearScreen();
    bool info();

    static void showInventory();
    static int inventoryChoice();
    static int serviceChoice();
    static void stats();

    Canvas();
    ~Canvas();
};
#endif
