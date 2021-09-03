//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 25 in 23 : 27 : 30
//title - Subtransmutation.cpp
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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int pos = uniform_int_distribution<int>(l,r)(rng);
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
int a[N], value[N];
int n, A, B, ans, c, FF, l, r, m;
void solve(){
            cin >> n >> A >> B;
            rep(i, 1 , n)
                	cin >> value[i];
            ans = inf;
            l = 1; r = 100;
            while(r >= l){
                  m = ((l + r) >> 1);
                  memset(a, 0, sizeof(a));
                  a[m] = 1;
                  per(i, m, n + 1){
                        a[max(i - B, 0LL)] += a[i];
                        a[max(i - A, 0LL)] += a[i];
                        a[i] = 0;
                  }
                  FF = 0;
                  per(i, n, 1){
                        if(value[i] > a[i]){
                            FF = 1;
                            goto F;
                        }
                        a[max(i - B, 0LL)] += a[i] - value[i];
                        a[max(i - A, 0LL)] += a[i] - value[i];
                  }
				  F:;
                  if(FF)
                        l = m + 1;
                  else
                        ans = m,
                        r = m - 1;
            }
            if(ans == inf)
				cout << "IMPOSSIBLE";
			else
				cout << ans;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){xx++;cout<<"Case #"<<xx<<": ";solve();cout<<"\n";}
  return 0;
}