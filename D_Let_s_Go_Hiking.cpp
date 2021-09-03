//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 13 in 09 : 34 : 00
//title - D_Let_s_Go_Hiking.cpp
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
int n, a[N], x, l;vector<tuple<int, int, int>> v;
map<int, int>m;
void solve(){
	cin >> n;
	rep(i, 1, n)
		cin >> a[i];
	l = 1;
	x = (a[2] > a[1]);
	rep(i, 3, n){
		if((a[i] > a[i - 1]) != x){
			v.pb(l, i - 1, x);
			l = i - 1;
			x ^= 1;
		}
	}
	v.pb(l, n, x);
	// for(auto [L, R, X]: v){
	// 	cout << L << " " << R << " " << X << "\n";
	// }
	for(auto [L, R, X]: v)
		m[R - L + 1]++;
	// if(m.rbegin() -> S & 1){
	// 	cout << 0;
	// 	return;
	// }
	int len = m.rbegin() -> F, cnt = 0, cnt1 = 0;
	int l1 = - 1, l2 = - 1, l3 = - 1;
	for(auto [L, R, X]: v){
		if(l1 != - 1){
			if(R - L + 1 == len and l2 - l1 + 1 == len and ((l2 - l1 + 1) & 1)){
				cnt++;
				cnt1 += (l3 == 1 and X == 0);
			}
			// else if(R - L + 1 == len and (len & 1)){
			// 	cout << 0;
			// 	return;
			// }
		}
		l1 = L, l2 = R, l3 = X;
	}
	if(cnt == 1 and cnt1 == 1)
		cout << cnt;
	else
		cout << 0;
	return;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}