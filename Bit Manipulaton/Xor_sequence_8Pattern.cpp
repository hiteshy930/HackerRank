============================================================== Xor Sequence ++++++++++++++++++++++++++++++++++++++++++++++
An array,A, is defined as follows:
A[0]=0
A[x]=(A[x-1] ^ x) for x>0 , where ^   is the symbol for XOR

You will be given a left and right index l,r. You must determine the XOR sum of the segment of 
A as A[l] ^ A[l+1] ^ ....^ A[r-1] ^ A[r]

For example, A=[0,1,3,0,4,1,7,0,8]. The segment from to sums to
1 ^ 3 ^ 0 ^ 4 = 6.

Print the answer to each question.

Function Description

Complete the xorSequence function in the editor below. It should return the integer value calculated.

xorSequence has the following parameter(s):

    l: the lower index of the range to sum
    r: the higher index of the range to sum

Input Format

The first line contains an integer q
, the number of questions.
Each of the next q lines contains two space-separated integers,l[i] and r[i]

, the inclusive left and right indexes of the segment to query.

Constraints
q<=10^5
l[i]<=r[i]<=10^15

Output Format

On a new line for each test case, print the XOR-Sum of A's elements in the inclusive range between indices l[i] and

r[i].

Sample Input 0

3
2 4
2 8
5 9

Sample Output 0

7
9
15


Time Complexity :   O(1)
                   if :  O(n) ==> not work with large inputs ... but we can do that 
                                  with check divisible by 4 also.
                                  
                                  and traverse array from l to r.






=================================================================================================
/*
         +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                To find out Xor of array :
                
                  1. From 1 to n ==> Use pattern 4.
                  2. if range is given from (l,r) ==> use pattern 4 ( when a continuous a[i] values given)
                      for eg :       Input: L = 4, R = 8
                                      Output: 8
                                      4 ^ 5 ^ 6 ^ 7 ^ 8 = 8

                                      Input: L = 3, R = 7
                                      Output: 3 
                  3. if range (L,r) given and no sequence in array elements. (As per this question) ==> use pattern of 8 only.
                  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

     if we xor from [L -> R] => pattern of 4 is okey i.e for 1 to n continuous number sequence only.
     But here our array[i] has different sequence number. if we observe carefully then at 0th index value has difference of 8 with value at 8th index, and at few places its same at both index. so we choose 8 here: 
		 
		 Some important info to understand pattern:
		  1. Here n= 0,1,2,3,4,5,6,7
			2. y => Xor of "TILL" 0 to nth element in array.We have to take xor of array elements
			3. Find xor of nth elements of array[i] where n  is remainder possible after dividing by 8
			4. In-array --> n is Index of array
			
			
        rem=n%8 |  y | respective value of y
         _______|____|_______________________
            0    0    n
            1    1    n      // 
            2    2    2    // . 
            3    2    2     // 
            4    6    n+2
            5    7    n+2      // 
            6    0    0           //
            7    0    0            // 
            ________________________
            8    8    n
            9    9    n
            10    2    2
            11    2    2
            12    14    n+2
            13    15    n+2
            14    0    0
            15    0    0
            ________________________
            16    16    n
            17    17    n
            18    2    2
            19    2    2
            20    22    n+2
            21    23    n+2
            22    0    0
            23    0    0
            ________________________
            24    24    n

                                         
                             ▼                   ▼ 
Arr[i]:     |0|1|3|0|4|1|7|0|8|1|11|0|12|1|15|0|16|     ....so..on

index(n): 0  1   2  3  4  5  6  7  8   9  10 11 12 13 14 15 16

*/

============================================================================================
//function to find out xor of a[i]th index elements.

 long find_array_value_of_index(long x){
     long long a = x % 8;
    if(a == 0 || a == 1) return x;
    if(a == 2 || a == 3) return 2;
    if(a == 4 || a == 5) return x+2;
    if(a == 6 || a == 7) return 0;
    return 0;
 }
 
// Complete the xorSequence function below.
long xorSequence(long l, long r) {
        // if(l%4==0 && r%4==0) return l^r;
        
        
            return ( find_array_value_of_index(l-1) ^ find_array_value_of_index(r) );  // Here idea is given below
                
}


=============================================================================
Idea of doing Xor at last is :                       
                                                          L            R
                                                          ▼            ▼
                 suppose we have an array  : a= [ a b b f fs s sr w w we r er ]  
                                                  |--------|
                                                   Xor (1 to L-1)
                                                  |---------------------|
                                                           xor(1 to r)
                                                  
                 and we given  L and R , so to find xor (L,R)
                 we can find as follows :
                 ========================================================
                           Xor (L,R) = Xor(L-1) ^ Xor(R)
                 =========================================================          
