//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 26 in 18 : 42 : 35
//title - Moons_and_umbrellas.cpp
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
int x, y, n, dp[N][2];
string s;
void solve(){
	cin >> x >> y >> s;
	n = s.length();
	s = '#' + s;
	dp[0][0] = dp[1][0] = 0;
	rep(i, 1, n){
		dp[i][1] = dp[i][0] = inf;
		if(s[i] == 'J'){
			dp[i][1] = min(dp[i - 1][0] + x, dp[i - 1][1]);
		}
		if(s[i] == 'C'){
			dp[i][0] = min(dp[i - 1][1] + y, dp[i - 1][0]);
		}
		if(s[i] == '?'){
			dp[i][0] = min(dp[i - 1][1] + y, dp[i - 1][0]);
			dp[i][1] = min(dp[i - 1][0] + x, dp[i - 1][1]);
		}
	}
	cout << min(dp[n][0], dp[n][1]);
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){xx++;cout<<"Case #"<<xx<<": ";solve();cout<<"\n";}
  return 0;
}