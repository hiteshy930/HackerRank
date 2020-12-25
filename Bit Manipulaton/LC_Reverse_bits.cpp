====================================================== Reverse bits of a number ========================================================
Reverse bits of a given 32 bits unsigned integer.

Note:

    Note that in some languages such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
    In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.

Follow up:

If this function is called many times, how would you optimize it?

 

Example 1:

Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

Example 2:

Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.

 

Constraints:

    The input must be a binary string of length 32




====================================================================================================
Approach :  1. 2-pointer approach --> flip bits which are different in values(using xor).
            2. Using Leftshift and right shift operator



===========================================================================
Solution :  

           ==============================self implemented================>>>>>>>>>>> 
           Time Complexity : O(no. of bits) //for large inputs n ,loop will run 32 times only, also pow() can calculate in O(1) time, flipping is also in constant time
           Space complexity : O(1)
             
             class Solution {
                public:
                    uint32_t flip_bit(uint32_t n,uint32_t bit){
                       return  n = (n ^ (1<<bit));     // flipping single bit at one time using xor        <--- N I C E -- L  O G I C
                    }
                    uint32_t reverseBits(uint32_t n) { 

                        for(int i=31,j=0;i>j;i--,j++){                 // 2-pointer approach traverse bits of number from (left and right) towards center
                            uint32_t x= n& (1<<j);                       // finding bit value at particular bit from left
                            uint32_t p=(uint32_t)pow(2,i);              
                            uint32_t y=n & p;                           // from right finding bit value
                          //  cout<<"i: "<<i<<" j: "<<j<<" x: "<<x<<" y: "<<y<<endl;
                            if((x!=y)&&(x==0||y==0))                                        //only flip bits when bits are different
                            {                                                                //second condition is to avoid situation when both x and y > 1,
                                n=flip_bit(n,j);                                           //so either x or y should be zero to flip bits
                                n=flip_bit(n,i);
                            }

                        }
                        return n;
                    }
                };
                
    =================================================================================
     +++++++++Better Solution ++++++++++++++++++++++++++++++
    hint:   1.) find LSB bit of n using (n & 1), do it for all bits
                  --> store it into a new variable let say "reverse" where rev = (rev<<1) | (n & 1);       <------( left shift reverse variable )
            2.)  do right shift of number, to get next bit of number.      
       explain::::::::::::::::::::::::::::::::::::::::::::::     
           number : 00000..........000101
                     ------------------------> Check first bit is set or not to store into reverse.
                     
          reverse : 00000 ...........0000 | either 0 or 1
          
          update number : Right shift one by one to get next bit
     
             class Solution {
            public int reverseBits(int n) {
                int reverse = 0;
                for (int i = 0; i < 32; i++) {
                    reverse = (reverse << 1) | (n & 1);
                    n = n >> 1;
                }
                return reverse;
            }
        }
        
        =====================Output if n=5 then:
n: 5 rev: 0 i: 0      after -> rev: 1 n: 2
n: 2 rev: 1 i: 1      after -> rev: 2 n: 1
n: 1 rev: 2 i: 2      after -> rev: 5 n: 0
n: 0 rev: 5 i: 3      after -> rev: 10 n: 0
n: 0 rev: 10 i: 4      after -> rev: 20 n: 0
n: 0 rev: 20 i: 5      after -> rev: 40 n: 0
n: 0 rev: 40 i: 6      after -> rev: 80 n: 0
n: 0 rev: 80 i: 7      after -> rev: 160 n: 0
n: 0 rev: 160 i: 8      after -> rev: 320 n: 0
n: 0 rev: 320 i: 9      after -> rev: 640 n: 0
n: 0 rev: 640 i: 10      after -> rev: 1280 n: 0
n: 0 rev: 1280 i: 11      after -> rev: 2560 n: 0
n: 0 rev: 2560 i: 12      after -> rev: 5120 n: 0
n: 0 rev: 5120 i: 13      after -> rev: 10240 n: 0
n: 0 rev: 10240 i: 14      after -> rev: 20480 n: 0
n: 0 rev: 20480 i: 15      after -> rev: 40960 n: 0
n: 0 rev: 40960 i: 16      after -> rev: 81920 n: 0
n: 0 rev: 81920 i: 17      after -> rev: 163840 n: 0
n: 0 rev: 163840 i: 18      after -> rev: 327680 n: 0
n: 0 rev: 327680 i: 19      after -> rev: 655360 n: 0
n: 0 rev: 655360 i: 20      after -> rev: 1310720 n: 0
n: 0 rev: 1310720 i: 21      after -> rev: 2621440 n: 0
n: 0 rev: 2621440 i: 22      after -> rev: 5242880 n: 0
n: 0 rev: 5242880 i: 23      after -> rev: 10485760 n: 0
n: 0 rev: 10485760 i: 24      after -> rev: 20971520 n: 0
n: 0 rev: 20971520 i: 25      after -> rev: 41943040 n: 0
n: 0 rev: 41943040 i: 26      after -> rev: 83886080 n: 0
n: 0 rev: 83886080 i: 27      after -> rev: 167772160 n: 0
n: 0 rev: 167772160 i: 28      after -> rev: 335544320 n: 0
n: 0 rev: 335544320 i: 29      after -> rev: 671088640 n: 0
n: 0 rev: 671088640 i: 30      after -> rev: 1342177280 n: 0
n: 0 rev: 1342177280 i: 31      after -> rev: 2684354560 n: 0

Output
  2684354560 (10100000000000000000000000000000)
Expected
  2684354560
