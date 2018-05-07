#include "Canvas.h"

using namespace std;

void Canvas::clearScreen(){
  cout << "\033c";
}

bool Canvas::info(){
  clearScreen();
  stats();
  cout << "\n\n\nInventory (i)   |   ";
  cout << "Auction (a)   |   Sell (s)   |   Improve (m)   |   Invest (n)"
  << "   |   Quit (q)" << endl;

  bool running = true;
  Player::setChoice();
  if(Player::getChoice() == "a" || Player::getChoice() == "A"){
    Auction::auction();
  }
  if(Player::getChoice() == "i" || Player::getChoice() == "I"){
    clearScreen();
    showInventory();
    cout << "\n\nPress any key to return." << endl;
    cin.ignore();
  }
  if(Player::getChoice() == "s" || Player::getChoice() == "S"){
    Sell::sell();
  }
  if(Player::getChoice() == "m" || Player::getChoice() == "M"){
    Improve::improve();
  }
  if(Player::getChoice() == "n" || Player::getChoice() == "N"){
    Invest::invest();
  }
  if(Player::getChoice() == "q" || Player::getChoice() == "Q"){
    running = false;
  }
  return running;
}

int Canvas::inventoryChoice(){
  showInventory();
  int choice = 0;
  cout << "  Choice: ";
  cin >> choice;
  cout << "\n";

  if(static_cast<uint>(choice) > Player::getInventory().size()){
    bool runagain = false;
    do{
      cout << "Pick an item onscreen." << endl;
      cin >> choice;
      if(static_cast<uint>(choice) > Player::getInventory().size())
        runagain = true;
      else {
        runagain = false;
      }
      while(cin.fail()) {
        cout << "Pick an item onscreen" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> choice;
      }
    } while(runagain);
    // choice = 0;
  }

  return choice;
}

int Canvas::serviceChoice(){
  int choice = 0;
  cout << "  Choice: ";
  cin >> choice;
  cout << "\n";

  if(choice > 5){
    bool runagain = false;
    do{
      cout << "Pick an item onscreen." << endl;
      cin >> choice;
      if(choice > 5)
        runagain = true;
      else // if passes everything, just return choice
        runagain = false;
      while(cin.fail()){ // if cin sees a char, set choice to 0
        cout << "test" << endl;
        cin.clear();
        cin.ignore();
        cin.ignore();
        cin.ignore();

        runagain = false;
        choice = 0;
      }

    } while(runagain);
    //choice = 0;
  }

  return choice;
}


void Canvas::showInventory(){
  cout << "\n INVENTORY: \n" << endl;
  if(Player::hasInventory()){
    for(uint i = 0; i < Player::getInventory().size(); i++){
      cout << i + 1 << ".\n" << Player::getInventory().at(i) << endl;
    }
  }
  else{
    cout << "\n No items in inventory.\n\n" << endl;
  }
}

void Canvas::stats(){
  cout << "\n Balance: $" << FormatWithCommas(Player::getBalance()) << endl;
  cout << " Items:   [" << Player::getInventory().size() << " / 6]" << endl;
}

string Canvas::FormatWithCommas(unsigned long long val){
    stringstream ss;
    ss.imbue(std::locale(""));
    ss << fixed << val;
    return ss.str();
}

unsigned long long Canvas::randomLL(unsigned long long min, unsigned long long max) //range : [min, max)
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

Canvas::Canvas(){}
Canvas::~Canvas(){}
