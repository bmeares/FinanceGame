#include "Canvas.h"

using namespace std;

void Canvas::clearScreen(){
  cout << "\033c";
}

bool Canvas::info(){
  clearScreen();
  stats();
  cout << "\n\n\nInventory (i)   |   ";
  cout << "Auction (a)   |   Sell (s)   |   Invest (n)   |   Quit (q)" << endl;

  bool running = true;
  Player::setChoice();
  if(Player::getChoice() == "a" || Player::getChoice() == "A"){
    Auction::auction();
  }
  if(Player::getChoice() == "i" || Player::getChoice() == "I"){
    clearScreen();
    showInventory();
    cout << "\n\nPress any key to return." << endl;
    cin.ignore();
  }
  if(Player::getChoice() == "s" || Player::getChoice() == "S"){
    Sell::sell();
  }
  if(Player::getChoice() == "n" || Player::getChoice() == "N"){
    Invest::invest();
  }
  if(Player::getChoice() == "q" || Player::getChoice() == "q"){
    running = false;
  }
  return running;
}

void Canvas::showInventory(){
  cout << "Here is your inventory: " << endl;
  cout << "\n";
  for(uint i = 0; i < Player::getInventory().size(); i++){
    cout << i + 1 << ".\n" << Player::getInventory().at(i) << endl;
  }
}

void Canvas::stats(){
  cout << "\n Balance: $" << Player::getBalance() << endl;
  cout << " Items: " << Player::getInventory().size() << endl;
}

Canvas::Canvas(){}
Canvas::~Canvas(){}
