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
int a,b,c;vpii v;
bool f(){
  cin>>a;
  cout.flush();
  exit(0);
}
void solve(){
  cin>>a>>b>>c;
  v=vpii{{a,1},{b,2},{c,3}};
  sort(all(v));
  a=v[0].F,b=v[1].F,c=v[2].F;
  if(a==b or b==c){
    cout<<"First"<<"\n";
    cout.flush();
    f();
  }
  cout<<"First"<<"\n";
  cout.flush();
  cout<<2*c-b-a<<"\n";
  cout.flush();
  int x;
  cin>>x;
  if(x==v[0].S){
    cout<<c-b<<"\n";
    cout.flush();
    f();
  }
  if(x==v[1].S){
    cout<<c-a<<"\n";
    cout.flush();
    f();
  }
  c=3*c-a-b;
  cout<<2*c-b-a<<"\n";
  cout.flush();
  cin>>x;
  if(x==v[0].S){
    cout<<c-b<<"\n";
    cout.flush();
    f();
  }
  if(x==v[1].S){
    cout<<c-a<<"\n";
    cout.flush();
    f();
  }
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