#include "Service.h"
#include "Player.h"
#include "../Canvas/Canvas.h"

void Service::buy(){

  cout << "Would you like to buy " << name << " for $" << cost <<
  "? (Y/N) ";

  Player::setChoice();

  if(Player::yesOrNo()){
    Player::setBalance(Player::getBalance() - cost);
    Player::addService(*this);
  }
}



std::ostream& operator << (ostream& out, const Service& service) {
 return out << "   Service:" << setw(15) << service.name << "\n"
            << "   Cost:" << setw(16) << "$"
            << Canvas::FormatWithCommas(service.cost) << "\n"
            << "   Improvement:" << setw(10) << setprecision(2)
            << Canvas::FormatWithCommas((service.effect * 100) - 100)
            << "%" << endl;
}

Service& Service::operator = (const Service& rhs){
  this->cost = rhs.cost;
  this->name = rhs.name;
  this->effect = rhs.effect;
  return *this;
}

Service::Service(){}
Service::Service(int c, string n, double e) : cost(c),
  name(n), effect(e){}
Service::~Service(){}
