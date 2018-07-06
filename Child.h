#include <list>
#include <string>
#include <iostream>

class Child {
 private:
  std::string name;
  std::list<std::string> gifts;

 public:
  Child() {
    name = "no_name";
  }

  Child(std::string name) {
    this->name = name;
  }

  void addGift(std::string gift) {
    if (gift != "")
      gifts.push_back(gift);
  }

  void display() {
    // display name
    std::cout << name << " ";
    // display gifts
    std::list<std::string>::iterator it;
    for(it = gifts.begin(); it != gifts.end(); it++) {
      std::cout << ' ' << *it;
    }
    // newline
    std::cout << std::endl;
  }
};
