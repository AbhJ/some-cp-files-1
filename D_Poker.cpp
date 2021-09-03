//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 27 in 17 : 44 : 56
//title - D_Poker.cpp
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
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = M_PI;
#define F first
#define S second
string s, t;int k, ta, ao, c[10], pre[10], ba[10], den, num, da[10], req;double ans;
void solve(){
	cin >> k >> s >> t;
	rep(i, 0, 3)
		c[s[i] - '0']++,
		ba[s[i] - '0']++;
	rep(i, 0, 3)
		c[t[i] - '0']++,
		da[t[i] - '0']++;
	rep(i, 1, 9)
		ta += (i * pow(10, ba[i])),
		ao += (i * pow(10, da[i]));
	// rep(i, 1, 9)
	// 	c[i] = k - c[i],
	// 	pre[i] = c[i] + pre[i - 1];
	rep(i, 1, 9){
		if(c[i] < k){
			int t = ta - (i * pow(10, ba[i]));
			c[i]++;
			ba[i]++;
			t += (i * pow(10, ba[i]));
			rep(j, 1, 9){
				if(c[j] < k){
					int a = ao - (j * pow(10, da[j]));
					c[j]++;
					da[j]++;
					a += (j * pow(10, da[j]));
					if(t > a){
						if(i == j){
							int cnt = k - c[j] + 2;
							num += (cnt * (cnt - 1));
						}
						else{
							num += ((k - c[i] + 1) * (k - c[j] + 1));
						}
					}
					if(i == j){
						int cnt = k - c[j] + 2;
						den += (cnt * (cnt - 1));
					}
					else{
						den += ((k - c[i] + 1) * (k - c[j] + 1));
					}
					da[j]--;
					c[j]--;
				}
			}
			ba[i]--;
			c[i]--;
		}
	}
	// den = ((9 * k - 8) * (9 * k - 8 - 1));
	// cout << num << " " << den;

	ans = (double)((double)num / (double)den);
	cout << setprecision(20) << ans;
	// cout << ta << " " << ao;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}