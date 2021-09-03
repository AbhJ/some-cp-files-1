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
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
#define deb(x) cout<<"\n["<<#x<<" = "<<x<<"]\n";
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
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,dp[4][N][N];string s[N];
vvi dx{{0,-1},{1,0},{0,1},{-1,0}},dy{{-1,0},{0,1},{-1,0},{0,1}};
void solve(){
  cin>>n>>m;
  rep(i,1,n)cin>>s[i],s[i]='#'+s[i];
  rep(i,1,n)
    rep(j,1,m)
      rep(k,0,3)
        dp[k][i][j]=1;
  rep(i,1,n)
    rep(j,1,m)
      if(s[i][j]==s[i+dx[0][0]][j+dy[0][0]] and s[i][j]==s[i+dx[0][1]][j+dy[0][1]])
        dp[0][i][j]=1+min(dp[0][i+dx[0][0]][j+dy[0][0]],dp[0][i+dx[0][1]][j+dy[0][1]]);
  per(i,n,1)
    per(j,m,1)
      if(s[i][j]==s[i+dx[1][0]][j+dy[1][0]] and s[i][j]==s[i+dx[1][1]][j+dy[1][1]])
        dp[1][i][j]=1+min(dp[1][i+dx[1][0]][j+dy[1][0]],dp[1][i+dx[1][1]][j+dy[1][1]]);
  per(i,n,1)
    rep(j,1,m)
      if(s[i][j]==s[i+dx[2][0]][j+dy[2][0]] and s[i][j]==s[i+dx[2][1]][j+dy[2][1]])
        dp[2][i][j]=1+min(dp[2][i+dx[2][0]][j+dy[2][0]],dp[2][i+dx[2][1]][j+dy[2][1]]);
  rep(i,1,n)
    per(j,m,1)
      if(s[i][j]==s[i+dx[3][0]][j+dy[3][0]] and s[i][j]==s[i+dx[3][1]][j+dy[3][1]])
        dp[3][i][j]=1+min(dp[3][i+dx[3][0]][j+dy[3][0]],dp[3][i+dx[3][1]][j+dy[3][1]]);
  int ans=0;
  rep(i,1,n)
    rep(j,1,m){
      int z=inf;
      rep(k,0,3)
        z=min(z,dp[k][i][j]);
      ans+=z;
    }
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}