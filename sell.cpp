#include "sell.h"

using namespace std;

void Sell::sell(){
  Canvas::clearScreen();
  Canvas::stats();

  cout << "\n   SELL:\n\n";

  if(Player::hasInventory()){

    cout << "   Choose an item from below to sell, or press n to return.\n"
    << endl;

    // Canvas::showInventory();
    // int choice = 0;
    // cout << "  Choice: ";
    // cin >> choice;
    // cout << "\n";

    int choice = Canvas::inventoryChoice();

    if(choice != 0)
      Player::getInventory().at(choice - 1).sell(choice - 1);
    cin.clear();
  }
  else{
    cout << "   You need an inventory to sell items.\n\n" << endl;
    cout << "   Press any key to return." << endl;
    cin.ignore();
  }
}
