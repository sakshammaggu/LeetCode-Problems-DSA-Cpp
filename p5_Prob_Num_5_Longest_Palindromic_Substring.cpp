class Solution {
private:
    string getPalindrome(int left, int right, string &s)
    {
        // going left and right most from the curr centre of the palindrome
        while (left>=0 && right<s.length() && (s[left]==s[right]))
        {
            left-=1;
            right+=1;
        }

        return s.substr(left+1, right-left-1);
    }
public:
    string longestPalindrome(string s) 
    {
        if (s.length()<=1)
            return s;

        string ans=s.substr(0, 1); 
        int maxLen=1;

        for (int i=0; i<s.length(); i++)
        {
            string oddPalindrome=getPalindrome(i, i, s);    // getting odd length palindrome
            string evenPalindrome=getPalindrome(i, i+1, s); // getting even length palindrome

            // updating string and length
            if (oddPalindrome.length()>maxLen)
            {
                ans=oddPalindrome;
                maxLen=oddPalindrome.length();
            }
            
            // updating string and length
            if (evenPalindrome.length()>maxLen)
            {
                ans=evenPalindrome;
                maxLen=evenPalindrome.length();
            }
        }

        return ans;
    }
};
// time complexity: O(n^2)
// space complexity: O(1)