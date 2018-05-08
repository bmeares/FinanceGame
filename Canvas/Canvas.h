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
    static string FormatWithCommas(unsigned long long);
    static unsigned long long randomLL(unsigned long long, unsigned long long);
    static bool lost();
    static bool quit();
    static void lostMessage();
    // static int x();
    // static int y();

    Canvas();
    ~Canvas();
};
#endif
