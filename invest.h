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
    static Service service1, service2, service3, service4,
    service5, service6;
    static vector<Service> SERVICES;

  public:
    static void invest();
    //static string serviceName(int seed);
  };

#endif
