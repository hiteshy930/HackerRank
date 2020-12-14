/*
============================================ Between 2 set ===========================================
Question : find out multiple of array and same will divisor for array 2

There will be two arrays of integers. Determine all integers that satisfy the following two conditions:

    The elements of the first array are all factors of the integer being considered
    The integer being considered is a factor of all elements of the second array

These numbers are referred to as being between the two arrays. Determine how many such numbers exist

Function Description

Complete the getTotalX function in the editor below. It should return the number of integers that are betwen the sets.

getTotalX has the following parameter(s):

    int a[n]: an array of integers
    int b[m]: an array of integers

Returns

    int: the number of integers that are between the sets

Input Format

The first line contains two space-separated integers n,
and m, the number of elements in arrays a and b.
The second line contains distinct space-separated integers a[i]
The third line contains distinct space-separated integers b[j]

Sample Input

2 3
2 4
16 32 96

Sample Output

3

Explanation

2 and 4 divide evenly into 4, 8, 12 and 16.
4, 8 and 16 divide evenly into 16, 32, 96.

4, 8 and 16 are the only three numbers for which each element of a is a factor and each is a factor of all elements of b. 

*/
==================================== SOLUTION ===========================
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */
int gcd(int a,int b){
    if(a==0)
    return b;
    return gcd(b%a,a);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
int getTotalX(vector<int> a, vector<int> b) {
      //         Find LCM of A[i] 
      //          Find HCF of B[i]                                                                      //  LOGIC
      //             Find Multiples of LCM which divides HCF of b[i]

int gcd(int a,int b){
	if(a==0)                            //TO find out GCD of a & b numbers
    return b;
    return gcd(b%a,a);
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);                 //To find out of lcm of a & b
}
int getTotalX(vector<int> a, vector<int> b) {
        int lcmOfArray=a[0];
        int gcdOfArray=b[0];
				
				 int a_size=a.size();
        int b_size=b.size();
//LCM of array A
        for(int i=1;i<a_size;i++)
        {
            lcmOfArray=lcm(lcmOfArray,a[i]);
        }
//GCD of Array B				
        for(int i=1;i<b_size;i++)
        {
            gcdOfArray=gcd(gcdOfArray,b[i]);
        }
        int count=0;
//Find out Multiples of LCM which divides GCD				
        for(int i=lcmOfArray;i<=gcdOfArray;i+=lcmOfArray)
        {
          if(gcdOfArray%i==0)
              count++;
        }        
        return count++;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    string brr_temp_temp;
    getline(cin, brr_temp_temp);

    vector<string> brr_temp = split(rtrim(brr_temp_temp));

    vector<int> brr(m);

    for (int i = 0; i < m; i++) {
        int brr_item = stoi(brr_temp[i]);

        brr[i] = brr_item;
    }

    int total = getTotalX(arr, brr);

    fout << total << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
