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
int n;vi a, b, vis;
int f(int l1, int r1, int l2, int r2){
  rep(i, 0, r1 - l1)if(a[l1 + i] > b[l2 + i])return 0;
  return 1;
}
int g(int l1, int r1, int l2, int r2){
  rep(i, 0, r1 - l1)if(a[l1 + i] < b[l2 + i])return 0;
  return 1;
}
void solve(){
  cin >> n;
  vis = vi(2 * n + 1, 0);
  a = vi(n);
  b = vi();
  rep(i, 0, n - 1)cin >> a[i];
  rep(i, 0, n - 1)vis[a[i]] = 1;
  rep(i, 1, 2 * n)if(vis[i] == 0)
    b.pb(i);
  int ma = -inf, mi = inf, m, l = 0, r = n + 1;
  while(r - l > 1){
      m = ((l + r) >> 1);
      if(f(0, m - 1, n - m, n - 1) == 1)l = m;
      else r = m;
  }
  ma = l;
  l = 0, r = n + 1;
  swap(a, b);
  while(r - l > 1){
      m = ((l + r) >> 1);
      if(f(0, m - 1, n - m, n - 1) == 1)l = m;
      else r = m;
  }
  mi = n - l;
  cout << ma - mi + 1;
}
int32_t main()
{
  ibs;cti;
  // solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}