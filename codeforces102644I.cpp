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
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,m,q,s,t,k,y;
int mul(int a,int b){
  return ((a)*(b))%M;
}
int add(int a,int b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
vvi p(vvi a,vvi b){
  vvi x(a.size(),vi(b[0].size()));
  rep(i,0,a.size()-1)
    rep(j,0,b[0].size()-1)
      rep(k,0,a[0].size()-1)
        x[i][j]=add(x[i][j],mul(a[i][k],b[k][j]));
  return x;
}
vvi a;
vvi mat[70];
//this return pow(A,x) where A is matrix
vvi matrix_power_final(int s, int x){
  vvi result(1,vi(n,0)),A=a;
  result[0][s-1]=1;
  int pow=1;
  while(x){
    if (x&1)result = p(result , mat[pow]);
    pow++;
    x = x / 2;
  }
  return result;
}
void solve(){
  cin>>n>>m>>q;
  a=vvi (n,vi(n,0));
  rep(i,1,m){
  	int x;
    cin>>x>>y;
    a[--x][--y]=1;
  }
  mat[1]=a;
  rep(i,2,32)mat[i]=p(mat[i-1],mat[i-1]);
  rep(i,1,q){
    cin>>s>>t>>k;
    auto b=matrix_power_final(s,k);
    cout<<b[0][t-1]<<"\n";
  }
}
int32_t main()
{
  // ibs;cti;
  solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}