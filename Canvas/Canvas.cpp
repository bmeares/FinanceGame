#include "Canvas.h"

using namespace std;

void Canvas::clearScreen(){
  cout << "\033c";
}

bool Canvas::info(){
  clearScreen();
  stats();
  Menu::printTable();

  bool running = true;
  Player::setChoice();
  if(Player::getChoice() == "a" || Player::getChoice() == "A"){
    Auction::auction();
  }
  if(Player::getChoice() == "i" || Player::getChoice() == "I"){
    clearScreen();
    stats();
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
  if(lost()){
    lostMessage();
    running = false;
  }
  if(won()){
    wonMessage();
    running = false;
  }
  return running;
}
void Canvas::lostMessage(){
  clearScreen();
  cout << "\n You're out of money and have no assets!\n\n";
  cout << " Thanks for playing! Press any key to quit." << endl;
  //cin.ignore();
}

void Canvas::wonMessage(){
  clearScreen();
  cout << "\n Congrats! You own all of the wealth on Earth!\n\n";
  cout << " Thanks for playing! Press any key to quit." << endl;
  cin.ignore();
}

int Canvas::inventoryChoice(){
  showInventory();
  int choice = 0;
  cout << "  Choice: ";
  cin >> choice;

  if(quit())
    return 0;

  else if(static_cast<unsigned int>(choice) > Player::getInventory().size()){
    bool runagain = false;
    do{
      cout << "Pick an item onscreen." << endl;
      cin >> choice;

      if(static_cast<unsigned int>(choice) > Player::getInventory().size())
        runagain = true;

      else if(quit())
        return 0;

      else // if passes everything, just return choice
        runagain = false;
    } while(runagain);
  }

  return choice;
}

int Canvas::serviceChoice(){
  int choice = 0;
  cout << "  Choice: ";
  cin >> choice;

  if(quit())
    return 0;

  else if(choice > 5){
    bool runagain = false;
    do{
      cout << "Pick an item onscreen." << endl;
      cin >> choice;

      if(choice > 5)
        runagain = true;

      else if(quit()) // if cin sees a char, set choice to 0
        return 0;

      else // if passes everything, just return choice
        runagain = false;

    } while(runagain);
  }
  return choice;
}


void Canvas::showInventory(){
  cout << "\n INVENTORY: \n" << endl;
  if(Player::hasInventory()){
    for(unsigned int i = 0; i < Player::getInventory().size(); i++){
      cout << i + 1 << ".\n" << Player::getInventory().at(i) << endl;
    }
  }
  else{
    cout << "\n No items in inventory.\n\n" << endl;
  }
}


void Canvas::stats(){

  for(int i = 0; i < 19; i++){
    cout << " . ";
  }
  cout << "\n";
  stringstream balanceString;
  stringstream itemsString;
  // if(Player::numDigits() % 2 == 0 || Player::getBalance() == 0)
  //   balanceString << "Balance: $" << FormatWithCommas(Player::getBalance()) << " ";
  // else
  balanceString << "Balance: $" << FormatWithCommas(Player::getBalance());

  itemsString << " Items: [" << Player::getInventory().size() << " / 6]";

  cout << Menu::centered(balanceString.str(), 35);




  cout << Menu::centered("Press 'h'", 17) << "\n";
  cout << Menu::centered(itemsString.str(), 35);
  cout << Menu::centered("  to go home.", 17) << "\n";

  for(int i = 0; i < 19; i++){
    cout << " ' ";
  }
  cout << "\n";
}

string Canvas::FormatWithCommas(uint64_t val){
    stringstream ss;
    ss.imbue(std::locale(""));
    ss << fixed << val;
    return ss.str();
}

uint64_t Canvas::randomLL(uint64_t min, uint64_t max) //range : [min, max)
{
   static bool first = true;
   if (first)
   {
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

bool Canvas::lost(){
  bool lost = false;
  if(Player::getBalance() == 0 && Player::getInventory().size() == 0)
    lost = true;
  return lost;
}

bool Canvas::quit(){
  bool quit = false;
  if(cin.fail()){
    cout << "quit: test" << endl;
    cin.clear();
    quit = true;
  }
  return quit;
}

bool Canvas::won(){
  bool won = false;
  if(Player::getBalance() > 10000000000000000) //
    won = true;
  return won;
}

Canvas::Canvas(){}
Canvas::~Canvas(){}
