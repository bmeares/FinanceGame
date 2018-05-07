#ifndef IMPROVE_H
#define IMPROVE_H 1

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

class Improve{
  private:
    static Service service1, service2, service3, service4,
    service5, service6;
    static vector<Service> SERVICES;

  public:
    static void improve();
    static string serviceName(int seed);
    static void applyService(Service&);
  };

#endif
