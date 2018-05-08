#include "invest.h"

using namespace std;

unsigned long long Invest::amount = 0;
double Invest::rate = 0.001;
double Invest::effect = 0.0;

void Invest::invest(){
  Canvas::clearScreen();
  Canvas::stats();
  cout << "\n   INVEST:\n\n";
  cout << "   Rate: 0.1% per $\n" << endl;

  if(Player::hasInventory()){

    cout << "Enter how much money you want to invest."
    << "\n(Note: You cannot invest more than an item is worth)" << endl;
    cout << "  $";
    cin >> amount;
    if(!Canvas::quit()){
      if(amount > 0 && amount <= Player::getBalance()){
        apply();
        Player::subtractBalance(amount);
      }
      else{
        cout << "\n   You can't spend money you don't have.\n\n" << endl;
        cout << "   Press any key to return." << endl;
        cin.ignore();
      }
    }
    else{
      cout << "\n   You need an inventory to invest.\n\n" << endl;
      cout << "   Press any key to return." << endl;
      cin.ignore();
    }
  }
}

void Invest::apply(){
  Canvas::clearScreen();
  Canvas::stats();

  cout << "\n   INVEST:\n\n";
  cout << "   Which item do you want to invest in?\n\n" << endl;

  int choice = Canvas::inventoryChoice();

  if(choice != 0){
    unsigned long long val = Player::getInventory().at(choice - 1).getValue();
    if(amount > val){
      cout << "\n   Cannot invest more than the item is worth.\n\n" << endl;
      cout << "   Press any key to return." << endl;
      cin.ignore();
      Player::addBalance(amount);
    }
    // Check if good does not have an improvement already
    else if (!Good::hasImprovement(choice - 1)){
      effect = (amount) * rate;

      val = (val * effect) + val;

      Player::getInventory().at(choice - 1).setValue(val);
    }
    else{ //if good has improvement
      cout << "\nCannot invest in an item that has already been improved." << endl;
      cout << "Press any key to return." << endl;
      cin.ignore();
    }

  }
//  Player::getInventory().at(choice - 1).getValue() *= effect;
  // Player::getInventory().at(choice - 1).improve(srv.getEffect());

}

// string Invest::serviceName(int num){
//   string name;
//   int randMax = 5;
//   vector<string> NAMES;
//   double effect;
//
//   int vectorPosition = rand() % randMax;
//
//     // enum NAMES_VALS {Fixing = 1, Repairing, Cleaning, Washing, Painting, Restoring,
//     //                 Refurbishing, Refining, Upgrading
//     //                 };
//
//     NAMES =  {"Repair", "Refurbish", "Restore", "Refine", "Upgrading"
//               };
//     effect = static_cast<double>(vectorPosition + 1) * 0.1;
//     cout << "serviceName effect: " << effect << endl;
//
//
//   name = NAMES.at(vectorPosition);
//
//   return name;
// }
