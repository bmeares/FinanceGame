#include "invest.h"

using namespace std;

Service Invest::service1, Invest::service2, Invest::service3, Invest::service4,
  Invest::service5, Invest::service6;
vector<Service> Invest::SERVICES = {service1, service2, service2, service3,
  service4, service5, service6};

void Invest::invest(){
  Canvas::clearScreen();
  Canvas::stats();

  srand(time(NULL));

  int maxPrice = Player::getBalance();
  vector<string> NAMES =  {"Repair", "Refurbish", "Restore",
                          "Refine", "Upgrade"};
  double effect;

  cout << "\n   INVESTMENTS:\n\n";
  cout << "   Choose an investment from below to purchase.\n" << endl;

  for(int i = 0; i < 5; i++){
    effect = (static_cast<double>(i + 1) * 0.1) + 0.8;
    SERVICES.at(i).setCost(rand() % maxPrice);
    SERVICES.at(i).setName(NAMES.at(i));
    SERVICES.at(i).setEffect(effect);
    cout << " " << i + 1 << ".\n" << SERVICES.at(i) << endl;
  }


  int choice;
  cout << "  Choice: ";
  cin >> choice;
  cout << "\n";
  Service srv = SERVICES.at(choice - 1);

  srv.buy();
  if(Player::yesOrNo())
    applyService(srv);
}

void Invest::applyService(Service& srv){
  Canvas::clearScreen();
  Canvas::stats();

  cout << "\n   INVESTMENTS:\n\n";
  cout << "   Which item do you want to invest in?\n\n" << endl;

  Canvas::showInventory();

  int choice;
  cout << "  Choice: ";
  cin >> choice;
  cout << "\n";

  Player::getInventory().at(choice - 1).setService(srv);
  Player::getInventory().at(choice - 1).improve(srv.getEffect());




//  cin.ignore();
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
