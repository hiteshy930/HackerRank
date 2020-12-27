======================================================== Binary Number with Alternating Bits ========================================
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

 

Example 1:

Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101

Example 2:

Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.

Example 3:

Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.

Example 4:

Input: n = 10
Output: true
Explanation: The binary representation of 10 is: 1010.

Example 5:

Input: n = 3
Output: false

 

Constraints:

    1 <= n <= 2^31 - 1

=============================================================================================
Approach : find out LSB value compare it with next position value after right shift number by 1.

             n    101
             &    001
             ----------------
          temp =  001
            ------------------
            
            Now Right shift number to get 2nd bit of number
          n>>1   010
          &        1
          -------------------
        curr =   000
          -------------------
          check temp== curr if yes return false; else continue
           Now Right shift number to get 3rd bit of number
          n>>1   001
          &      001
          -------------------
                 001
          -------------------
          
          Now Right shift number to get 4th bit of number
          n>>1   000
         So, loop ends her because number became 0 here. So output will be true.
         
         Time Complexity : O(1)
         Space complexity : O(1)
         ==============================================================================
          bool hasAlternatingBits(int n) {
       while(n>0){
			   int temp=n&1;                  //find out first bit value from right
             n=n>>1;                             //right shift number by 1
           if(temp== (n&1)) return false;      //if prev result is same as shifted number's result. 
		                                         // it means 2 adjacent bits are same , so returned false.
         
       }
        return true;
    }
            
