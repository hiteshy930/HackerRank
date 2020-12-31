====================================== Generate all permutaions of string ============================================



==========================================================================================
// C++ program to print all 
// permutations with duplicates allowed 
#include <bits/stdc++.h> 
using namespace std; 


// Function to print permutations of string 
// This function takes three parameters: 
// 1. String 
// 2. Starting index of the string 
// 3. Ending index of the string. 
void permute(string a, int l) 
{ 
	// Base case 
	if (l == a.length()-1) {
		cout<<a<<endl;
      return ;
    }
	else
	{ 
		// Permutations made 
      
		for (int i = l; i <a.length(); i++) 
		{ 
                                    cout<<"j: "<<i<<" i: "<<l<<endl;
			// Swapping done 
		    	swap(a[l], a[i]); 
                                    cout<<"first swap: " <<a<<endl;
		                                  cout<<"permute("<<a<<","<<l+1<<")"<<endl;	
          // Recursion called 
			permute(a, l+1); 
                                    cout<<"after permute j: "<<i<<" i: "<<l<<endl;
			//backtrack 
			swap(a[l], a[i]); 
                                    cout<<"second  swap: " <<a<<endl;
                                    cout<<"Loop ends here for j & i: "<<i<<" : "<<l<<endl<<endl;
		} 
	} 
} 

// Driver Code 
int main() 
{ 
	string str = "ABC"; 
	int n = str.size(); 
	permute(str, 0); 
	return 0; 
} 

// This is code is contributed by rathbhupendra 
