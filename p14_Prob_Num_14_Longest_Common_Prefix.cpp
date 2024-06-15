class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        // finding length of each string
        vector<int> strLength;
        for (int i=0; i<strs.size(); i++)
            strLength.push_back(strs[i].length());

        int mini=*min_element(strLength.begin(), strLength.end());  // loop will be run till min of the vector

        string ans="";

        int index=0;
        while (index<mini)
        {
            char curr=strs[0][index];

            // checking for the character in other strings of the vector
            for(int i=1; i<strs.size(); i++)
                if (strs[i][index]!=curr)
                    return ans;

            ans+=curr;
            index++;
        }

        return ans;
    }
};
// time complexity: O(n^2)
// space complexity: O(n)