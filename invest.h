#ifndef INVEST_H
#define INVEST_H 1

#include "auction.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "includes.h"
#include <sstream>
//#include "objects/Service.h"
//#include "objects/Good.h"

using namespace std;

class Invest{
  private:
    static unsigned long long amount;
    static double rate;
    static double effect;

  public:
    static void invest();
    static void apply();


  };

#endif
