//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 20 in 21 : 04 : 02
//title - Random_Naruto.cpp
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
const int N=1e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, a[N], pre[N], dp[N][N];
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
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
// int f(int cur){
// 	if(cur == 0)
// 		return 1;
// 	int tmp = cur - a[cur];
// 	int ans = 1;
// 	rep(i, cur + 1, n){
// 		if(tmp <= i - a[i])
// 			ans = mul(ans, mul(tmp, f(i)));
// 		tmp = min(tmp, i - a[i]);
// 	}
// 	return mul(ans, f(cur - 1));
// }
int ans = 0;
void solve(){
	cin >> n;ans = 1;
	pre[0] = inf;
	rep(i, 1, n)
		cin >> a[i];
	rep(i, 0, n)
		rep(j, 0, n)
			dp[i][j] = 0;
	rep(i, 1, n)
		pre[i] = min({a[i], i, pre[i - 1] + 1});
	rep(i, 1, n){
		ans = mul(ans, pre[i]);
	}
	cout << ans;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}