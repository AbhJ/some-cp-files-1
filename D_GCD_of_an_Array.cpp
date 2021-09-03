//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 06 in 23 : 30 : 18
//title - D_GCD_of_an_Array.cpp
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
// #define int long long int
#define ll long long int
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
const int N=2e5+10;
// const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, a[N], x, y, q;vvi A;ll cnt = 1;
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
ll mul(ll a,ll b){
  return ((a)*(b))%M;
}
ll add(ll a,ll b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
multiset<int>mult[N];
// int sp[N];
vector<map<int, int>>f;
void up(int i, int j, int cn){
	int in = 0;
	if((int)mult[j].size() == (int)n){
		in = *mult[j].begin();
	}
	if(f[i].count(j) != 0){
		mult[j].erase(mult[j].find(f[i][j]));
	}
	f[i][j] += cn;
	mult[j].insert(f[i][j]);
	if((int)mult[j].size() == (int)n)while(*mult[j].begin() != in++){
		cnt = mul(cnt, j);
	}
}
void solve(){
	cin >> n >> q;
	f.resize(n + 1);
	rep(i, 1, n){
		scanf("%d", &a[i]);
	}
	rep(i, 1, n){
		for (int j = 2; j * j <= a[i]; j++) {
			int cnt1 = 0;
			while (a[i] % j == 0) a[i] /= j, cnt1++;
			if (cnt1) up(i, j, cnt1);
		}
		if (a[i] != 1) up(i, a[i], 1);
	}
	rep(i, 1, q){
		scanf("%d%d", &x, &y);
		for (int j = 2; j * j <= y; j++) {
			int cnt1 = 0;
			while (y % j == 0) y /= j, cnt1++;
			if (cnt1) up(x, j, cnt1);
		}
		if (y != 1) up(x, y, 1);
		printf("%lld\n", cnt);
	}
}
int32_t main()
{
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}