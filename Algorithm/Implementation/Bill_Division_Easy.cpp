========================================= Bill Division ===============================================

Two friends Anna and Brian, are deciding how to split the bill at a dinner.
Each will only pay for the items they consume. Brian gets the check and calculates Anna's portion. You must determine if his calculation is correct.

Function Description

Complete the bonAppetit function in the editor below. It should print Bon Appetit if the bill is fairly split. Otherwise, it should print the integer amount of money that Brian owes Anna.

bonAppetit has the following parameter(s):

bill: an array of integers representing the cost of each item ordered
k: an integer representing the zero-based index of the item Anna doesn't eat
b: the amount of money that Anna contributed to the bill
Sample Input 0

4 1
3 10 2 9
12
Sample Output 0

5
==========================================================================
void bonAppetit(vector<int> bill, int k, int b) {
    if(bill.size()<=1) return;
   int n=bill.size();
   int b_charged=b;
   int b_actual=0;
    for(int i=0;i<n;i++){
        if(i==k)
        continue;
        else
         b_actual +=bill[i];
    }  
    b_actual /=2;
    if(b_actual != b_charged)
    cout<<b_charged-b_actual<<endl;
    else {
    cout<<"Bon Appetit"<<endl;
    }
}
