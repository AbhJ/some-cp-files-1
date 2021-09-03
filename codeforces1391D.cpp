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
using vi = std::vector<char>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=1e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,a[N],dp[N][8];
void solve(){
  cin>>n>>m;
  if(n>3){cout<<-1;return;}
  vvi c(n+1,vi(m+1,0));
  rep(i,0,n-1){
    rep(j,1,m){
      cin>>c[i][j];
    }
  }
  rep(j,1,N-1)rep(i,0,7)dp[j][i]=inf;
  rep(j,1,m){
    rep(i,0,n-1)
      a[j]|=(c[i][j]-'0')<<i;
  }
  rep(i,0,(1<<n)-1)dp[1][i]=__builtin_popcount(i^a[1]);
  rep(j,2,m){
    rep(m1,0,(1<<n)-1)
      rep(m2,0,(1<<n)-1){
        bool no=0;
        int koita_change=__builtin_popcount(m2^a[j]);
        rep(i,0,n-2){
          int cnt=!!(m1&(1<<i));
          cnt+=!!(m2&(1<<i));
          cnt+=!!(m1&(1<<(i+1)));
          cnt+=!!(m2&(1<<(i+1)));
          if(cnt==0 or cnt==2 or cnt==4)no=1;
        }
        if(no==1)continue;
          dp[j][m2]=min(dp[j][m2],dp[j-1][m1]+koita_change);
      }
  }
  cout<<*min_element(dp[m],dp[m]+(1<<n));
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