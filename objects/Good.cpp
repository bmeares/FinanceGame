#include "Good.h"
#include "Player.h"

void Good::buy(){

  cout << "Would you like to buy " << name << " for $" << value <<
  "? (Y/N) ";

  Player::setChoice();

  if(Player::yesOrNo()){
    Player::setBalance(Player::getBalance() - value);
    Player::addGood(*this);
  }
}

void Good::sell(int num){
  cout << "Would you like to sell " << name << " for $" << value <<
  "? (Y/N) ";

  Player::setChoice();

  if(Player::yesOrNo()){
    Player::setBalance(Player::getBalance() + value);
    Player::removeGood(num);
  }
}

void Good::improve(double e){
  value = ((value * e));
}

std::ostream& operator << (ostream& out, Good& good) {
  out << "   Item:     " << good.name << "\n"
      << "   Value:    $" << good.value << "\n";
      if(good.service.getName() != "")
        out << "     (Investment: " << good.service.getName() << ")" << endl;
  return out;
 // return out << "   Item:     " << good.name << "\n"
 //            << "   Value:    $" << good.value << "\n";
}

Good::Good(){}
Good::Good(int val, string name){
  this->value = val;
  this->name = name;
}
Good::~Good(){}
