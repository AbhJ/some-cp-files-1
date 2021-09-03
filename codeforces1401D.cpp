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
const int N=3e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int mul(int a,int b){
  return ((a%M)*(b%M))%M;
}
int add(int a,int b){
  return ((a%M)+(b%M))%M;
}
/*
1
16

5 10

16 1

14 1

7 5

13 2

16 11

1 7

1 4

3 14

8 16

1 6

4 9

4 12

5 13

1 15

18

45893 9901 51229 15511 46559 28433 4231 30241 29837 34421 12953 6577 12143 52711 40493 89 34819 28571
*/
int n,x,y,m,ind;vvi a;vi sub,f;priority_queue<pii>q;
void dfs(int u,int par=-1){
  sub[u]=1;
  for(auto i:a[u])if(i!=par){
    dfs(i,u);
    sub[u]+=sub[i];
  }
  f[u]=sub[u]*(n-sub[u]);
}
void solve(){
  cin>>n;a.clear();a.resize(n+10);q=priority_queue<pii>();int ans=0;
  sub=vi(n+10,1),f=vi(n+10,0);
  rep(i,1,n-1){
    cin>>x>>y;
    a[x].pb(y),a[y].pb(x);
  }
  cin>>m;vi p(m);dfs(1);
  ans=0;rep(i,2,n)q.push({f[i],i});
  rep(i,0,m-1)cin>>p[i];
  sort(all(p));
  vi done(n+1,1);
  while(p.empty()==0){
    pii z=q.top();q.pop();int i=z.S;
    done[i]=mul(done[i],p.back());p.pop_back();
    if((int)p.size()>=1+(int)q.size())q.push(z);
  }
  rep(i,1,n)ans=add(ans,mul(done[i],f[i]));
  cout<<ans;
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