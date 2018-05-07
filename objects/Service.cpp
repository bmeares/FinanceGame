#include "Service.h"
#include "Player.h"

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
 return out << "   Service:     " << service.name << "\n"
            << "   Cost:        $" << service.cost << endl;
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
