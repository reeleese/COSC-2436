/*
  Author: Lee Reese
  Lab: 3
*/

#include <iostream>
#include <string>
#include <stack>

int evaluate(std::stack<char>&);

int main() {
  std::cout << "Postifx expression evaluator.\nLeave Expression empty to quit."
            << std::endl;
  bool done = false;
  while (!done) {
    // Get expression
    std::cout << "Expression: ";
    std::string expr;
    getline(std::cin, expr);
    if (expr.empty())
      done = true;

    // Fill stack
    std::stack<char> post;
    for (char& x : expr)
      post.push(x);

    // Output result
    std::cout << "Result: " << evaluate(post) << std::endl;
  } //end while

  return 0;
} // end main

int evaluate(std::stack<char>& post) {
  // Base case: enpty stack
  if (post.empty())
    return 0;
  // Base case: top is an integer
  char x = post.top(); post.pop();
  if (47 < x && x < 58)
    return x - 48;

  // Inductive case(s): top is an operator
  if (x == '+')
    return evaluate(post) + evaluate(post);
  if (x == '-')
    return evaluate(post) - evaluate(post);
  if (x == '*')
    return evaluate(post) * evaluate(post);
  if (x == '/')
    return evaluate(post) / evaluate(post);
  else
    return 0;
}
