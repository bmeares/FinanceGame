#include "sell.h"

using namespace std;

void Sell::sell(){
  Canvas::clearScreen();
  Canvas::stats();

  cout << "\n   SELL:\n\n";
  cout << "   Choose an item from below to sell.\n" << endl;

  Canvas::showInventory();
  int choice;
  cout << "  Choice: ";
  cin >> choice;
  cout << "\n";

  Player::getInventory().at(choice - 1).sell(choice - 1);

  // Player::setBalance(Player::getBalance() +
  //   Player::getInventory().at(choice - 1).getValue());
  // Player::removeGood(choice - 1);

}
