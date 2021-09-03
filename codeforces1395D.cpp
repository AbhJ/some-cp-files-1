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
int n,d,m,a[N];vi big,small;
int n1,n2,ma,ans;
int f(int cnt){
  int day=(cnt-1)*(d+1)+1;
  int rem=min(n-day,n2);
  if(cnt==0){ma=max(ma,small[n2-1]);return 1;}
  if(rem==0){ma=max(ma,big[cnt-1]);return 1;}
  if(rem<0){return 0;}
  int val=big[cnt-1]+small[min(n2-1,rem-1)];
  ma=max(ma,val);
  return val==ma;
}
void solve(){
  cin>>n>>d>>m;
  rep(i,1,n)cin>>a[i];
  rep(i,1,n){
    if(a[i]>m)big.pb(a[i]);
    else small.pb(a[i]);
  }
  if(big.empty()==0)sort(all(big));
  if(small.empty()==0)sort(all(small));
  if(big.empty()==0)reverse(all(big));
  if(small.empty()==0)reverse(all(small));
  n1=big.size(),n2=small.size();
  if(big.empty()==0)rep(i,1,big.size()-1)big[i]+=big[i-1];
  if(small.empty()==0)rep(i,1,small.size()-1)small[i]+=small[i-1];
  int l=(n1+d)/(1+d),r=n1;
  // while(r-l>1){
  //   int m=l+r>>1;
  //   if(f(m))l=m;
  //   else r=m;
  // }
  rep(i,l,r)f(i);
  cout<<ma;
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