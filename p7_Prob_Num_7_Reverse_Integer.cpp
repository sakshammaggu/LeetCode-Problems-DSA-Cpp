#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:
    long int reverse(long int x) {
        long int rev=0, rem;
        if (x>0)
        {
            if (x%10==0)
            {
                x/=10;
                while(x!=0)
                {
                    rem=x%10;
                    rev=(rev*10)+rem;
                    x/=10;
                }
            }
            else
            {
                while(x!=0)
                {
                    rem=x%10;
                    rev=(rev*10)+rem;
                    x/=10;
                }
            }
        }
        else
        {
            long int t=(-1)*x;
            if (t%10==0)
            {
                t/=10;
                while(t!=0)
                {
                    rem=t%10;
                    rev=(rev*10)+rem;
                    t/=10;
                }
                rev=(-1)*rev;
            }
            else
            {
                while(t!=0)
                {
                    rem=t%10;
                    rev=(rev*10)+rem;
                    t/=10;
                }
                rev=(-1)*rev;
            }
        }
        if ((rev<=pow(2,31)-1)&&(rev>=pow(-2, 31)))
        {
            return rev;
        }
        else
        {
            return 0;
        }
    }
};