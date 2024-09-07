#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase( unique( nums.begin(), nums.end() ), nums.end() );
        return nums.size();
    }
};
// time complexity: O(n)
// space complexity: O(1)