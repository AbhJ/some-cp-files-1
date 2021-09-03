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
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec "<<endl;
#define deb(x) cout<<endl<<"["<<#x<<" = "<<x<<"]"<<endl;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,a[N],dp[N];stack<int>s1,s2;vi l,r;
int f(int i){
  if(i==-1)return inf;
  if(i==n-1)return 0;
  if(dp[i]!=inf and i!=0)return dp[i];
  return dp[i]=1+min({f(l[i]),f(r[i]),f(i+1)});
}
void solve(){
  cin>>n;l=vi(n,-1),r=vi(n,-1);fill(dp+1,dp+n,inf);
  rep(i,0,n-1)cin>>a[i];
  s1.push(0),s2.push(0);
  rep(i,1,n-1){
      dp[i]=min(dp[i],dp[i-1]+1);
      /* While the array is not empty and the current element is greater than the top stack element. */
      while(!s1.empty() && a[s1.top()] <= a[i]) {
          int z=s1.top();s1.pop();
          /* Print the greater element. */
          if(a[i]!=a[z] and s1.empty()==0)l[s1.top()]=i,dp[i]=min(1+dp[s1.top()],dp[i]);
      }
      /* Push the current element. */
      s1.push(i);
      /* While the array is not empty and the current element is greater than the top stack element. */
      while(!s2.empty() && a[s2.top()] >= a[i]) {
          /* Print the greater element. */
          int z=s2.top();s2.pop();
          /* Print the greater element. */
          if(a[i]!=a[z] and s2.empty()==0)r[s2.top()]=i,dp[i]=min(dp[i],1+dp[s2.top()]);
      }
      /* Push the current element. */
      s2.push(i);
  }
  // cout<<f(0);
  cout<<dp[n-1];
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}