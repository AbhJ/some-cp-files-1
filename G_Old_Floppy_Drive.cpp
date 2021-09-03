//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 17 in 15 : 29 : 59
//title - G_Old_Floppy_Drive.cpp
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
int n, a[N], p[N], s[N], x, cost, ans, m, ma;
int f(int v){
	int l = 0, r = n, m;
	assert(v >= 0);
	while(r - l > 1){
		m = ((l + r) >> 1);
		if(p[m] >= v)
			r = m;
		else
			l = m;
	}
	return l;
}
void solve(){
	cin >> n;
	ans = cost = x = p[0] = s[0] = ma = 0;
	cin >> m;
	rep(i, 1, n)
		cin >> a[i];
	rep(i, 1, n)
		s[i] = s[i - 1] + a[i],
		ma = max(ma, s[i]),
		p[i] = ma;
	rep(i, 1, m){
		cin >> x;
		int full_rotat = max((s[n] == 0 ? inf :((x - ma + s[n] - 1) / s[n])), 0LL);
		if(s[n] <= 0){
			if(x > p[n])
				cout << - 1;
			else
				cout << f(x);
		}
		else
			cout << ((full_rotat * n) + f(x - (full_rotat * s[n])));
		cout << " ";
	}
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}