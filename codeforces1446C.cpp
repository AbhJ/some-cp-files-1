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
int n;vi a;
int f(vi &a){
    int n = a.size();
    if(a.empty() == 1)return 0;
    if(a.back() == 0)return a.size();
    int hig = 0;
    rep(i, 0, n - 1){
        hig = max(hig, (int)log2(a[i]));
    }
    vi l, r;
    rep(i, 0, n - 1){
        if((int)log2(a[i]) < hig)
         l.pb(a[i]);
        else
         r.pb(a[i] ^ (1 << (int)log2(a[i])));
    }
    if(!(l.size() < r.size()))
        swap(l, r);
    a = vi();
    if(l.size() == 0)
        return f(r);
    return 1 + max(f(l), f(r));
}
void solve(){
    cin >> n;a.resize(n);
    rep(i, 1, n)
        cin >> a[i - 1];
    sort(all(a));
    cout << (a.size() - f(a));
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}