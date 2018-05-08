#include "Player.h"

unsigned long long Player::balance = 10000000;
string Player::choice = "";
vector<Good> Player::inventory = {};
vector<Service> Player::services = {};

Player::Player(){}
Player::~Player(){}


bool Player::yesOrNo(){
  if(choice == "y" || choice == "Yes" || choice == "yes" || choice == "Y"
  || choice == "YES" || choice == "1" || choice == "YASS")
    return true;
  else{
    choice = "";
    return false;
  }
}

bool Player::hasInventory(){
  bool hasInventory;
   if(inventory.size() > 0)
     hasInventory = true;
  else
    hasInventory = false;
  return hasInventory;
}

int Player::numDigits(){
  int numDigits = 0;
  unsigned long long tempBalance = balance;
  while(tempBalance > 0){
    tempBalance /= 10;
    numDigits++;
  }
  return numDigits;
}

int Player::firstThreeBalance(){
  int num = numDigits();
  unsigned long long tempBalance = balance;
  for (int i = 0; i < num - 3; i++){
    tempBalance /= 10;
  }
  return tempBalance;
}

void Player::addGood(Good& good){
  inventory.push_back(good);
}

void Player::removeGood(int num){
  inventory.erase(inventory.begin() + num);
}

void Player::addService(Service& service){
  services.push_back(service);
}

vector<Good>& Player::getInventory(){return inventory;}


string Player::getChoice(){return choice;}
void Player::setChoice(){cin >> choice;}
