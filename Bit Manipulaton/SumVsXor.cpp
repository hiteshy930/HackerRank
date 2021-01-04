============================================ Sum vs Xor =====================================================
find value of x which satisfy following conditions:
   0<=x<=n
   n + x = n ^ x
==================================================================   
   Hint : x aesa number hoga jiski bits 0 hogi , vaha pe jaha n ki bits 1 hogi. 
=======================================================================
   Function Description

Complete the sumXor function in the editor below. It should return the number of values determined, as an integer.

sumXor has the following parameter(s):
- n: an integer

Input Format

A single integer  n,
.

Output Format

Print the total number of integers x satisfying the criteria.

Sample Input 0

5

Sample Output 0

2
=============================================================================================================================
Solution:
            1. Find count of '0' in number 
            2. power ( 2 , count )
            
            Explaination :
                          xor simulates binary addition without the carry over to the next digit. 
                          For the zero digits of n you can either add a 1 or 0 without getting a carry which implies
                          ( xor = + )
               for bit value 1: whereas if a digit in n is 1 then the matching digit in x is forced to be 0 on order to avoid carry.
               for bit value 0 :    For each 0 in n in the matching digit in x can either being a 1 or 0 with a total combination count of """"" 2^(num of zero)  """"".
long sumXor(long n) {
        long c = 0;
        while(n){
            c += n%2?0:1;
            n/=2; 
        }
            c=pow(2,c);
        return c;    

}
