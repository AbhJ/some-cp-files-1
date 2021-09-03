//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 16 in 23 : 19 : 52
//title - E_Accidental_Victory.cpp
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
int n, cnt = 0, koita = 0, c[N];pii a[N];vi b;
void solve(){
	cin >> n;cnt = 0;koita = 0;b.clear();fill(c + 1, c + 1 + n, 0);
	rep(i, 1, n)cin >> a[i].F, a[i].S = i, c[i] = a[i].F;b.clear();
	sort(a + 1, a + 1 + n);cnt = a[1].F;vi b{a[1].S};
	rep(i, 2, n){
		if(cnt < a[i].F)
			//dhue jabe
			b.clear();
		b.pb(a[i].S);
		cnt += a[i].F;
	}
	koita = (int)b.size();
	cout << koita << "\n";
	sort(all(b));
	rep(i, 1, (int)koita)cout << b[i - 1] << " ";
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}