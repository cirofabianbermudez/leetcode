#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
  int n = s.size();
  int res = 0;

  unordered_map<char, int> m = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                                {'C', 100}, {'D', 500}, {'M', 1000}};

  for (int i = 0; i < n; i++) {
    if ((i < n - 1) && (m[s[i]] < m[s[i + 1]])) {
      res -= m[s[i]];
    } else {
      res += m[s[i]];
    }
    cout << s[i] << " " << res << endl;
  }
  return res;
}

/*
       if (s[i] == "I") { val = 1;   }
  else if (s[i] == "V") { val = 5;   }
  else if (s[i] == "X") { val = 10;  }
  else if (s[i] == "L") { val = 50;  }
  else if (s[i] == "C") { val = 100; }
  else if (s[i] == "D") { val = 500; }
  else if (s[i] == "M") { val = 1000;}
*/

int main(int argc, char** arvv) {
  cout << romanToInt("XIV") << endl;
  return 0;
}
