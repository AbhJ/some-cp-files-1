//Coded by Abhijay Mitra
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator> 
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
// #include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
#define res(vector) v.resize(unique(v.begin(), v.end()) - v.begin());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
set<int>a[N],A[N];int n,m,u,v,T,col[N];set<int>s[N];pair<int,int>t[N];
set<int>f;
void solve(){
  cin>>n>>m;
  for(int i=1;i<=m;i++){
    cin>>u>>v;
    a[u].insert(v),a[v].insert(u);
  }
  for(int i=1;i<=n;i++){
    cin>>t[i].F;t[i].S=i;
    col[i]=t[i].F;
  }
  sort(t+1,t+1+n);
  for(int i=1;i<=n;i++){
    int x=0;
    for(auto j:a[t[i].S]){
      if(col[j]<=t[i].F){
        x+=(f.count(col[j])==0);
        f.insert(col[j]);
      }
    }
    if(x!=(t[i].F)-1 or f.count(t[i].F)==1)cout<<-1,exit(0);
    for(auto j:a[t[i].S])f.erase(col[j]);
  }
  for(int i=1;i<=n;i++)cout<<t[i].S<<" ";
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}