#include "invest.h"

using namespace std;

unsigned long long Invest::amount = 0;
double Invest::rate = 0.01;
double Invest::effect = 0.0;

void Invest::invest(){
  Canvas::clearScreen();
  Canvas::stats();
  cout << "\n   INVEST:\n\n";
  cout << "   Rate: 1% per $\n" << endl;

  if(Player::hasInventory()){

    cout << "Enter how much money you want to invest: ";
    cout << "$";
    cin >> amount;

    if(amount > 0 && amount <= Player::getBalance()){
      apply();
      Player::subtractBalance(amount);
    }
    else{
      cout << "\n   You can't spend money you don't have." << endl;
      cout << "   Press any key to return." << endl;
      cin.ignore();
    }
  }
  else{
    cout << "   You need an inventory to invest.\n\n" << endl;
    cout << "   Press any key to return." << endl;
    cin.ignore();
  }
}

void Invest::apply(){
  Canvas::clearScreen();
  Canvas::stats();

  cout << "\n   INVEST:\n\n";
  cout << "   Which item do you want to invest in?\n\n" << endl;

  int choice = Canvas::inventoryChoice();

  effect = static_cast<double>(amount) * rate;
  int val = Player::getInventory().at(choice - 1).getValue();

  val = (val * effect) + val;

  Player::getInventory().at(choice - 1).setValue(val);

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
