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
int n, k, a[N], b[N];
vi d(N, inf);
int LIS(int l, int r, int mi = -inf, int ma = inf){
   vector<int> lis;
   // make both < = instead of < if increasing ans not strictly increasing
   //optionally min and max can be passed
   for (int j = l; j <= r; ++j) if (mi <= a[j] && a[j] <= ma) {
     auto pos = upper_bound(lis.begin(), lis.end(), a[j]);
     if (pos == lis.end()) lis.push_back(a[j]);
     else *pos = a[j];
   }
   return (lis.size());
}
void solve(){
  int ans = 0;
  cin >> n >> k;
  rep(i, 1, n)cin >> a[i];
  rep(i, 1, n)a[i] = a[i] - i;
  a[0] = -inf;
  a[n + 1] = inf;
  rep(i, 1, k)cin >> b[i];
  b[0] = 0;b[k + 1] = n + 1;
  rep(i, 0, k){
    int left = b[i];
    int right = b[i + 1];
    ans += (right - 1) - (left + 1) + 1 - LIS(left + 1, right - 1, a[left], a[right]);
  }
  rep(i, 0, k - 1){
    if(a[b[i]] > a[b[i + 1]]){
      cout << -1;
      return;
    }
  }
  cout << ans;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}