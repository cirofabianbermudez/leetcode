#include <iostream>
#include <string>
#include <stack>

using namespace std;

//void printstack(stack<char> s) {
//  for (size_t i = 0; i < s.size(); i++) {
//    if ( !s.empty() ) {
//      cout << s.top() << " -- " << endl;
//      s.top();
//    }
//
//  }
//}

bool isValid(string s) {
  stack<char> tracker;
  int offset;
  int n = s.size();

  for (int i = 0; i < n; i++) {

    cout << s[i] << " ";

    if( (s[i] == '(')  || (s[i] == '{')  || (s[i] == '[') )  {
      tracker.push( s[i] );
    }

    if( (s[i] == ')')  || (s[i] == '}')  || (s[i] == ']') )  {
      offset = ( s[i] == ')' ) ? 1 : 2;
      if (tracker.top() == s[i] - offset) {
        tracker.pop();
      }
    }


    cout << "stack: " << tracker.top() << endl;
  }
    //if( (s[i] == '(')  || (s[i] == '{')  || (s[i] == '[') )  {
    // if( (s[i] == ')')  || (s[i] == '}')  || (s[i] == '}') )  {
  /*
    if( (s[i] == '(')  || (s[i] == '{')  || (s[i] == '[') )  {
      offset = ( s[i] == '(' ) ? 1 : 2;
      tracker.push( s[i] + offset );
      //cout << tracker.top() << endl;
      continue;
    } 

    printstack(tracker);

    if( (s[i] == ')')  || (s[i] == '}')  || (s[i] == '}') )  {
      if (tracker.top() == s[i] ) {
        cout << "here" << endl;
        tracker.pop();
      }
    }

  }

  */
  return tracker.empty();
}

int main(int argc, char** arvv) {
  cout << isValid("([{}])") << endl;
  return 0;
}

