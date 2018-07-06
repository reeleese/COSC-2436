/*
Ch. 8, Programming Problems 2, pg. 264

Name the program giftlist.cpp. Make sure the following requirements are met. 

    - Program must compile and run.
    - All inputs are strings.
    - Only do the nice list, not the naughty list.
    - User will enter names until empty string denoting no more names.
    - Each name will be followed by one or more gifts.
    - After names entered display contents of the name list and each gift list.

Remember to upload all files before submitting.

    giftlist.cpp

Example Run

name for nice list: greg
add gifts for greg
gift: legos
gift: cookie
gift:
name for nice list: bob
add gifts for bob
gift: monopoly
gift: candy cane
gift:
name for nice list: alice
add gifts for alice
gift: dress
gift:
name for nice list: tim
add gifts for tim
gift: superman comic
gift: car
gift: pony
gift:
name for nice list:
The list contains
greg  legos cookie
bob  monopoly candy cane
alice  dress
tim  superman comic car pony
*/
/*
  Author: Lee Reese
  Lab: 4
  Files: Child.h, giftlist.cpp
*/
#include <iostream>
#include "Child.h"
#include <list>

int main() {
  std::string name;
  std::string gift;
  std::list<Child> kids;

  bool done = false;
  while (!done) {
    // Get name
    std::cout << "name for nice list: ";
    std::getline(std::cin, name);

    // If there is a name
    if (name != "") {
      // Create child with name
      Child kid = Child(name);

      // Get the gifts
      std::cout << "add gifts for " << name <<std::endl;
      bool done_gift = false;
      while (!done_gift) {
        std::cout << "gift: ";
        std::getline(std::cin, gift);

        // Note: addGift does not take empty strings
        kid.addGift(gift);
        if (gift == "")
          done_gift = true;
      } // end while "gift"

      // Record the kid, complete with gifts
      kids.push_back(kid);
    } // end if "name"

    // If no name, done
    else
      done = true;
  } // end while "name"

  // Display all kids and their gifts
  if (!kids.empty()) {
    std::cout << "The list contains";
    std::list<Child>::iterator it;
    for (it = kids.begin(); it != kids.end(); it++)
      it->display();
  }
  
  return 0;
}
