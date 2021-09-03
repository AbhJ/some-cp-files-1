//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 04 in 16 : 01 : 10
//title - A_Maximum_Average_Segment.cpp
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
using vi = std::vector<double>;
using vvi = std::vector<vi>;
using pii = std::pair<double,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x) x.rbegin(), x.rend()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, d, a[N], b[N], Le, Ri, k;double l, r, m;
int f(double rat){
	vi v;
	rep(i, 1, n)
		v.pb(a[i] - rat * b[i]);
	sort(all(v));
	double taka = 0;
	rep(i, 0, k - 1)
		taka += v[i];
	return taka >= 0;
}
void solve(){
	cin >> n >> k;
	//su(a[i] - x[b[i]]) >= 0
	rep(i, 1, n)
		cin >> a[i] >> b[i];
	l = 0, r = inf;
	while(r > l + 5e-7){
		m = (l + r + 5e-7) / 2.0;
		if(f(m))
			l = m;
		else
			r = m - 5e-7;
	}
		cout << fixed << setprecision(6) << l;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}