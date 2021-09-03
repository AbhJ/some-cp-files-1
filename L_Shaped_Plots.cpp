//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 21 in 09 : 37 : 44
//title - L_Shaped_Plots.cpp
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
// const double Pi = M_PI;
#define F first
#define S second
int n, m, a[N][N], l[N][N], r[N][N], u[N][N], d[N][N];
int ok(int x, int y){
	return (x <= n and y <= m and x >= 1 and y >= 1 and a[x][y] == 1);
}
void solve(){
	cin >> n >> m;int cnt = 0;
	memset(l, 0, sizeof l);
	memset(r, 0, sizeof r);
	memset(u, 0, sizeof u);
	memset(d, 0, sizeof d);
	rep(i, 1, n)
		rep(j, 1, m)
			cin >> a[i][j];
	 rep(i, 1, n){
                  rep(j, 1, m){
                        if(a[i][j]==1){
                              l[i][j]=l[i][j-1]+1;
                        }
                        else{l[i][j]=0;}
                  }
            }
            rep(i, 1, n){
                  per(j, m, 1){
                        if(a[i][j]==1){
                              r[i][j]=r[i][j+1]+1;
                        }
                        else{r[i][j]=0;}
                  }
            }
            rep(j, 1, m){
                  rep(i, 1, n){
                        if(a[i][j]==1){
                              u[i][j]=u[i-1][j]+1;
                        }
                        else{u[i][j]=0;}
                  }
            }
            rep(j, 1, m){
                  per(i, n, 1){
                        if(a[i][j]==1){
                              d[i][j]=d[i+1][j]+1;
                        }
                        else{d[i][j]=0;}
                  }
            }
            rep(i, 1, n){
                  rep(j, 1, m){
                        cnt += max( min(r[i][j] >> 1, u[i][j]) - 1, 0LL);
                        cnt += max( min(u[i][j] >> 1, r[i][j]) - 1, 0LL);
                        cnt += max( min(l[i][j] >> 1, u[i][j]) - 1, 0LL);
                        cnt += max( min(u[i][j] >> 1, l[i][j]) - 1, 0LL);
                        cnt += max( min(r[i][j] >> 1, d[i][j]) - 1, 0LL);
                        cnt += max( min(d[i][j] >> 1, r[i][j]) - 1, 0LL);
                        cnt += max( min(l[i][j] >> 1, d[i][j]) - 1, 0LL);
                        cnt += max( min(d[i][j] >> 1, l[i][j]) - 1, 0LL);
                  }
            }
	cout << cnt;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){xx++;cout<<"Case #"<<xx<<": ";solve();cout<<"\n";}
  return 0;
}