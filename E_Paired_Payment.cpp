//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 09 in 04 : 10 : 21
//title - E_Paired_Payment.cpp
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
// const double Pi = M_PI;
#define F first
#define S second
int n, m, u, v, w, x; vvi dp;
priority_queue<tuple<int, int, int, int>>q;
vvpii a;
void solve(){
	cin >> n >> m;
	dp = vvi(n + 1, vi(51, inf));
	// fill(all(dp[1]), 0LL);
	a.resize(n + 1);
	dp[1][0] = 0;
	a[0].clear();
	rep(i, 1, m){
		cin >> u >> v >> w;
		a[u].pb(pii{v, w});
		a[v].pb(pii{u, w});
	}
	q.push({0, 1, 0, 0});
	while(q.empty() == 0){
		auto [d, u, wxu, par] = q.top();
		q.pop();
		//x u v
		if(- d > dp[u][wxu])
			continue;
		for(auto &[v, wuv]: a[u]){
			if(par == 1 and dp[v][0] > - d + wuv * wuv + wuv * wxu * 2)
				dp[v][0] = - d + wuv * wuv + wuv * wxu * 2,
				q.push({- dp[v][0], v, 0, par ^ 1});
			if(par == 0 and dp[v][wuv] > - d + wuv * wuv)
				dp[v][wuv] = - d + wuv * wuv,
				q.push({- dp[v][wuv], v, wuv, par ^ 1});
		}
	}
	rep(i, 1, n)
		if(dp[i][0] == inf)
			dp[i][0] = - 1;
	rep(i, 1, n)
		cout << dp[i][0] << " ";

}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}