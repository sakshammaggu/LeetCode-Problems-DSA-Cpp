class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());

        int n=nums.size();

        if (n==3)
            return nums[0]+nums[1]+nums[2];
            
        int closestSum=nums[0]+nums[1]+nums[2];

        for (int i=0; i<n-2; i++)
        {
            int j=i+1, k=n-1;

            while (j<k)
            {
                int newSum=nums[i]+nums[j]+nums[k];

                if (newSum==target)
                    return newSum;

                else
                {
                    // rest logic is 3sum ques. in addition to, the nearest sum is our ans
                    if (abs(closestSum-target)>=abs(newSum-target))
                        closestSum=newSum;

                    if (newSum<target)
                        j++;
                    else
                        k--;
                }
            }
        }

        return closestSum;
    }
};
// time complexity: O(n^2)
// space complexity: O(1)