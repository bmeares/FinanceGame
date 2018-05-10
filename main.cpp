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

  Canvas::clearScreen();
  cout << "\n Would you like to save your game? (Y/N) ";
  Player::setChoice();
  if(Player::yesOrNo()){
    saveFile.open("inventory.save", fstream::in | fstream::out | std::ios_base::app);
    Player::writeSave(saveFile);
    saveFile.close();
  }

  Canvas::clearScreen();

  return 0;
}
