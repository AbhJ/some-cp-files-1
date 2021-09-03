//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 03 in 02 : 30 : 44
//title - E_Egor_in_the_Republic_of_Dagestan.cpp
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
int n, m, x, y, vis[N], dis[N], col[N];
vpii a[N];
int f(int c){
	fill(dis + 1, dis + 1 + n, inf);
	fill(col + 1, col + n, - 1);
	queue<int> q;
	q.push(n);
	vis[n] = 1;
	dis[n] = 0;
	while(q.empty() != 1){
		int u = q.front();
		q.pop();
		for(auto &[x, typ]: a[u]){
			if(vis[x] == 1)continue;
			if(col[x] == - 1){
				col[x] = typ ^ 1;
				//we may skip the vertex if it does not appear again
			}
			if(col[x] == typ){
				//we wanr min to be maxi
				dis[x] = min(dis[x], dis[u] + 1);
				//this veretx is unavoidable from n
				vis[x] = 1;
				q.push(x);
			}
		}
	}
	return dis[1];
}
void solve(){
	cin >> n >> m;
	rep(i, 1, m){
		cin >> x >> y;
		int t;cin >> t;
		a[y].pb(mp(x, t));
	}
	f(0);
	if(dis[1] == inf)cout << -1;
	else cout << dis[1];
	cout << "\n";
	rep(i, 1, n - 1)
		cout << abs(col[i]);
	cout << 1;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}