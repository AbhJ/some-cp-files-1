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
int n, a, b, da, db, x, y;
vi A[N];
vpii bob;
vi euler,height,first,t;
void dfs1(int u,int h=0,int p=0){
  euler.pb(u);
  height[u]=h++;
  first[u]=euler.size()-1;
  for(auto i:A[u])if(i!=p){
    dfs1(i,h,u);
    euler.pb(u);
  }
}
int h[N];
void build(int v=1, int tl=0, int tr=euler.size()-1) {
    if (tl == tr) {
        t[v] = euler[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v]=(height[t[v*2]]<height[t[v*2+1]]?t[v*2]:t[v*2+1]);
    }
}
//queries
int sum(int l, int r,int v=1, int tl=0, int tr=euler.size()-1) {
    if (l > r) 
        return inf;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    int s1= sum( l, min(r, tm),v*2, tl, tm);
    int s2= sum(max(l, tm+1), r,v*2+1, tm+1, tr );
    if(s1==inf)return s2;
    if(s2==inf)return s1;
    return (height[s1]<height[s2])?s1:s2;
}
int q(int a,int b){
  a=first[a],b=first[b];
  if(b<a)swap(a,b);
  return sum(a,b);
}
void dfs (int u, int p = -1) {
  for(auto i: A[u]) if(i!=p) {
    h[i] =  h[u] + 1;
    dfs(i, u);
  }
  if(h[u] % db == 0)bob.pb(u, h[u] / db);
}
void solve() {
  cin >> n; fill (h + 1, h + 1 + n, 0);
  rep(i, 1, n)A[i].clear();
  euler.clear();
  height = first = vi(n + 1, 0);
  cin >> a >> b >> da >> db;
  rep(i, 1, n - 1){
    cin >> x >> y;
    A[x].pb(y);
    A[y].pb(x);
  }
  dfs1(1);t=vi(euler.size()*4,0);
  dfs(b);
  build();
  int ind = max_element(h + 1, h + 1 + n) - h;
  int dist = h[a];
  fill (h + 1, h + 1 + n, 0);
  dfs(ind);
  int dia = *max_element(h + 1, h + 1 + n);
  if(2 * da >= dia){
    cout << "Alice";return;
  }
  if(da >= dist){
    cout << "Alice";return;
  }
  if(2 * da < db){
    cout << "Bob";return;
  }
  cout<<"Alice";
}
int32_t main()
{
  ibs;cti;
  // solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}