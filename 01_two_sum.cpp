#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Brute Force
vector<int> twoSum1(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                return {i,j};
            }
        }
    }
    return {};
}

// Optimize version
vector<int> twoSum2(vector<int>& nums, int target) {

    unordered_map<int, int> hash_map;
    int comp;
    int n = nums.size();

    for (int idx = 0; idx < n; idx++) {
      comp = target - nums[idx];
      if ( hash_map.contains(comp) ) {
        //return vector<int>{nums[idx], idx};
        return {idx, hash_map[comp] };
      } 
      hash_map[nums[idx]] = idx;
      //hash_map.insert( {nums[idx], idx} );
    }
    return {};
}


int main(int argc, char** arvv) {
  vector<int> test = {2,7,11,15};
  vector<int> result;
  result = twoSum2(test, 9);
  cout << result[0] << ", " << result[1] << endl;
  return 0;
}
