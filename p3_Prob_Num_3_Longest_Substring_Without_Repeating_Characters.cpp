class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int maxLength=0;
        unordered_set<int> us;
        int i=0, j=0;   // slinding window approach

        while (j<s.length())
        {
            // if curr char is not found in set
            if (us.find(s[j])==us.end())
            {
                us.insert(s[j]);    // inserting it
                maxLength=max(maxLength, static_cast<int>(us.size()));  // updating length
                j++;
            }

            // if curr char is found in set
            else
            {
                // erasing curr char and going forward
                us.erase(s[i]);
                i++;
            }
        }

        return maxLength;
    }
};
// time complexity: O(n)
// space complexity: O(1)