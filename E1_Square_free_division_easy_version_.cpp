//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 17 in 21 : 15 : 19
//title - E1_Square_free_division_easy_version_.cpp
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
const int N=1e7+10;
// const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, k, a[N], cnt = 1, sp[N];set<vi>S;
void Sieve()
{
    for(int i=2;i<N;i++)
    {
        if(sp[i] == 0)
        {
            for(int j=i;j<N;j+=i)
            {
                sp[j] = i;
            }
        }
    }
}
void solve(){
	cin >> n >> k;
	rep(i, 1, n)
		cin >> a[i];
	rep(i, 1, n){
		int s = sp[a[i]];
		vi v;
		while(a[i] > 1){
			int x = 0;
			while(a[i] % s == 0)a[i] /= s, x ^= 1;
			if(x & 1)
				v.pb(s);
			s = sp[a[i]];
		}
		if(S.count(v)){
			cnt++;
			S.clear();
		}
		S.insert(v);
	}
	cout << cnt;
	S.clear();
	cnt = 1;
}
int32_t main()
{
  ibs;cti;
  Sieve();
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}