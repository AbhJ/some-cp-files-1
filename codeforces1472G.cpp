//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 16 in 17 : 25 : 06
//title - G_Moving_to_the_Capital.cpp
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
int n, m, dp[N][2], vis[N], dist[N];
vi a[N], b[N], c[N];
void dfs(int u){
	// cout << u;
	if(u != 1)dp[u][0] = dp[u][1] = dist[u];
	for(auto &i: c[u]){
		if(dp[i][1] == 0 and i != 1){
			dp[i][1] = dp[u][0] + 1;
		}
		else
			if(i != 1)
				dp[i][1] = min(dp[i][1], dp[u][0] + 1);
	}
	for(auto &i: b[u]){
		if(dp[i][0] == 0 and i != 1){
			dp[i][0] = dp[u][0] + 1;
			dfs(i);
		}
		else
			if(i != 1)
				dp[i][0] = min(dp[i][0], dp[u][0] + 1);
		if(dp[i][1] == 0 and i != 1){
			dp[i][1] = dp[u][1] + 1;
			// dfs(i);
		}
		else
			if(i != 1)
				dp[i][1] = min(dp[i][1], dp[u][1] + 1);
	}
}
void dis(int u){
	queue<int>q;
	q.push(1);
	while(q.empty() == 0){
		int z = q.front();
		q.pop();
		for(auto &i: a[z])
			if(dist[i] == 0 and i != 1)
				q.push(i),
				dist[i] = dist[z] + 1;
	}
}
vi d[N];
void solve(){
	cin >> n >> m;
	rep(i, 1, n * 10)a[i].clear(), b[i].clear(), c[i].clear(), dp[i][0] = dp[i][1] = 0, dist[i] = 0, d[i].clear();
	rep(i, 1, m){
		int u, v;
		cin >> u >> v;
		a[u].pb(v);
	}
	dis(1);
	rep(i, 1, n){
		for(auto &j: a[i])if(dist[j] > dist[i])	b[i].pb(j);
		else c[i].pb(j);
	}
	int x = 0;
	rep(i, 1, n)d[dist[i]].pb(i), x = max(x, dist[i]), dp[i][1] = dp[i][0] = dist[i];
	per(dep, x, 1)for(auto &i: d[dep]){
		for(auto &j: b[i])
			//honesty
			dp[i][1] = min(dp[i][1], dp[j][1]);
		for(auto &j: c[i])
			//only dishonesty
			dp[i][1] = min(dp[i][1], dp[j][0]);
	}
	rep(i, 1, n)cout << dp[i][1] << " ";
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}