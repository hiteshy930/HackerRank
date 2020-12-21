Given two integers, L and R, find the maximal values of A xor B, where A and B satisfies the following condition:

    L≤A≤B≤R

Link

Maximizing XOR
Complexity:

time complexity is O(N^2);

space complexity is O(1)

==================================================
#include <bits/stdc++.h>

using namespace std;

// Complete the maximizingXor function below.
int maximizingXor(int l, int r) {
    if(l==r) return 0;
  int max=INT_MIN;
    for(int i=l;i<=r;i++){
        for(int j=i;j<=r;j++){                    ///logic
            if((i^j) > max) 
               max= i ^ j;
        }
    }
   return max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int l;
    cin >> l;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int r;
    cin >> r;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = maximizingXor(l, r);

    fout << result << "\n";

    fout.close();

    return 0;
}
