#include <iostream>

using namespace std;

bool isPalindrome(int x) {
  long int operand = x;
  long int reverse = 0;

  if (x < 0) {
    return false;
  }

  cout << operand << " " << reverse << endl;
  while (operand > 0) {
   reverse = reverse*10 + operand%10;
   operand = operand/10;
   cout << operand << " " << reverse << endl;
  }

  return (reverse == x);
}


int main(int argc, char** arvv) {
  cout << isPalindrome(1221) << endl;
  return 0;
}

