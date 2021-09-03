// Computes sum all sub-array 
long int SubArraySum(int arr[], int n) 
{ 
    long int result = 0; 
  
    // Pick starting point 
    for (int i=0; i <n; i++) 
    { 
        // Pick ending point 
        for (int j=i; j<n; j++) 
        { 
            // sum subarray between current 
            // starting and ending points 
            for (int k=i; k<=j; k++) 
                result += arr[k] ; 
        } 
    } 
    return result ; 
} 

#include <bits/stdc++.h>
using namespace std;
int main(){
    


    return 0;
}