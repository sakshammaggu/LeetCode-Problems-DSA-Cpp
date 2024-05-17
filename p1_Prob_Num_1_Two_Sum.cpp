#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> res;
        for (int i=0; i<nums.size(); i++)
        {
            for (int j=(i+1); j<nums.size(); j++)
            {
                if ((nums.size()>=2)&&(nums.size()<=10000)&&(nums[i]>=-1000000000)&&(nums[i]<=1000000000)&&(target>=-1000000000)&&(target<=1000000000))
                {
                    if ((nums[i]+nums[j])==target)
                    {
                        res.emplace_back(i);
                        res.emplace_back(j);
                    }                
                }
            }
        }
        return res;
    }
};
// time complexity: O(n^2)
// space complexity: O(1) 

// ------------------------------------------------------------------------------------

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) 
        {
            int complement = target - nums[i];

            // finding complement in map and returning corresponding index
            if (numMap.find(complement)!=numMap.end()) 
            {
                return {numMap[complement], i};
            }

            numMap[nums[i]] = i;
        }

        return {}; // No solution found
    }
};
// time complexity: O(n *log(n))
// space complexity: O(n)