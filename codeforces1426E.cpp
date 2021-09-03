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
int n,x,y,z,a,b,c;
//x y z
//a b c
//R P S
int f(){
  vi A{x,y,z},B{a,b,c};
  int ans=inf;
  vvi v={{0,0},{1,1},{2,2},{0,1},{1,2},{2,0}};
  sort(all(v));
  do{
    auto X=A,Y=B;
    for(auto i:v){
      int rem=min(X[i[1]],Y[i[0]]);
      X[i[1]]-=rem,Y[i[0]]-=rem;
    }
    ans=min({ans,min(X[0],Y[1])+min(X[1],Y[2])+min(X[2],Y[3%3])});
    // cout<<X[0]<<" "<<X[1]<<" "<<X[2]<<"\n";
  }while(next_permutation(all(v)));
  return ans;
}
int g(){
  return min(x,b)+min(y,c)+min(z,a);
}
void solve(){
  cin>>n>>x>>y>>z>>a>>b>>c;
  cout<<f()<<" "<<g();
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}