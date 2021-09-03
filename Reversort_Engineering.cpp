//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 26 in 18 : 50 : 13
//title - Reversort_Engineering.cpp
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
#define all(x) x.rbegin(), x.rend()
#define rall(x) x.begin(), x.end()
using namespace std;
const int N=100;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, c, taka;vi b;
vi z;
int f(vi a){
	vi tmp = a;
	if(taka != 0)
		taka = 0;
	rep(i, 0, n - 1){
		rep(j, i, n - 1)
			if(a[j] == i + 1){
				reverse(a.begin() + i, a.begin() + j + 1);
				taka += j - i + 1;
				break;
			}
	}
	return taka - 1;
}
void solve(){
	// cin >> n >> c;
	b.resize(n, 0);
	iota(all(b), 1);
	do{
		if(f(b) == c){
			rep(i, 0, n - 1)
				cout << b[i] << " ";
			return;
		}
	}while(next_permutation(all(b)));
	cout << "IMPOSSIBLE";
}
// int dp[N][N];
int a[N];int ori_c;
void solve2(){
	cin >> n >> c;
	if(!(n>7)){
		solve();
	}
	else{
		vi tmp;int koita = 0, taka = 1;
		per(i, n - 1, 1){
			taka++;
			if(koita >= c - i + 1 - taka){
				int r = c - koita - i + 1;
				tmp.pb(r);
				rep(j, 1, i - 1)
					tmp.pb(1);
				koita = c;
				break;
			}
			koita += taka;
			tmp.pb(taka);
		}
		if(koita < c or c + 1 < n or tmp.empty() == 1){
			cout << "IMPOSSIBLE";
			return;
		}
		vi v(n);
		iota(rall(v), 1LL);
		int len = tmp.size();
		rep(i, 0, len - 1){
			reverse(v.begin() + n - i - 2, v.begin() + n - i + tmp[i] - 2);
		}
		for(auto &i: v)
			cout << i << " ";
		fill(a + 1, a + 1 + n, 0LL);
		ori_c = 0;
	}
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){xx++;cout<<"Case #"<<xx<<": ";solve2();cout<<"\n";}
  return 0;
}