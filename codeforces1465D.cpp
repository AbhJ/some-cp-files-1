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
string s;int x, y, ans;
void solve(){
  cin >> s >> x >> y;
  int n = s.length();
  s = '#' + s;
  int cost = 0, z = 0, o = 0, ques = 0, tmp = 0;
  if(x > y){
    rep(i, 1, n){
        if(s[i] == '1'){
          s[i] = '0';
          continue;
        }
        if(s[i] == '0'){
          s[i] = '1';
          continue;
        }
        ques++;
    }
    x ^= y;
    y ^= x;
    x ^= y;
  }
  else{
    rep(i, 1, n)
      ques += s[i] == '?';
  }
  int default_taka = 0;
  rep(i, 1, n){
    z += (s[i] == '0');
    o += (s[i] == '1');
    if(s[i] == '1')
      default_taka += x * z;
    if(s[i] == '0')
      default_taka += y * o;
  }
  int ans = inf, to = 0, tz = 0, ques_taka = 0;
  if(ques == 0){
    cout << default_taka;
    return;
  }
  rep(i, 1, n){
    tz += (s[i] == '0');
    to += (s[i] == '1');
    if(s[i] == '?')
      ques_taka += tz * x + (z - tz) * y;
  }
  ans = min(ans, ques_taka + default_taka); 
  to = tz = 0;
  rep(i, 1, n){
    if(s[i] == '0')tz++;
    if(s[i] == '1')to++;
    if(s[i] == '?'){
      tmp++;
      ans = min(ans, default_taka + ques_taka + (tmp - 1) * (ques - tmp + 1) * x);
      ques_taka += to * y + (o - to) * x;
      ques_taka -= tz * x + (z - tz) * y;
    }
  }
  cout << min(ans, default_taka + ques_taka);
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}