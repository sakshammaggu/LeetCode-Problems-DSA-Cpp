#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int index;
        for (int i=0; i<haystack.size(); i++)
        {
            index=haystack.find(needle);
            return index;
            break;
        }
        return -1;
    }
};