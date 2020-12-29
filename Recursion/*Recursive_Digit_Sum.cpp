=================================================== Recursive Sum of digits  ===========================================================
We define super digit of an integer x using the following rules:

Given an integer, we need to find the super digit of the integer.

    If x has only 1 digit, then its super digit is x.
Otherwise, the super digit of x is equal to the super digit of the sum of the digits of x.

For example, the super digit of n=9875 

will be calculated as:

	super_digit(9875)   	9+8+7+5 = 29 
	super_digit(29) 	2 + 9 = 11
	super_digit(11)		1 + 1 = 2
	super_digit(2)		= 2  

Example
n=9875 ,k=4
The number p is created by concatenating the string n,k times so
    superDigit(p) = superDigit(9875987598759875)
                  5+7+8+9+5+7+8+9+5+7+8+9+5+7+8+9 = 116
    superDigit(p) = superDigit(116)
                  1+1+6 = 8
    superDigit(p) = superDigit(8)



========================================================================
Time Complexity : O(length of string)
Space COmplexity : O(1)




================================================================================

Iterative approach :
                FInd sum of digit(n)
                Fint full_string_sum = sod(n)*k;
                check if (f_s_s %9 ==0 ) return 9;
                else return (f_s_s%9);
                
       code:  
            long long superDigitInteger(string n){
              long long sum=0;
               for(int i=0;i<n.length();i++)
                 sum+=n[i]-48;         //To get char value we need to minus 48, which is ascii value of 0.
               return sum;
            }
          
          // Complete the superDigit function below.
          long long superDigit(string n, int k) {

              long long  total_sum = k * superDigitInteger(n);
              
                 if(total_sum%9==0) return 9;
                 else 
                 return total_sum%9; 
          }
==========================================================================================================
Recursive Approach :

                typedef long long int int64;

            // Complete the superDigit function below.
            int64 superDigit(string n, int k) {
                int64 fullSum = 0;

                for (auto i : n) {
                    fullSum += (i - 48);
                }

                fullSum *= k;
                if (fullSum > 10)
                    return superDigit(to_string(fullSum), 1);

                return fullSum;
            }
