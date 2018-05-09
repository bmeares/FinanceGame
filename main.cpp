#include "includes.h"

using namespace std;

int main() {

  Menu menu;
  Canvas canvas;
  ofstream write;
  ifstream read;

//  saveFile.open("inventory.save");

  bool running = menu.startGame();
  do{
    Player::readSave(read);
    running = canvas.info();
    cin.ignore();


    Canvas::clearScreen();


  } while (running);

  saveFile.close();

  return 0;
}
