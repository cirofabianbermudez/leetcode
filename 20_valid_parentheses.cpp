#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s) {
  stack<char> tracker;
  int offset;
  int n = s.size();

  for (int i = 0; i < n; i++) {
    if( ( (s[i] == ')')  || (s[i] == '}')  || (s[i] == ']') ) && !tracker.empty() ) {
      offset = ( s[i] == ')' ) ? 1 : 2;
      if (tracker.top() == s[i] - offset) {
        tracker.pop();
        continue;
      }
    }
    tracker.push( s[i] );
  }
  return tracker.empty();
}

int main(int argc, char** arvv) {
  //cout << isValid("([{}])") << endl;
  //cout << isValid("(]") << endl;
  cout << isValid("(){}}{") << endl;
  return 0;
}

