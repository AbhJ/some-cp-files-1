//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 12 in 17 : 02 : 34
//title - D_White_Lines.cpp
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
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int prerow[N][N], posrow[N][N], precol[N][N], poscol[N][N], n, m, ans = inf, taka, pre_row[N][N], pre_col[N][N];bool row_te_pabo_kina[N][N], col_te_pabo_kina[N][N];
char a[N][N];
void solve(){
	cin >> n >> m;
	rep(i, 1, n)
		rep(j, 1, n)
			cin >> a[i][j];
	rep(i, 1, n)
		rep(j, 1, n){
			if(a[i][j] == 'B')
				prerow[i][j] = prerow[i][j - 1] + 1,
				precol[i][j] = precol[i - 1][j] + 1;
			else
				prerow[i][j] = prerow[i][j - 1],
				precol[i][j] = precol[i - 1][j];
		}
	int already = 0;
	rep(i, 1, n)
		already += (prerow[i][n] == 0) + (precol[n][i] == 0);
	ans = already;
	//will a row be empty on erasing m elements from i, j in the row i
	rep(i, 1, n)
		rep(j, 1, n - m + 1)
			row_te_pabo_kina[i][j] = ((prerow[i][j + m - 1] - prerow[i][j - 1] == prerow[i][n]) and prerow[i][n] != 0);
	//will a col be empty on erasing m elements from i, j in the col j
	rep(j, 1, n)
		rep(i, 1, n - m + 1)
			col_te_pabo_kina[i][j] = ((precol[i + m - 1][j] - precol[i - 1][j] == precol[n][j]) and precol[n][j] != 0);
	rep(i, 1, n)
		rep(j, 1, n)
			pre_row[i][j] = pre_row[i - 1][j] + row_te_pabo_kina[i][j],
			pre_col[i][j] = pre_col[i][j - 1] + col_te_pabo_kina[i][j];
	rep(i, 1, n - m + 1)
		rep(j, 1, n - m + 1)
			ans = max(ans, already + pre_row[i + m - 1][j] - pre_row[i - 1][j] + pre_col[i][j + m - 1] - pre_col[i][j - 1]);
	cout << ans;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}