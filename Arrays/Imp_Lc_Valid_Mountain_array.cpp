========================================= Valid Mountain Array (combination of ascending + decending array ) ==========================================

IMPORTANT CORNER CASES :  array will return true if it will be combination of both ascending + decending only;

Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

 

Example 1:

Input: arr = [2,1]
Output: false
Example 2:

Input: arr = [3,5,5]
Output: false
Example 3:

Input: arr = [0,3,2,1]
Output: true
 

Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 104

=============================================================================================
Time complexity : O(n)
Space complexity : O(1)

Solution:
      class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return  false;
        
        int i;
        for(i=1;i<arr.size();i++){
            if(arr[i-1]<arr[i])
                continue;
            else if(arr[i-1]==arr[i])
                 return false;
            else
                break;            //whenever we find a change (i.e first time we get smaller value than prev, means from here our array's value must reduced) so return index.
        }
   //corner cases :     
         if(i==arr.size() && arr.size() != 3 )
             return false;   //if whole array traverse still no change : ascending only
         if(i==1)            // if upper loop terminate at first means : array is in decending position only
             return false;
    //Once corner cases handled , look for decrement array only.    
        for(int j=i;j<arr.size();j++){
            if(arr[j-1]<=arr[j])   //if prev found to be smaller than or equal to next one means , its hike or no change in value. so return false , else true 
                return false;
        }  
        return true;
    }
};
