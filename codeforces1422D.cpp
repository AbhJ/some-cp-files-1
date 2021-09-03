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
int n,m,sx,sy,fx,fy,x,y;pii S,F;
int add(int a,int b){
  a+=b;
  return a;
}
static bool cmp(vi a,vi b){
  return a[1]<b[1];
}
int X(int x,int y){
  return abs(x-y);
}
vpii a[N];
void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = m+2;
    d.assign(n, inf);
    p.assign(n, -1);
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for (auto edge : a[v]) {
            int to = edge.first;
            int len = edge.second;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}
void solve(){
  cin>>n>>m;
  cin>>sx>>sy>>fx>>fy;
  S={sx,sy};F={fx,fy};
  vvi A(m),B(m);
  rep(i,0,m-1){
    cin>>x>>y;
    A[i]=vi{x,y,i+1};
  }
  B=A;
  sort(all(A));
  sort(all(B),cmp);
  // for(auto i:B)cout<<i[2]<<"\n";
  //0 12...m-1m m+1
  rep(i,0,m-2){
    a[A[i][2]].pb(A[i+1][2],X(A[i+1][0],A[i+0][0]));
    a[A[i+1][2]].pb(A[i][2],X(A[i+1][0],A[i+0][0]));
    a[B[i][2]].pb(B[i+1][2],X(B[i+1][1],B[i+0][1]));
    a[B[i+1][2]].pb(B[i][2],X(B[i+1][1],B[i+0][1]));
  }
  a[0].pb(m+1,add(X(S.F,F.F),X(S.S,F.S)));
  a[m+1].pb(0,add(X(S.F,F.F),X(S.S,F.S)));
  rep(i,0,m-1){
    a[0].pb(A[i][2],X(A[i][0],S.F));
    a[0].pb(A[i][2],X(A[i][1],S.S));
    a[A[i][2]].pb(0,X(A[i][1],S.S));
    a[A[i][2]].pb(0,X(A[i][0],S.F));
    a[m+1].pb(B[i][2],add(X(B[i][1],F.S),X(B[i][0],F.F)));
    a[m+1].pb(B[i][2],add(X(B[i][1],F.S),X(B[i][0],F.F)));
    a[B[i][2]].pb(m+1,add(X(B[i][1],F.S),X(B[i][0],F.F)));
    a[B[i][2]].pb(m+1,add(X(B[i][1],F.S),X(B[i][0],F.F)));
  }
  vi d,p;
  dijkstra(0,d,p);
  cout<<d[m+1];
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}