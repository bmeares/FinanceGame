#include "Player.h"

int Player::balance = 100;
string Player::choice = "";
vector<Good> Player::inventory = {};

Player::Player(){}
Player::~Player(){}


bool Player::yesOrNo(){
  if(choice == "y" || choice == "Yes" || choice == "yes" || choice == "Y"
  || choice == "YES" || choice == "1" || choice == "YASS")
    return true;
  else
    return false;
}

void Player::addGood(Good& good){
  inventory.push_back(good);
}

void Player::removeGood(int num){
  inventory.erase(inventory.begin() + num);
}


int Player::getBalance(){return balance;}

vector<Good> Player::getInventory(){return inventory;}


string Player::getChoice(){return choice;}
void Player::setChoice(){cin >> choice;}
