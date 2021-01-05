======================================= Given a binary array, find the maximum number of consecutive 1s in this array. =================

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
==============================================================================================
Approach : Traverse array and count++ until , 0 comes. when 0 comes make count to be 0 again

TimeComplexity : O(n)
Space COmplexity: O(1)

Solution: 
 class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count=0;
        int max=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) count++;
            else count=0;
            max=(max<count)?count:max;
        }
        return max;
    }
};
