=========================================== Power of 4 ====================================================

Hint: 
      only  power (2, even) ==> (power of 4 )                             :::::::::::::: EVEN powers of 2 only ::::::::::::::::::::::::
      
====================

Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

 

Example 1:

Input: n = 16
Output: true

Example 2:

Input: n = 5
Output: false

Example 3:

Input: n = 1
Output: true

 

Constraints:

    -231 <= n <= 231 - 1
    
    Time Complexity : O(1)
    Space Complexity : O(1)
===========================================================================================================
Solution :

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0||n==2) return false;
        if(n==1) return true;
        int powerof2=(int)log2(n);
        if(powerof2 % 2 == 0)
             if((n &(n-1))==0) return true;
        return false;
    }
};
