#include "includes.h"

using namespace std;

int main() {

  Menu menu;
  Canvas canvas;

  bool running = menu.startGame();
  do{
    running = canvas.info();
    cin.ignore();


    Canvas::clearScreen();


  } while (running);

  return 0;
}
