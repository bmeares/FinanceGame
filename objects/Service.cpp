#include "Service.h"
#include "Player.h"

std::ostream& operator << (ostream& out, const Service& service) {
 return out << "   Service:     " << service.name << "\n   "
            << "Cost:    $" << service.cost << endl;
}

Service::Service(){}
Service::Service(int cost, string name){
  this->cost = cost;
  this->name = name;
}
Service::~Service(){}
