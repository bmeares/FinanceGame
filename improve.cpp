#include "improve.h"

using namespace std;

Service Improve::service1, Improve::service2, Improve::service3,
  Improve::service4, Improve::service5, Improve::service6;
vector<Service> Improve::SERVICES = {service1, service2, service2, service3,
  service4, service5, service6};

void Improve::improve(){
  Canvas::clearScreen();
  Canvas::stats();
  cout << "\n   IMPROVEMENTS:\n\n";

  if(Player::hasInventory()){
    srand(time(NULL));

    int maxPrice = Player::getBalance();
    vector<string> NAMES =  {"Repair", "Refurbish", "Restore",
                            "Refine", "Upgrade"};
    double effect;

    cout << "   Choose an improvement from below to purchase.\n" << endl;

    for(int i = 0; i < 5; i++){
      effect = ((static_cast<double>(i + 0.5) * 0.1) / 1.3) + 1;
      SERVICES.at(i).setCost(rand() % maxPrice);
      SERVICES.at(i).setName(NAMES.at(i));
      SERVICES.at(i).setEffect(effect);
      cout << " " << i + 1 << ".\n" << SERVICES.at(i) << endl;
    }


    int choice = Canvas::serviceChoice();

    Service srv;

    if(choice != 0){
      srv = SERVICES.at(choice - 1);
      srv.buy();
    }

    if(Player::yesOrNo())
      applyService(srv);
  }
  else{
    cout << "   You need an inventory to buy improvements.\n\n" << endl;
    cout << "   Press any key to return." << endl;
    cin.ignore();
  }
}
void Improve::applyService(Service& srv){
  Canvas::clearScreen();
  Canvas::stats();

  cout << "\n   IMPROVEMENTS:\n\n";
  cout << "   Which item do you want to improve?\n\n" << endl;

  int choice = Canvas::inventoryChoice();

  if (Player::getInventory().at(choice - 1).getService().getName() == ""){
    Player::getInventory().at(choice - 1).setService(srv);
    Player::getInventory().at(choice - 1).improve(srv.getEffect());
  }
  else{
    cout << "Cannot improve an item more than once." << endl;
    cout << "Press any key to return." << endl;
    cin.ignore();
  }

}
