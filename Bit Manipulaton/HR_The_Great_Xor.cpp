================================================  The Great Xor ======================================
Given a long integer n, count the number of values of k satisfying the following conditions:

    k⊕n > n
    0<k<n

where n and k are long integers and ⊕ is the bitwise XOR operator.

You are given q queries, and each query is in the form of a long integer denoting nnn. For each query, print the total number of values of satisfying the conditions above on a new line.

For example, you are given the value n=5. Condition 2 requires k<n The following tests are run:

    1⊕5=4
    2⊕5=7
    3⊕5=6
    4⊕5=1

We find that there are 2 values meeting the first condition: 2 and 3.

Function Description

Complete the theGreatXor function in the editor below. It should return an integer that represents the number of values satisfying the constraints.

Constraints

    1≤q≤10^5
    1≤n≤10^10
    
    ======================================================================================
    Approach :   Find next greater powerof2 than n
                 substract (number + 1) from that power.
                 
       Time Complexity : O(log n)
     =======================================================================================
     
     Solution :
                   long theGreatXor(long x) {
                      long value = 1;
                        while (value <= x)
                            value *= 2;
                      return value - x-1;
                  }
