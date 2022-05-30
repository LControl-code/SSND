#include <iostream>
using namespace std;

int main() {
  int num1, num2;
  char op;

  cout << "Enter your first number: ";
  cin >> num1;

  cout << "Enter the operator: ";
  cin >> op;

  cout << "Enter your second number: ";
  cin >> num2;

  int result;
  switch (op) {
  case '+':
    result = num1 + num2;
    break;
  case '-':
    result = num1 - num2;
    break;
  case '*':
    result = num1 * num2;
    break;
  case '/':
    result = num1 / num2;
    break;
  default:
    cout << "Invalid operator";
    return 0;
  }

  cout << "Result: " << result;
  return 0;
}