//Coded by Abhijay Mitra (AbJ) on 2021 / 05 / 02 in 21 : 52 : 00
//title - D_Phoenix_and_Socks.cpp
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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int pos = uniform_int_distribution<int>(l,r)(rng);
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
using namespace std;
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int l[N], r[N], n, L, R, fl[N], fr[N];
void f(){
	rep(i, 0, L - 1)
		cin >> l[i],
		fl[l[i]]++;
	rep(i, 0, R - 1)
		cin >> r[i],
		fr[r[i]]++;
}
void solve(){
	cin >> n >> L >> R;
	if(R <= L){
		swap(l, r);
		swap(fl, fr);
		f();
		swap(l, r);
		swap(fl, fr);
		swap(L, R);
	}
	else f();
	rep(i, 0, n){
		int tmp = min(fl[i], fr[i]);
		fl[i] -= tmp, fr[i] -= tmp, R -= tmp, L -= tmp;
	}
	vi v;
	rep(i, 0, n){
		int tmp = min(((R - L) >> 1LL), fr[i] >> 1LL);
		R -= (tmp << 1);
		v.pb(tmp);
	}
	v.pb(R);
	cout << accumulate(all(v), 0LL);
	rep(i, 0, n)
		fr[i] = fl[i] = 0;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}