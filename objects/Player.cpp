#include "Player.h"
#include "../Canvas/Canvas.h"

uint64_t Player::balance = 100;
string Player::choice = "";
vector<Good> Player::inventory = {};
vector<Service> Player::services = {};

Player::Player(){}
Player::~Player(){}


bool Player::yesOrNo(){
  if(choice == "y" || choice == "Yes" || choice == "yes" || choice == "Y"
  || choice == "YES" || choice == "1" || choice == "YASS"){
//    cout << "TEMP true yes" << endl;
//    cin.ignore();
    return true;
  }
  else{
    choice = "";
//    cout << "TEMP false yes" << endl;
    cin.ignore();
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
  uint64_t tempBalance = balance;
  while(tempBalance > 0){
    tempBalance /= 10;
    numDigits++;
  }
  return numDigits;
}

int Player::firstThreeBalance(){
  int num = numDigits();
  uint64_t tempBalance = balance;
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

void Player::readSave(fstream& saveFile){

  string name;
  string buffer;
  uint64_t value;
  int runint = 1;
  vector<Good> inventory;
  bool load = false;
  //string choice;

  getline(saveFile, name);

//  cout << "TEMP: name" << name << endl;
//   cin.ignore();
  //cout << "TEMP name = " << name << endl;
  //cin.ignore();
//  cout << "TEMP name = " << name << endl;
  if(name != "" || name == "0"){
    Canvas::clearScreen();
    cout << "Save detected. Load save? (Y/N) ";
    cin.clear();
//    cin.ignore();
    cin >> choice;
//    cout << "TEMP: choice: " << choice << endl;
    load = yesOrNo();
  }

  if(load){

    if(name != "" || name == "0"){
      saveFile.clear();
      saveFile.seekg(0, ios::beg);
      do {
        getline(saveFile, name);
        saveFile >> value;
        getline(saveFile, buffer);
        saveFile >> runint;
        getline(saveFile, buffer);
        Good good(value, name);

        addGood(good);

        //cout << "TEMP: runint = " << runint << endl;
      } while(runint);
    }
    else{
      saveFile.clear();
      saveFile.seekg(0, ios::beg);
      saveFile >> runint;
    }
      //getline(saveFile, buffer);
      saveFile >> balance;
  }
}

void Player::writeSave(fstream& saveFile){

  for(uint i = 1; i < inventory.size(); i++){
    saveFile << inventory.at(i).getName();
    saveFile << "\n";
    saveFile << inventory.at(i).getValue();
    saveFile << "\n";
    saveFile << 1;
    saveFile << "\n";
  }
  if(inventory.size() > 0){
    saveFile << inventory.back().getName();
    saveFile << "\n";
    saveFile << inventory.back().getValue();
    saveFile << "\n";
    //saveFile << 0;
    //saveFile << "\n";
    // cout << "TEMP INSIDE WRITE" << endl;
    // cout << "TEMP "
    // cin.ignore();
  }

  saveFile << 0;
  saveFile << "\n";
  saveFile << balance;
}

void Player::clearSave(){
  ofstream deleteFile;
  deleteFile.open("inventory.save", std::ofstream::out | std::ofstream::trunc);
  deleteFile.close();
}


vector<Good>& Player::getInventory(){return inventory;}


string Player::getChoice(){return choice;}
void Player::setChoice(){cin >> choice;}
