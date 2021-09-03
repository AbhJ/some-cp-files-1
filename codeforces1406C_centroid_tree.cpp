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
int n;
vector<int> Centroid(const vector<vector<int>> &g) {
        int n = g.size();
        vector<int> centroid;
        vector<int> sz(n);
        function<void (int, int)> dfs = [&](int u, int prev) {
                sz[u] = 1;
                bool is_centroid = true;
                for (auto v : g[u]) if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > n / 2) is_centroid = false;
                }
                if (n - sz[u] > n / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs(0, -1);
        return centroid;
}
int x,y;
vector<set<int>>g;
void dfs(int u,int p=-1){
  int cnt=0;
  for(auto i:g[u])if(i!=p)cnt++,dfs(i,u);
  if(cnt==0)x=u,y=p;return;
}
void solve(){
	int n;cin>>n;vvi a(n);g=vector<set<int>>(n);vi deg(n);
	rep(i,0,n-2){
		cin>>x>>y;
		x--;y--;
		a[x].pb(y);
		a[y].pb(x);
    g[x].insert(y);
    g[y].insert(x);
    deg[x]++,deg[y]++;
	}
	vi c=Centroid(a);
  if(c.size()==1){
    cout<<x+1<<" "<<y+1<<"\n"<<x+1<<" "<<y+1;
  }
  else{
    // cout<<c[0]+1<<" "<<c[1]+1<<"\n";
    g[c[0]].erase(c[1]);
    g[c[1]].erase(c[0]);
    dfs(c[0],c[1]);
    cout<<x+1<<" "<<y+1<<"\n"<<x+1<<" "<<c[1]+1;
  }
}
int32_t main()
{
  ibs;cti;
  // solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}