//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 01 in 12 : 40 : 08
//title - D_Stylish_clothes.cpp
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
#include <bits/stdc++.h>
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
const int N=1e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n1, n2, n3, n4, l1 = 1, l2 = 1, l3 = 1, l4 = 1, a[N], b[N], c[N], d[N], mi, ans = inf, dis;vi V;
int di(){
	vi v{a[l1], b[l2], c[l3], d[l4]};
	return *max_element(all(v)) - *min_element(all(v));
}
int mm(){
	vi v{a[l1], b[l2], c[l3], d[l4]};
	return *min_element(all(v));
}
void solve(){
	cin >> n1;
	rep(i, 1, n1)
		cin >> a[i];
	cin >> n2;
	rep(i, 1, n2)
		cin >> b[i];
	cin >> n3;
	rep(i, 1, n3)
		cin >> c[i];
	cin >> n4;
	rep(i, 1, n4)
		cin >> d[i];
	sort(a + 1, a + 1 + n1);
	sort(b + 1, b + 1 + n2);
	sort(c + 1, c + 1 + n3);
	sort(d + 1, d + 1 + n4);
	while(l1 != n1 + 1 and l2 != n2 + 1 and l3 != n3 + 1 and l4 != n4 + 1){
		dis = di();
		if(ans > dis)
			ans = dis, V = vi{a[l1], b[l2], c[l3], d[l4]};
		mi = mm();
		if(a[l1] == mi)
			l1++;
		else if(b[l2] == mi)
			l2++;
		else if(c[l3] == mi)
			l3++;
		else if(d[l4] == mi)
			l4++;
		else
			assert(0);
	}
	for(auto &i: V)
		cout << i << " ";
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}