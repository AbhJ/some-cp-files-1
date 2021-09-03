//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 05 in 20 : 06 : 29
//title - D_AB_Graph.cpp
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
const int N=1e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, m, in[N], out[N], T;char a[N][N];
void solve(){
	cin >> n >> m;
	rep(i, 1, n)rep(j, 1, n)cin >> a[i][j];
	//palindromic cycle of length divisor of m
	rep(i, 1, n)rep(j, 1, n){
		if(a[i][j] == a[j][i] and i != j){
			cout << "YES\n";
			rep(I, 1, m + 1)cout << (I & 1 ? i : j) << " ";
			return;
		}
	}
	if(m & 1){
		cout << "YES\n";
		rep(i, 1, m + 1)cout << (i & 1) + 1 << " ";
		return;
	}
	rep(I1, 1, 20)rep(I2, 1, 20)rep(I3, 1, 20){
		int i1 = rand() % n + 1;
		int i2 = rand() % n + 1;
		int i3 = rand() % n + 1;
		if(i1 != i2 and i2 != i3 and i3 != i1 and a[i1][i2] == a[i2][i3] and a[i3][i2] == a[i2][i1]){
			cout << "YES\n";
			rep(i, 0, m){
				int tmp = (i + (m % 4 == 0)) % 4 + 1;
				if(tmp == 1)cout << i1;
				if(tmp == 2)cout << i2;
				if(tmp == 3)cout << i3;
				if(tmp == 4)cout << i2;
				cout << " ";
			}
			return;
		}
	}
	cout << "NO";
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}