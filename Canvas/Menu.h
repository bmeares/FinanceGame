#ifndef MENU_H
#define MENU_H 1

#include <iostream>
#include <string>
#include "Canvas.h"
#include <assert.h>

using namespace std;

class Menu{
  private:

  public:

    bool startGame();
    static void printTable();
    static string centered(string, int);

    Menu();
    ~Menu();
};
#endif
