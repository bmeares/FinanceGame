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

std::ostream& operator << (ostream& out, const Good& good) {
 return out << "   Item:     " << good.name << "\n   "
            << "Value:    $" << good.value << endl;
}

Good::Good(){}
Good::Good(int val, string name){
  this->value = val;
  this->name = name;
}
Good::~Good(){}
