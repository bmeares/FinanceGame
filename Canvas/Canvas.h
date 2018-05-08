#ifndef CANVAS_H
#define CANVAS_H 1

#include <iostream>
#include <string>
#include <sstream>
//#include "../objects/Player.h"
//#include "../auction.h"
// #include "../sell.h"
// #include "../invest.h"
#include "../includes.h"
#include <locale>
#include <iomanip>
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
    static string FormatWithCommas(uint64_t);
    static uint64_t randomLL(uint64_t, uint64_t);
    static bool lost();
    static bool quit();
    static bool won();
    static void lostMessage();
    static void wonMessage();
    // static int x();
    // static int y();

    Canvas();
    ~Canvas();
};
#endif
