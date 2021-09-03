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
using vi = std::vector<double>;
using vvi = std::vector<vi>;
using pii = std::pair<double,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, d, a[N], Le, Ri;double l, r, m;
int f(double av){
	double pr = 0;
	vpii pre(n + 1, pii(0LL, 0LL));
	rep(i, 1, n){
		pr += (double)a[i] - av;
		pre[i] = pii{pr, i};
		if(i != 1 and pr > pre[i - 1].F)
			pre[i] = pre[i - 1];
		if(i - d >= 0 and pr >= pre[i - d].F){
			Ri = i;
			Le = pre[i - d].S + 1;
			return 1;
		}
	}
	return 0;
}
void solve(){
	cin >> n >> d;
	rep(i, 1, n)
		cin >> a[i];
	l = 0, r = inf;
	while(r > l){
		m = (l + r) / 2.0;
		if(f(m))
			l = m;
		else
			r = m - 1e-14;
	}
	f(l);
	cout << Le << " " << Ri;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}