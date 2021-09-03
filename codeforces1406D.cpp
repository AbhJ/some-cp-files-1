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
const int N=1e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,q,a[N],l,r,x,dif,d[N];
void solve(){
  cin>>n;
  rep(i,1,n)cin>>a[i];
  dif=a[1];
  d[1]=dif;
  rep(i,2,n){
    d[i]=a[i]-a[i-1];
    dif+=max(d[i],0LL);
  }
  if(abs(dif)&1^1)cout<<(dif)/2;
  else cout<<(dif+1)/2;
  //maximum number appearing
  cin>>q;
  while(q--){
    cout<<"\n";
    cin>>l>>r>>x;
    //increase on l and r
    if(l==1){
      dif-=(d[l]);
      d[l]+=x;
      dif+=(d[l]);
    }
     else{ dif-=max(0LL,d[l]),
      d[l]+=x,
      dif+=max(0LL,d[l]);
      }
    if(r!=n)
      dif-=max(0LL,d[r+1]),
      d[r+1]-=x,
      dif+=max(0LL,d[r+1]);
    if(abs(dif)&1^1)cout<<(dif)/2;
    else cout<<(dif+1)/2;
  }
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}