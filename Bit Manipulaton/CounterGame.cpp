==============================   counter game    ===========================================================
Louise and Richard play a game. They have a counter set to N. Louise gets the first turn and the turns alternate thereafter. In the game, they perform the following operations.

    If N is not a power of 2, reduce the counter by the largest power of 2 less than N.
    If N is a power of 2, reduce the counter by half of N i.e-(n = n - nextLower power of 2).
    The resultant value is the new N which is again used for subsequent operations.

The game ends when the counter reduces to 1, i.e., N == 1, and the last person to make a valid move wins.

Given N, your task is to find the winner of the game.

Complexity:

time complexity is O(N)

space complexity is O(1)

LOGIC++++++++++++++++++++++++++++++>>>>>>>>> find count of set bit in (N-1) 
                                                    ---> take bitwise AND of ( 1 & count )
                                                                  --> if 1 -> louise otherwise Richard
=============================================================================
#include <bits/stdc++.h>

using namespace std;
//Check total no of set bit in a number
long long set_bit(long long n){
    int count=0;
    while(n!=0){
        n=n&(n-1);                              //find out set bit
        count++;
    }
    return count;
}

//CHECK FOR ( & ) of setbitcountof(n-1) with 1
    // if 1 --> louise win
    //if 0 --> Richard wins
// Complete the counterGame function below.
string counterGame(long n) {
        
      return  (set_bit(n-1) & 1)? "Louise" : "Richard";       // solution one line 

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        long n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
