//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 27 in 20 : 18 : 31
//title - D_Strange_Definition.cpp
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
const int N=3e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, a[N], q, w, z, sp[4 * N], tot, Z;map<int, vi> A;
// int t[N][100];
int ans[N];
void Sieve()
{
    for(int i=2;i< 4 * N;i++)
    {
        if(sp[i] == 0)
        {
            for(int j=i;j< 4 * N;j+=i)
            {
                sp[j] = i;
            }
        }
    }
}
void solve(){
	cin >> n;z = 0, tot = 0, Z = 0;
	rep(i, 1, n)cin >> a[i];
	A.clear();
	vi one;
	rep(i, 1, n){
		int p = sp[a[i]];
		int x = a[i];
		int cnt = 1;
		while((p == 0 or p == 1) == 0){
			int y = 0;
			while(x % p == 0)x /= p, y ^= 1;
			if(y == 1)cnt *= p;
			p = sp[x];
		}
		if(cnt == 1)one.pb(i);
		A[cnt].pb(i);
	}
	for(auto &[x, y]: A){
		z = max(z, (int)y.size());
		if((int)y.size() & 1)Z = max(Z, (int)y.size());
		else if(x != 1)tot += (int)y.size();
	}

	cin >> q;
	rep(i, 1, q){
		cin >> w;
		if(w == 0)cout << z;
		else cout << max(tot + (int)one.size(), Z);
		cout << "\n";
	}
}
int32_t main()
{
  ibs;cti;
  Sieve();
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();}
  return 0;
}