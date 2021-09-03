//Coded by Abhijay Mitra (AbJ) on 2020 / 12 / 27 in 20 : 38 : 50
//title - d.cpp
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
int n, m, l[N], r[N], p[N], h[N];
char b[N][2];
int parent[N],ind[N];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    ind[v] = 1;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ind[a] < ind[b])
            swap(a, b);
        parent[b] = a;
        ind[a] += ind[b];
        ind[b] = 0;
    }
}
void solve(){
  cin >> n >> m;
  rep(i, 1, n){
    cin >> l[i] >> r[i];
    make_set(i);
  }
  rep(i, 1, m){
    cin >> p[i] >> h[i];
    if(h[i] == 2)b[p[i]][1] = 'x';
    if(h[i] == 1)b[p[i]][0] = 'x';
  }
  cout << - 1 << "\n";
  rep(i, 1, n){
      if(b[i][0] != 'x' and l[i] != - 1)
        union_sets(i, l[i]);
      if(b[i][1] != 'x' and r[i] != - 1)
        union_sets(i, r[i]);
  }
  vi a(n);
  per(i, m, 1){
    if(ind[find_set(p[i])] == 1)a[p[i] - 1] = i;
    if(h[i] == 2)union_sets(p[i], r[p[i]]);
    if(h[i] == 1)union_sets(p[i], l[p[i]]);
  }
  rep(i, 2, n)cout << a[i - 1] << "\n";
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}