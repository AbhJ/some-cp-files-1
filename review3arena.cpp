
// Given a complete binary tree with N nodes and each node have an distinct integer attached with it, find the minimum number of swaps you can make to convert the binary tree into binary search tree. In one swap, you can select any two nodes and swap their values.

// You will be given the array representation of the binary tree. Root of the tree will be at . Left child of root will be at  and right child of root will be at . Left child of node at array position k will be at  and right child of node at array position k will be at .

// Input format:
// First line contains an integer, N , denoting the number of nodes. Second line contains N space separated integers,  ,, denoting the value attached to  node.

// Output format:
// Print a single integer, denoting the minimum number of swaps needed to convert binary tree into a binary search tree.

// SAMPLE INPUT 
// 3
// 1 2 3
// SAMPLE OUTPUT 
// 1
// Explanation
// We need to only one swap  to convert the given binary tree into binary search tree.

// enter image description here





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
using namespace std;
int a[N+1];
int b[N+1];
int j=1;
void inorder(int i,int n)
{
    if(i>n)
    return ;
    inorder(2*i,n);
    b[j++]=a[i];
    inorder(2*i+1,n);
}
int main()
{
    // freopen("input.txt","r",stdin);
    ibs;cti;
    int n;
    cin >> n;
    unordered_map <int,int> um2;
    f(i,1,n)
    {
        cin >> a[i];
    }
    inorder(1,n);
    f(i,1,n)
    {
        um2[b[i]]=i;
    }
    sort(a+1,a+n+1);
    int ans=0;
    f(i,1,n)
    {
     if(a[i]!=b[i])
        {
            ans++;
            int idx1=i;
            int idx2=um2[a[i]];
            //um2[b[idx1]]=idx2;
            swap(um2[b[idx1]],um2[b[idx2]]);
            swap(b[idx1],b[idx2]);
        }
    }
    cout << ans << endl;
}