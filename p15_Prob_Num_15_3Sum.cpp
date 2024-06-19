class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort (nums.begin(), nums.end());

        int n=nums.size();

        vector<vector<int>> ans;
        set<vector<int>> s; // to remove duplicates

        int i=0;
        while (i<n-2)
        {
            // fixing one pointer and appying two sum by changing to other two pointers
            int j=i+1, k=n-1;

            while (j<k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }

                else if (nums[i] + nums[j] + nums[k] < 0)
                    j++;
                
                else if (nums[i] + nums[j] + nums[k] > 0)
                    k--;
            }

            i++;
        }

        for (auto x:s)
            ans.push_back(x);

        return ans;
    }
};
// time complexity: O(n^2)
// space complexity: O(n)