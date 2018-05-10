#include "includes.h"

using namespace std;

int main() {

  Menu menu;
  Canvas canvas;
  fstream saveFile;

  saveFile.open("inventory.save", fstream::in | fstream::out | std::ios_base::app);

//  Player::writeSave(saveFile);
  Player::readSave(saveFile);
  saveFile.close();



  bool running = menu.startGame();
  do{

    running = canvas.info();
    cin.ignore();


    Canvas::clearScreen();


  } while (running);

  Player::clearSave();

  saveFile.open("inventory.save", fstream::in | fstream::out | std::ios_base::app);
  Player::writeSave(saveFile);

  saveFile.close();

  return 0;
}
