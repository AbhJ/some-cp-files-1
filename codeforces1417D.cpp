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
const int N=1e4+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,a[N],sum,cnt;vvi v;
void f(int i,int j,int x){
  v.pb(vi{i,j,x});
  // cout<<i<<" "<<j<<"\n";
  a[i]-=(x*i);
  a[j]+=(x*i);
}
void solve(){
  cin>>n;v.clear();sum=0;cnt=0;
  rep(i,1,n)cin>>a[i];
  rep(i,2,n){
    if(a[i]%i){
      cnt++;
      int mod=a[i]%i;
      // remove mod from i and add to 1
      f(1,i,i-mod);
    }
    int x=a[i]/i;
    f(i,1,x);
    cnt++;
  }
  sum=accumulate(a+1,a+1+n,0);
  if(sum%n){cout<<-1;return;}
  rep(i,2,n){
    f(1,i,sum/n);
  }
  cout<<cnt+n-1<<"\n";
  for(auto &i:v){
    for(auto &j:i)cout<<j<<" ";
    cout<<"\n";
  }
}
int32_t main()
{
  ibs;cti;
  // solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}