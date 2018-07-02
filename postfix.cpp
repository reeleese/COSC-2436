/*
Ch. 6, Programming Problems 5, pg. 219

Name the program postfix.cpp. Make sure the following requirements are met. 

    - Program must compile and run.
    - Make sure to implement the algorithm 
      (Evaluating Postfix Expressions 6.3.1) 
      as a function. (not as part of main)
    - Note while C does have the atoi function 
      it may be easier to simply subtract the 
      char '0' from the char digit.

Remember to upload all files before submitting.

    postfix.cpp

*/
#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>

int evaluate(std::stack<char>&);

int main() {
  // Get expression
  std::cout << "Expression to evaluate: ";
  std::string expr;
  getline(std::cin, expr);

  // Fill stack
  std::stack<char> post;
  for (char& x : expr)
    post.push(x);
  
  std::cout << "Result: " << evaluate(post) << std::endl;

  

  
  return 0;
} // end main

int evaluate(std::stack<char>& post) {
  char x = post.top(); post.pop();
  if (47 < x && x < 58) // if x is an integer
    return x - 48;
  if (x == '+')
    return evaluate(post) + evaluate(post);
  else if (x == '-')
    return evaluate(post) - evaluate(post);
  else if (x == '*')
    return evaluate(post) * evaluate(post);
  else if (x == '/')
    return evaluate(post) / evaluate(post);
}
