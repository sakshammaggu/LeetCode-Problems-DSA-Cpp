class Solution {
public:
    string convert(string s, int numRows) 
    {
        /*
            --zig zag order--

            0->numRows-1
            numRow-1->0
            0->numRows-1
            numRow-1->0
            ...
            ...
        */

        if (numRows<=1)
            return s;

        vector<string> zigZag(numRows, ""); // vector to store the string in zig zag order

        int j=0, direction=-1;

        for (int i=0; i<s.length(); i++)
        {
            // chaning direction
            if (j==0 || j==numRows-1)
                direction*=-1;

            zigZag[j]+=s[i];    // pushing char

            // left to right
            if (direction==1)
                j++;

            // right to left
            else
                j--;
        }

        string ans="";
        for (int i=0; i<zigZag.size(); i++)
        {
            ans+=zigZag[i];
        }

        return ans;
    }
};
// time complexity: O(n)
// space complexity: O(n)