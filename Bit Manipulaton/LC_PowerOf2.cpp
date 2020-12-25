=============================================== Power of 2 ( N could be negative) ====================================
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1

Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16

Example 3:

Input: n = 3
Output: false

Example 4:

Input: n = 4
Output: true

Example 5:

Input: n = 5
Output: false

 

Constraints:

    -231 <= n <= 231 - 1

==============================================================
Appraoch : if N<=0 then it will be false .... (PLEASE NOTE  ::::::::::::::::::::  Negative power is not Power of 2)
           using brain kerningam 
   Time Complexity : O(1)
   Space Complexity : O(1)
   
   +======================================================
   
Solution: 
            class Solution {
public:
    
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        if(n==1) return true;
       
        if((n & (n-1))==0) return true;
        return false;
    }
};
