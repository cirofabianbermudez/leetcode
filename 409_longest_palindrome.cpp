#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


int longestPalindrome(string s) {

    unordered_map<char, int> tracker;
    int result = 0;
    int n = s.size();
    int odd_flag = 0;

    for (int i = 0; i < n; i++) {
        if ( !tracker.contains( s[i] ) ) { 
            tracker[s[i]] = 1;
        } else {
          tracker[s[i]]++;
        }
    }

    //cout << "diff = " << diff_letters << endl;
    for (const auto &pair : tracker) {
      //cout << "key: " << pair.first << ", value: " << pair.second;
      if (pair.second % 2 == 0) {
        result += pair.second;
      } else {
        odd_flag = 1;
        result += pair.second - 1;
      }
      //cout << " partial: " << result << endl;

    }

    return result + odd_flag;
}

int main(int argc, char** arvv) {
  //string test = "abccccdd";
  string test = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";
  cout << longestPalindrome(test) << endl;
  return 0;
}



