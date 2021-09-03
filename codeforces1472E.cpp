//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 09 in 06 : 11 : 48
//title - E_Correct_Placement.cpp
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
int n;vector <tuple <int, int, int>> v;int ans [N];
void solve(){
	cin >> n;
	rep(i, 1, n)ans[i] = - 1;
	v.clear();
	rep(i, 1, n){
		int  x, y;
		cin >> x >> y;
		// ensure when width gets lowered, height has increased
		v.pb(tuple <int, int, int> {x, - y, i});
		v.pb(tuple <int, int, int> {y, - x, i});
	}
	sort(all(v));
	int least_width = inf, pos = - 1;
	for(auto &V: v){
		int h = get<0>(V), w = -get<1>(V), p = get<2>(V);
		if(w > least_width)ans[p] = pos;
		else if(w < least_width)least_width = w, pos = p;
	}
	rep(i, 1, n)cout << ans[i] << " ";
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}