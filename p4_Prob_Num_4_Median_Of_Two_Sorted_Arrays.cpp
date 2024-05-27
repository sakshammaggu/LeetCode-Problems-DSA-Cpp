#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int i,j;
        double median;
        for (int i=0; i<nums1.size(); i++)
        {
            merge.push_back(nums1[i]);
        }
        for (int j=0; j<nums2.size(); j++)
        {
            merge.push_back(nums2[j]);
        }
        sort(merge.begin(), merge.end());
        int n=merge.size();
        return n%2?merge[n/2]:(merge[n/2-1]+merge[n/2])/2.0;
    }
};