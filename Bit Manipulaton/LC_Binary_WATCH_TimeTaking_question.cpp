============================================================ Binary Watch =================================================================

A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.

clock repersentaion : 


____Value  _____  _32_16_8_4_2_1___________
                    ▼  ▼ ▼ ▼ ▼ ▼ 
       hour led :        □ □ □ □
       
     minute led :   □  □ □ □ □ □
__________________________________________

For example, the above binary watch reads "3:25".

Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

=========================================================================================================================================
Approach:
After spending 4-5 hours i got a solution myself. Approach was simple:
CODE IS BIG >>> APPROACH IS EASY >>>>Trust me, anyone can understand it.

		
			class Solution {
			public:
				void hour(vector<string> &ans,int arr[],int num ){
				  if(num==0) return;
					//all led used for hour only  
					  for(int i=0;i<12;i++){
						  if(num==arr[i] && i<=11){
							  string temp=to_string(i)+":00";
							  ans.push_back(temp);
						  }             
					  }
				}
				void minute(vector<string> &ans,int arr[],int num ){
				if(num==0) return;
				 //all led used for minutes 
				for(int i=0;i<60;i++){
							  if(num==arr[i] && i<10){
								  string temp="0:0"+to_string(i);
								  ans.push_back(temp);
							  }else if(num==arr[i] && (i>=10 && i<60)){
								   string temp="0:"+to_string(i);
								  ans.push_back(temp);
							  }   
				  }
				}

				void Hour_Minute(vector<string> &ans,int arr[],int numH,int numM ){
				
				for(int j=1;j<=11;j++){
				   for(int i=1;i<60;i++){
							  if((numM==arr[i] && i<10) && numH ==arr[j]){
								  string temp=to_string(j)+":0"+to_string(i);
								  ans.push_back(temp);
							  }else if((numM==arr[i] && (i>=10 && i<60)) && numH==arr[j]){
								   string temp=to_string(j)+":"+to_string(i);
								  ans.push_back(temp);
							  }
					 }
				  }
				}

				vector<string> readBinaryWatch(int num) {
				int hs=0,mf=0,ms=0;
				vector<string> ans;

				int arr[60];
				arr[0]=0;
				for(int i=1;i<60;i++)
					 arr[i]=(i&1)+arr[i/2];

				   if(num==0){
					   ans.clear();
					   ans.push_back("0:00");
					   return ans;
				   } 
				for(int i=0,j=num;(i<=num && j>=0);i++,j--){
					if(j==0)
					hour(ans,arr,i);
				   if(i==0)
					minute(ans,arr,j);
					//if(i ==0|| j==0)
					   Hour_Minute(ans,arr,i,j);  //pair i,j as H,M
				}
				return ans;
				}
				};
					
					
					



Made 3 functions:
1. if only find out hours.
2.  if only find out minutes.
3.  3rd case is both hour and minute.
          Now we have to find out how many possible cases can be of hour_minute combination :
		  for example : if 3 led light up then possible combination are:
		                         Hour 's led       Minute's LED
								   0                 |          3
								   1                 |          2
								   2                 |          1
								   3                 |          0
								   
					if hours led light up = 0, it means only minute led are lighting up , so work with minute () only
					if  minute led light up = 0, it means only minute led are lighting up , so work with hours () function only
					if hours led light up != 0 and minute led !=0, it means only minute led are lighting up , so work with Hour_Minute () only
					
					--------------------------------------------------------------------------
					You can easily get flow of all function if focus a little bit. if you really want to understand it. 
					in method we are doing 2 things :
					
					WE Made an array which has (total counts of et bit in a number) as an array element. in other way, array consist of count set bit of first 60 number only. because minute limit is 59 as per question.
					Please note index of array repersents number 0 to 60. 
					so if we have that array : we can check if num (i.e- number of LED is ON) == arr[i] (countset bit)
					if yes push the current index (which is nothing but the number (in range 0 to 60 )itself) .and same as we do for minute() and hour_minute();
					In Hour_minute : we are iterating for everyhour if there exist any minute or not.
					
					Please let me know anyone has further doubt.
	
		
				
				
				
		
					
