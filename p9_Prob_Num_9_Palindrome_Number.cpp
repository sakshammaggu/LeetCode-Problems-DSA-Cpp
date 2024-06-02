#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) 
    {
        long int digit, rev=0, n;
        if ((x<0))
        {
            return false;
        }
        else if ((x==0))
        {
            return true;
        }
        else
        {
            n=x;
            while (x!=0)
            {
                digit=x%10;
                rev=(rev*10)+digit;
                x=x/10;
            }
            if (n==rev)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};