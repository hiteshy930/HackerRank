========================================== SUM OF ODD LENGTH SUBARRAY ====================================================================

Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

A subarray is a contiguous subsequence of the array.

Return the sum of all odd-length subarrays of arr.

 

Example 1:

Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
Example 2:

Input: arr = [1,2]
Output: 3
Explanation: There are only 2 subarrays of odd length, [1] and [2]. Their sum is 3.
Example 3:

Input: arr = [10,11,12]
Output: 66
 

Constraints:

1 <= arr.length <= 100
1 <= arr[i] <= 1000

==========================================================================================================================================
              [   1,   4,   2,     3,    5  ]
       k=0        ▲
	   i=0          ▲                                     sum =sum +arr[j] =0+1 =1;
	   j=0 	        ▲
				 
			 [   1,   4,   2,     3,    5  ]
     k=0   ▲
		i=1	        ▲                                          //sum = 1 +4 =5 ;
		j=1	        ▲	 
				 
			 [   1,   4,   2,     3,    5  ]
       k=0   ▲
		i=2	              ▲                //sum = 5 +2 =7;
		j=2	              ▲	 	 
		
		    [   1,   4,   2,     3,    5  ]
       k=0   ▲
		i=3             	        ▲               //sum =7+3 =10;
		j=3	                      ▲	
		
		 [   1,   4,   2,     3,    5  ]
       k=0   ▲
		i=4	                        ▲                 //sum+10+5 =15
		j=4	                        ▲	 
		
		// j runs even length times (because array index start with 0 , so if we will find even length subarray then we will get odd length subarray in actual ) above illustration is just for  1 even_position.
		
		//next time we will check for 3 length then 5 then 7 ..so  on depend on length of array size.
		
    
```
 int sumOddLengthSubarrays(vector<int>& arr) {
        
        int sum=0;
        for(int k=0;k<arr.size();k=k+2){
            for(int i=0;i<=(arr.size()-1-k);i++){
           
                  for(int j=i;j<=(i+k);j++){
             
                         sum+=arr[j];
                } 
            }
        
        }
        
        return sum;
        
    }
```
