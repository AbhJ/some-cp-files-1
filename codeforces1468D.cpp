//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 05 in 04 : 38 : 26
//title - D_Firecrackers.cpp
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
int n, m, a, b, th, po, s[N];
int f(int pos){
	int max_time = 0;
	per(i, pos, 1){
		max_time = max(max_time, pos - i + 1 + s[i]);
	}
	//firecracker burst before police come to thief
	if(max_time <= po)
		return 1;
	return 0;
}
void solve(){
	cin >> n >> m >> a >> b;
	rep(i, 1, m)
		cin >> s[i];
	sort(s + 1, s + 1 + m);
	if(a < b){
		th = a - 1;
		po = b - 1;
	}
	if(a > b){
		th = n - a,
		po = n - b;
	}
	int l = 0, r = min(m, abs(a - b) - 1), mm;
	while(l < r){
		mm = (l + r + 1 >> 1);
		if(f(mm))
			l = mm;
		else
			r = mm - 1;
	}
	if(f(l)){
		cout << l;
	}
	else{
		cout << 0;
	}
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}