  ================================================  Hamming Distance ==================================================
  Hamming distance is : at how much positions two numbers x and y has different bits in binary repersentation.
  
  time complexity : O(no. of set bits in number)
  
  
  =====================================================================================
  Solution :
         find Xor of number
          find total set bit in numbers.
          
 code: 
 
             class Solution {
             
            public:
                    int countSetBit(int n){
                     int count=0;
                        while(n>0){
                              n= n & (n-1);                // 2
                                count++;
                         }
                        return count;
                    }
                
                
                  int hammingDistance(int x, int y) {
                     return countSetBit(x^y);             //1
                  }
                
                
            };
