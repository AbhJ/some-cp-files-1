//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 06 in 08 : 02 : 37
//title - E_Tree_Queries.cpp
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
int n, m;
int x,y,c,p[N],d[N],P[N],T,t[2][N];vector<int>A[N],h[N];
void dfs(int u,int p=0){
  t[0][u]=++T;
  h[u][0]=p;P[u]=p;
  for(int i=1;i<=ceil(log2(n));i++)h[u][i]=h[h[u][i-1]][i-1];
  for(auto i:A[u])if(i!=p){
    d[i]=d[u]+1;dfs(i,u);
  }
  t[1][u]=++T;
}
bool is_ancestor(int u,int v){
  if(t[0][u]<t[0][v] and t[1][u]>t[1][v])return 1;
  return 0;
}
int lca(int u,int v){
  if(is_ancestor(u,v))return u;
  if(is_ancestor(v,u))return v;
  for(int i=ceil(log2(n));i>=0;i--)
    if(is_ancestor(h[u][i],v)==0)u=h[u][i];
  return h[u][0];
}
int dist(int u,int v){
  return d[u]+d[v]-2*d[lca(u,v)];
}
void solve(){
	cin >> n >> m;
	rep(i, 0, n - 1)A[i].clear(), h[i].clear();
	memset(p, 0, sizeof p);
	memset(P, 0, sizeof P);
	memset(d, 0, sizeof d);
	for(int i=0;i<n;i++)
    h[i]=vector<int>(ceil(log2(n))+1);
	// for(int i=0;i<m;i++)cin>>P[i];
	for(int i=0;i<n - 1;i++){
		cin>>x>>y;x--,y--;
		A[x].pb(y),A[y].pb(x);
	}
  	dfs(0);
	rep(i, 1, m){
		int k;cin >> k;
		vi a(k);
		for(auto &j: a)cin >> j, j--;
		int ma = - 1;
		for(auto &j: a){
			if(ma == - 1 or d[j] > d[ma])ma = j;
		}
		// cout << ma + 1 << "\n";
		for(auto &j: a){
			if(lca(j, ma) == j or dist(lca(j, ma), j) == 1);
			else {
				cout << "NO";
				goto F;
			}
		}
		cout << "YES";
		F:;
		cout << "\n";
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