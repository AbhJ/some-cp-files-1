//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 28 in 19 : 39 : 14
//title - E_Traveler.cpp
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
#define all(x) x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, x[N], c[N], l[N], r[N], end_at_l[N], end_at_r[N], hatar_taka;
void solve(){
	cin >> n;
	rep(i, 1, n){
		cin >> x[i] >> c[i];
		if(l[c[i]] == 0 and r[c[i]] == 0){
			l[c[i]] = x[i],
			r[c[i]] = x[i];
			continue;
		}
		l[c[i]] = min(l[c[i]], x[i]);
		r[c[i]] = max(r[c[i]], x[i]);
	}
	rep(i, 1, n){
		hatar_taka = r[i] - l[i];
		if(l[i] == 0 and r[i] == 0){
			l[i] = l[i - 1];
			r[i] = r[i - 1];
			end_at_l[i] = end_at_l[i - 1];
			end_at_r[i] = end_at_r[i - 1];
			continue;
		}
		end_at_l[i] = min(abs(r[i - 1] - r[i]) + end_at_r[i - 1] + hatar_taka,
							abs(l[i - 1] - r[i]) + end_at_l[i - 1] + hatar_taka);
		end_at_r[i] = min(abs(r[i - 1] - l[i]) + end_at_r[i - 1] + hatar_taka,
							abs(l[i - 1] - l[i]) + end_at_l[i - 1] + hatar_taka);
	}
	cout << min(end_at_l[n] + abs(l[n]), end_at_r[n] + abs(r[n]));
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}