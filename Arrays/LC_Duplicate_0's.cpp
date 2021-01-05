==================================== Duplicate each occurrence of 0 in array ====================================================

Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

 

Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]
 

Note:

1 <= arr.length <= 10000
0 <= arr[i] <= 9

=====================================================================================
Time complexity : O (n*n) 
space complexity : O(1)

Solution:
====================
class Solution {
public:
    void insert(vector<int>& arr,int pos){
        int i;
        for(i=arr.size()-1;i>pos;i--){
            arr[i]=arr[i-1];
        }
        arr[i]=0;
        
        
    }
    void duplicateZeros(vector<int>& arr) {
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)
            {
                insert(arr,i+1);
                i++;
            }
        }
    }
};
