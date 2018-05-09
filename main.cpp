#include "includes.h"

using namespace std;

int main() {

  Menu menu;
  Canvas canvas;
  ofstream saveFile;

  saveFile.open("inventory.save");

  bool running = menu.startGame();
  do{
    running = canvas.info();
    cin.ignore();


    Canvas::clearScreen();


  } while (running);

  saveFile.close();

  return 0;
}
