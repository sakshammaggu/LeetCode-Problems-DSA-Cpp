class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int area=INT_MIN;

        // two pointer approach
        int i=0, j=height.size()-1;

        while (i<j)
        {
            int l=(j-i);
            int b=min(height[i], height[j]);
            int newArea=l*b;

            area=max(area, newArea);

            // if both curr height are equal 
            if (height[i]==height[j])
            {
                i++;
                j--;
            }

            // if first height is less than second height then incrementing first pointer to maximize the product
            else if (height[i]<height[j])
                i++;

            // if second height is less than first height then incrementing second pointer to maximize the product
            else
                j--;
        }

        return area;
    }
};
// time complexity: O(n)
// space complexity: O(1)