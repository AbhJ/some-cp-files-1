//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 20 in 01 : 22 : 36
//title - A_Counting_Rectangles_is_Fun.cpp
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
const int N=41+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, m, q, dp[N][N][N][N], len, x, y, z, w, cnt[N][N], taka;char c[N][N];
void solve(){
	cin >> n >> m >> q;
	rep(i, 1, n)
		rep(j, 1, m){
			cin >> c[i][j];
			if(c[i][j] == '0')
				cnt[i][j] = cnt[i][j - 1] + 1;
		}
	rep(i, 1, n)
		rep(j, 1, m)
			rep(r, i, n)
				rep(c, j, m){
					dp[i][j][r][c] = dp[i][j][r - 1][c] + dp[i][j][r][c - 1] - dp[i][j][r - 1][c - 1];
					taka = 0;
					len = inf;
					per(zz, r, i)
						len = min(len, cnt[zz][c]),
						taka += min(len, c - j + 1);
					dp[i][j][r][c] += taka;
				}
	rep(i, 1, q){
		cin >> x >> y >> z >> w;
		cout << dp[x][y][z][w];
		cout << "\n";
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