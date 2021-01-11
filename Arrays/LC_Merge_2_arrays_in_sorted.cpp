================================== Merge 2 arrays in sorted order ==================================================


===================================================================
solution: 
    
    Time Complexity : O( nlogn )
    
      class Solution {
        public:
            void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
                if(m==1 && n==0){
                    return;
                }
                 if(m==0 && n==1){
                     nums1[0]=nums2[0];
                    return;
                }
                int temp=0;
                m=n+m;
                for(int i=n;i<m;i++){
                    nums1[i]=nums2[temp++];
                }  
                sort(nums1.begin(),nums1.end());
            }
        };
  ===================================================================
  
  Time Complexity : O( n )
  Space COmplexity : O(1)
  
  Solution :
  
