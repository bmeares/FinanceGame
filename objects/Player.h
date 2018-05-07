#ifndef PLAYER_H
#define PLAYER_H 1

#include <iostream>
#include <string>
#include "Good.h"
#include <vector>
#include "Service.h"
// #include "../includes.h"

using namespace std;

class Player{
  private:
    static int balance;
    static string choice;
    static vector<Good> inventory;
    static vector<Service> services;

  public:

    static int getBalance();
    static void setBalance(int num){balance = num;}
    static string getChoice();
    static void setChoice();
    static vector<Good>& getInventory();

    static bool yesOrNo();
    static bool hasInventory();

    static void addGood(Good&);
    static void removeGood(int);

    static void addService(Service&);

    Player();
    ~Player();
};
#endif
