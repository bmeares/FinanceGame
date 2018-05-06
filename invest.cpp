#include "invest.h"

using namespace std;

Service Invest::service1, Invest::service2, Invest::service3, Invest::service4,
  Invest::service5, Invest::service6;
vector<Service> Invest::SERVICES = {service1, service2, service2, service3,
  service4, service5, service6};

void Invest::invest(){
  Canvas::clearScreen();
  Canvas::stats();

  srand(time(NULL));
  int randMax = 6;
  int seed;

  int maxPrice = Player::getBalance();

  cout << "\n   AUCTION:\n\n";
  cout << "   Choose an investment from below to purchase.\n" << endl;
  for(int i = 0; i < 6; i++){
    seed = rand() % randMax;
    SERVICES.at(i).setValue(rand() % maxPrice);
    SERVICES.at(i).setName(Auction::itemName(seed));
    cout << " " << i + 1 << ".\n" << SERVICES.at(i) << endl;
  }
  int choice;
  cout << "  Choice: ";
  cin >> choice;
  cout << "\n";
  SERVICES.at(choice - 1).buy();
}

// string Auction::itemName(int num){
//   string first, second, last;
//   int randMax = 19;
//   vector<string> firsts, seconds, lasts;
//   stringstream fullName;
//
//
//     firsts =  {"LG", "Apple", "Google", "Samsung", "Sony", "Nokia", "Motorola",
//               "2018", "2009", "1996", "1965", "1999", "2015", "2001",
//               "Speedy", "Lightning", "Super Duper", "Ultra", "Mega",
//               "All-natural"};
//     seconds = {"G5", "iPhone", "Pixel", "Galaxy", "Xperia", "3310", "Droid",
//               "BMW", "Ford", "Toyota", "Chevrolet", "GMC", "Tesla", "Nissan",
//               "Turbo", "Nintendo", "Lightsaber", "Time machine", "Toothpaste",
//               "Hershey's"};
//     lasts =   {"Pro", "Compact", "S9", "XL", "C", "X", "mini",
//               "X5", "F150", "Tacoma", "C10", "Sonoma", "Model S", "Altima",
//               "For Elders", "For Women", "For Men", "For Children",
//               "Uncensored Edition", "Xtreme Editiion"};
//
//
//   first = firsts.at(rand() % randMax);
//   second = seconds.at(rand() % randMax);
//   last = lasts.at(rand() % randMax);
//
//    fullName << first << " " << second << " " << last;
//    return fullName.str();
// }
