#include <bits/stdc++.h>
#define ll long long int
#define N 100000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
int A[N+1], B[N+1];
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
void printDistinct(int arr[],int n,int dist[]) 
{ 
    // Creates an empty hashset 
    unordered_set<int> s; 
    int j=1;
    // Traverse the input array 
    for (int i=1; i<n; i++) 
    { 
        // If not present, then put it in 
        // hashtable and print it 
        if (s.find(arr[i])==s.end()) 
        { 
            s.insert(arr[i]); 
            dist[j]= arr[i] ;
            j++; 
        } 
    } 
}
int main(){
    cout<<1%0;
    return 0;
}