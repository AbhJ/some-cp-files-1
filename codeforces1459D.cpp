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
#include <bits/stdc++.h>
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
using vi = std::vector<double>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N = 2e2+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, a[N], b[N], pos[N];
void solve(){
  cin >> n;
  rep(i, 1, n)cin >> a[i] >> b[i];
  // rep(i, 1, n)cin >> b[i];
  double total = accumulate(b + 1, b + 1 + n, 0);
  // vi v;
  vvi dp(N * N, vi(N, - inf));
  dp[0][0] = 0;
  double ans = - inf;
  int cap = 0;
  rep(i, 1, n){
    auto & tmp = dp;
    cap += a[i];
    per(c, cap, 1) per(k, n, 1)if(c >= a[i]){
      //choose
      tmp[c][k] = max(dp[c - a[i]][k - 1] + (double)b[i], dp[c][k]);
      // else tmp[c][i] = dp[c][i];
    }
  }
  rep(k, 1, n){
      ans = - inf;
      auto & tmp = dp;
      rep(c, 1, 100 * 100 + 10) ans = max(min(tmp[c][k] + (total - tmp[c][k]) / (double)2.0, (double)c), ans);
      cout << fixed << setprecision(20) << ans << " ";
  }
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}