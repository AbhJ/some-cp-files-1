//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 12 in 00 : 29 : 44
//title - B_Max_and_Mex.cpp
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
int n, a[N], cnt, k, vis[N];
void solve(){
	cin >> n >> k;
	rep(i, 1, n){
		cin >> a[i];
		if(a[i] < N)
			vis[a[i]] = 1;
	}
	a[- 1] = 0;cnt = 0;
	sort(a + 1, a + 1 + n);
	if(a[n] != n - 1){
		int m = - 1;
		rep(i, m + 1, n + cnt){
			if(vis[i] != 1){
				m = i;
				break;
			}
		}
		if(((m + a[n] + 1) >> 1) < N and vis[(m + a[n] + 1) >> 1]){
			cout << n;
		}
		else{
			cout << n + min(1LL, k);
		}
	}
	else
		cout << k + n;
	rep(i, 0, n + cnt)
		vis[i] = 0;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}