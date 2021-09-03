//Coded by Abhijay Mitra (AbJ) on 2021 / 05 / 01 in 18 : 21 : 52
//title - E_Sneaking.cpp
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
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int pos = uniform_int_distribution<int>(l,r)(rng);
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
using namespace std;
const int N=5e2+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, m;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int a[N][N], b[N][N], dp[N][N], cz;
int f(int i, int j, int taka){
	return (i <= n and j <= m and i >= 1 and j >= 1 and dp[i][j] > taka);
}
void solve(){
	cin >> n >> m;
	// cout << "ok";
	rep(i, 1, n)
		rep(j, 1, m - 1)
			cin >> a[i][j];
	rep(i, 1, n - 1)
		rep(j, 1, m)
			cin >> b[i][j];
	rep(i, 1, n)
		rep(j, 1, m)
			dp[i][j] = inf;
	priority_queue<tuple<int, int, int>>q;
	q.emplace(0, 1, 1);
	dp[1][1] = 0;
	while(q.empty() == 0 and cz++ < 1e6){
		auto [taka, x, y] = q.top();
		q.pop();
		// cout << taka;
		if(- taka > dp[x][y])
			continue;
		rep(k, 0, 3)if(k != 2){
			int X = x + dx[k], Y = y + dy[k];
			int tak = 0;
			if(k == 0)
				tak = b[x][y] + dp[x][y];
			if(k == 1)
				tak = a[x][y] + dp[x][y];
			if(k == 3)
				tak = a[x][y - 1] + dp[x][y];
			// assert(taka != 0 and f(X, Y, tak) == 1);
			if(f(X, Y, tak))
				q.emplace(- tak, x, y),
				dp[x][y] = tak;
		}
		else{
			// auto [taka, x, y] = q.top();
			// q.pop();
			// if(- taka > dp[x][y])
			// 	continue;
			// rep(i, 1, x - 1){
			// 	int X = x + (- i), Y = y;
			// 	int tak = 1 + i + dp[x][y];
			// 	if(f(X, Y, tak))
			// 		q.emplace(- tak, x, y),
			// 		dp[x][y] = tak;
			// }
		}
	}
	cout << dp[n][m];
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}