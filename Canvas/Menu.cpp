#include "Menu.h"

bool Menu::startGame(){
  Canvas::clearScreen();
  cout << "Welcome to Money Game. Press any key to begin" << endl;
  cin.ignore();
  return true;
}

Menu::Menu(){}
Menu::~Menu(){}
