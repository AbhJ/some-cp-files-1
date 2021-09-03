//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 10 in 23 : 19 : 03
//title - D_Strange_Housing.cpp
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
int n, m;vi a[N];int vis[N];
void dfs(int u){
	vis[u] = 1;
	for(auto &i: a[u]){
		if(vis[i] == 0)
			dfs(i);
	}
}
queue<int>q;
void en(){
	int cnt[3] = {0, 0, 0};
	rep(i, 1, n)if(vis[i] != 0)cnt[vis[i]]++;
	int z = 0;
	if(cnt[1] > cnt[2])z = 1;
	else z = 2;
	cout << "YES\n" << cnt[1] << "\n";
	rep(i, 1, n)if(vis[i] == 1)cout << i << " ";
}
void fu(){
	fill(vis + 1, vis + 1 + n, 0LL);
	cout << "NO";
}
void solve(){
	cin >> n >> m;
	rep(i, 1, n)a[i].clear();
	rep(i, 1, m){
		int x, y;
		cin >> x >> y;
		a[x].pb(y);
		a[y].pb(x);
	}
	dfs(n - 1);
	rep(i, 1, n)if(vis[i] == 0){fu();return;}
	fill(vis + 1, vis + 1 + n, 0LL);
	for(auto &x: a[1])vis[x] = 2, q.push(x);
	vis[1] = 1;
	while(q.empty() == 0){
		int x = q.front();
		q.pop();
		for(auto &i: a[x])if(vis[i] == 0){
			for(auto &y: a[i])vis[y] = 2, q.push(y);
			vis[i] = 1;
		}
	}
	en();
	fill(vis + 1, vis + 1 + n, 0LL);
	q = queue<int>();
	return;

}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}