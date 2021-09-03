//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 16 in 19 : 00 : 57
//title - E_A_Bit_Similar.cpp
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
int n, k, load[1 << 20];
string s;
void solve(int t){
	cin >> n >> k;
	cin >> s;
	rep(i, 0, n - 1)s[i] = ((s[i] - '0') ^ 1) + '0';
	int cnt_of_substring = n - k + 1;
	int K = min(20LL, k);
	int min_allowed_zero_prefix = max(k - 20LL, 0LL);
	int koita_zero_pref_continuous = 0;
	rep(i, 0, n - K){
		if(koita_zero_pref_continuous >= min_allowed_zero_prefix)load[stoull(s.substr(i, K), 0, 2)] = t;
		koita_zero_pref_continuous += (s[i] == '0');
		koita_zero_pref_continuous = (s[i] == '1' ? 0 : koita_zero_pref_continuous);
	}
	int F = - inf;
	rep(i, 0, (1 << K) - 1){
		if(load[i] != t){
			if(F == - inf)F = i;
			break;
		}
	}
	if(F == - inf){
		cout << "NO";
	}
	else{
		cout << "YES\n";
		cout << string(min_allowed_zero_prefix, '0');
		per(i, k - min_allowed_zero_prefix, 1)cout << (1 & (F >> (i - 1)));
	}
}
int32_t main()
{
  ibs;cti;
  fill(load, load + (1 << 20) - 1 + 1, - 1);
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve(t);cout<<endl;}
  return 0;
}