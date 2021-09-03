//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 20 in 23 : 47 : 20
//title - D_Ghd.cpp
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
int n, a[N], g = 1, cnt, zzz = 14;
void check(int fac){
	if(fac <= g)
		return;
	rep(i, 1, n)
		if(a[i] % fac == 0){
			cnt++;
			if(cnt >= n / 2){
				assert(fac > g);
				g = fac;
				cnt = 0;
				return;
			}
		}
	assert(fac > g);
	cnt = 0;
	return;
}
void solve(){
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin >> n;
	rep(i, 1, n)
		cin >> a[i];
	//high chance factor is a factor of a[z]
	vi s;
	map<int, int>m;
	rep(i, 1, zzz){
		int pos = uniform_int_distribution<int>(1, n)(rng);
		int z = a[pos];
		if(1.0 * clock() / CLOCKS_PER_SEC > 1.66)
			break;
		s.clear();
		m.clear();
		int zz = sqrt(z);
		rep(j, 1, zz)
			if(z % j == 0)
				s.pb(j),
				s.pb(z / j);
		res(s);
		rep(j, 1, n)
			m[__gcd(a[j], z)]++;
		for(auto &j: s)if(g < j){
			for(auto &k: m)
				if(k.F % j == 0)
					cnt += k.S;
			if(2 * cnt >= n)
				g = j;
			cnt = 0;
		}
	}
	cout << g;
	g = 1;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}