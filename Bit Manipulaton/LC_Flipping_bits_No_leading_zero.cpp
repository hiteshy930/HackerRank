=================================================== Flipping Bits of  a number =============

Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

 

Constraints:

    The given integer num is guaranteed to fit within the range of a 32-bit signed integer.
    num >= 1
    You could assume no leading zero bit in the integer’s binary representation.
    This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/




========================================================================================
Approach : 
          we know- "agar (bits of number) , (all bits 1) ka xor kare to , digits flip ho jayegi"
 But,    here we have bits till the number , not having more leading bits to number  in left side
         
         So, Now "ab signed integer ki range 2147483648 (0x7FFFFFFF) iska xor ni kar skte number ke sath."
         ab hume pta karna padega, har number ke liye ki kitni bits 111...111 hogi , number ke according
         So, hume pta hai :  agar hum  numbr ka log base 2 krenge or 1 add krenge to , hume us number me kitne total bits hai pta chal jayega , 
         to hum utne bits ki value nikal lenge or jo value ayegi uska xor apne number ke sath kar denge.
         
         for eg :  n=5 ==> 1 0 1 
                   total bits in 5 = floor(log2(5))+1 = 3
                   second_number = find power of 2 , total number of bit times. --> pow( 2, total bits) 
                   xor of num and second_number
                   
       ========================================================================================================
       
       class Solution {
public:
    
    int findComplement(int num) {
        if(num==0) return 1;
        int bit_position= log2(num)+1;
        int num2=pow(2,bit_position)-1;
       return (num ^ num2); 
    }
};
       
       
