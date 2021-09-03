//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 20 in 16 : 33 : 30
//title - D_Cut_and_Stick.cpp
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
#define all(x) x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, q, a[N], l, r, ans = - inf;
vi ind[N];
void solve(){
	cin >> n >> q;
	rep(i, 1, n)
		cin >> a[i],
		ind[a[i]].pb(i);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	vi an;
	rep(i, 1, q){
		cin >> l >> r;
		rep(j, 1, 50){
			int pos = uniform_int_distribution<int>(l,r)(rng);
			int cnt = upper_bound(all(ind[a[pos]]), r) - lower_bound(all(ind[a[pos]]), l);
			if(cnt <= (r - l + 2) / 2)
				ans = max(ans, 1LL);
			else
				ans = max(ans, 2 * cnt - r + l - 1);
		}
		an.pb(ans);
		ans = - inf;
	}
	for(auto &i: an)
		cout << i << "\n";
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}