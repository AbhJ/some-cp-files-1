//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 05 in 00 : 47 : 07
//title - D_Cleaning_the_Phone.cpp
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
// const double Pi = M_PI;
#define F first
#define S second
int n, m, x[N], y[N], ans = inf;vi a, b;
void solve(){
	cin >> n >> m;a.clear(), b.clear();
	rep(i, 1, n){
		cin >> x[i];
	}
	rep(i, 1, n){
		cin >> y[i];
	}
	int prea = 0, preb = 0;
	rep(i, 1, n){
		if(y[i] == 1)
			b.pb(x[i]),
			preb += x[i];
		if(y[i] == 2)
			a.pb(x[i]);
	}
	sort(all(a));
	reverse(all(a));
	sort(all(b));
	reverse(all(b));
	int j = (int)b.size() - 1;
	rep(i, 0, (int)a.size() - 1){
		//i is not taken
		while(j != - 1 and prea + preb - b[j] >= m)
			j--, preb -= b[j + 1];
		if(prea + preb >= m)
			ans = min(ans, i * 2 + (j + 1));
		prea += a[i];
		if(prea + preb >= m)
			ans = min(ans, (i + 1) * 2 + (j + 1));
	}
	while(j != - 1 and prea + preb - b[j] >= m)
			j--, preb -= b[j + 1];
	if(prea + preb >= m)
		ans = min(ans, (int)a.size() * 2 + (j + 1));
	cout << (ans != inf ? ans : - 1);
	ans = inf;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}