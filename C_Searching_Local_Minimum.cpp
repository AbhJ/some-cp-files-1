//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 07 in 21 : 00 : 25
//title - C_Searching_Local_Minimum.cpp
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
const double Pi = 3.14159265;
#define F first
#define S second
int n, a[N], l, r, m, ans = - 1;
int f(int i){
	if(i == 0 or i == n + 1)return 0;
	if(a[i])return a[i];
	cout << "? " << i << "\n";
	cout.flush();
	cin >> a[i];
	cout.flush();
	return a[i];
}
void solve(){
	cin >> n;
	int l = 1, r = n, m;
	int cnt = 0;
	while(cnt++ < 100){
		int cur, bam = inf, dan = inf;
		m = (r + l)/2;
		cur = f(m);
		if(m > 1){
			bam = f(m - 1);
		}
		if(m < n){
			dan = f(m + 1);
		}
		if(cur < bam and cur < dan){
			cout<<"! "<< m <<"\n";
			cout.flush();
			return;
		}
		if(cur > bam)r = m - 1;
		else if(cur > dan)l = m + 1;
	}
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}