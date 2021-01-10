========================================================== Find all Disappear number in array ===========================

Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]


============================================
Approach : 
======== >>>>>>>>>>>

 without space {
         To solve this problem we will iterate through the input array and mark elements as negative using nums[nums[i] -1] = -nums[nums[i]-1].
e.g. We have an array [4, 3, 2, 7, 8, 2, 3, 1]
We will start iterating this array. Below will be the array elements after processing each element:
when i = 0 , than nums[i] is 4 , so array will become [4, 3, 2, -7, 8, 2, 3, 1]
when i = 1 , than nums[i] is 3 , so array will become [4, 3, -2, -7, 8, 2, 3, 1]
when i = 2 , than nums[i] is 2 , so array will become [4, -3, -2, -7, 8, 2, 3, 1]
when i = 3 , than nums[i] is 7 , so array will become [4, -3, -2, -7, 8, 2, -3, 1]
when i = 4 , than nums[i] is 8 , so array will become [4, -3, -2, -7, 8, 2, -3,-1]
when i = 5 , than nums[i] is 2 , so array will become [4, -3, -2, -7, 8, 2, -3,-1]
when i = 6 , than nums[i] is 3 , so array will become [4, -3, -2, -7, 8, 2, -3,-1]
when i = 7 , than nums[i] is 1 , so array will become [-4, -3, -2, -7, 8, 2, -3,-1]
In this way all the numbers that we have seen will be marked as negative. In the second iteration, if a value is not marked as negative, 
it means we have never seen that index before, so just add it to the return list.
  }
============================================

Solution :  using extra space

         class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++)
            temp.push_back(i+1);
        
        for(int i=0;i<nums.size();i++)
          if(nums[i]==temp[nums[i]-1])
             temp[nums[i]-1]=0;
         for(int i=0;i<nums.size();i++)     
              temp.erase(remove (temp.begin(), temp.end(), 0), temp.end());
        
        return temp;
    }
};

==========================================================
solution : in place array


           class Solution {
            public:
                vector<int> findDisappearedNumbers(vector<int>& nums) {
                    vector<int> temp;


                    for(int i=0;i<nums.size();i++){
                        int index=abs(nums[i])-1;           // take abs() , because we need positive index not negative
                        if(nums[index]>0)                      //also check for only those elements which are not marked negative yet
                         nums[index]= -nums[index];
                    }  
                     for(int i=0;i<nums.size();i++)     
                          if(nums[i]>0)
                              temp.push_back(i+1);

                    return temp; 
                }
            };
 
