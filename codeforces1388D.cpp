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
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
#define deb(x) cout<<"\n["<<#x<<" = "<<x<<"]\n";
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
int n,a[N],b[N],vis[N],ans;vi A[N],v[2];
void dfs(int u){
	vis[u]=1;
	for(auto i:A[u])if(vis[i]==0){
			dfs(i);
	}
	if(b[u]!=-1 and a[u]>0)a[b[u]]+=a[u];
	ans+=a[u];
	if(a[u]>0)v[0].pb(u);
	else v[1].pb(u);
}
void solve(){
	cin>>n;
	rep(i,1,n)cin>>a[i];
	rep(i,1,n)cin>>b[i];
	rep(i,1,n){
		if(b[i]!=-1)A[b[i]].pb(i);
	}
	rep(i,1,n)if(vis[i]==0)dfs(i);
	cout<<ans<<"\n";
	for(auto i:v[0])cout<<i<<" ";
	reverse(all(v[1]));
	for(auto i:v[1])cout<<i<<" ";
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}