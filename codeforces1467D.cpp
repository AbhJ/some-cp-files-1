//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 09 in 01 : 38 : 43
//title - d.cpp
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
const int N=5e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, k, q, a[N], dp[5010][5010], c[N];
int mul(int a,int b){
  return ((a)*(b))%M;
}
int add(int a,int b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
void solve(){
    cin >> n >> k >> q;
    rep(i, 1, n)dp[i][0] = 1;
    rep(j, 1, k)rep(i, 1, n)dp[i][j] = add((i != 1 ? dp[i - 1][j - 1] : 0LL), (i != n ? dp[i + 1][j - 1] : 0LL));
    rep(i, 1, n)rep(j, 0, k)c[i] = add(c[i], mul(dp[i][j], dp[i][k - j]));
    int ans = 0;
    rep(i, 1, n)
        cin >> a[i],
        ans = add(ans, mul(a[i], c[i]));
    while(q--){
        int x, y;
        cin >> x >> y;
        ans = add(ans, mul((sub(y, a[x])), c[x]));
        cout << ans << "\n";
        a[x] = y;
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