//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 27 in 20 : 30 : 46
//title - Sed_Max.cpp
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
const double Pi = M_PI;
#define F first
#define S second
int n, a[N], ma, MA, SE, se, p;set<int>s;map<int, int>f;
void solve(){
	cin >> n;
	f.clear();
	rep(i, 1, n)
		cin >> a[i];
	stack<int>S;
    /* Push the first element into the stack. */
    S.push(1);
    rep(i, 2, n){
        /* While the array is not empty and the current element is greater than the top stack element. */
        while(!S.empty() && a[S.top()] < a[i]) {
            /* Print the greater element. */
            f[a[S.top()]] = i;
            S.pop();
        }
        /* Push the current element. */
        S.push(i);
    }
	s.clear();
	rep(i, 1, n){
		ma = a[i];
		se = - inf;
		rep(j, i + 1, n){
			if(a[j] >= ma)
				se = ma,
				ma = a[j];
			else
				se = max(se, a[j]);
			s.insert(ma - se);
			if(f.count(se) == 1)
				j = max(f[se] - 1, j);
		}
	}
	cout << (int)(s.size());
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}