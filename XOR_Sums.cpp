//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 12 in 21 : 53 : 17
//title - XOR_Sums.cpp
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
const int N=1e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
int mul(int a,int b){
  return ((a % M)*(b % M))%M;
}
int modinv(int x) { return powM(x,M-2); }
void fft(vector<int> & a, bool invert) {
    int n = a.size();
    int root = powM(3,(M-1)/n);
    int root_1 = modinv(root);

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < n; i <<= 1)
            wlen = wlen * wlen % M;

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = a[i+j+len/2] * w % M;
                a[i+j] = u + v < M ? u + v : u + v - M;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + M;
                w = w * wlen % M;
            }
        }
    }

    if (invert) {
        int n_1 = modinv(n);
        for (int & x : a)
            x = x * n_1 % M;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<int> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);


    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] = fa[i] * fb[i] % M;
    fft(fa, true);

    return fa;
}
int add(int a,int b){
  return (((a % M) + (b % M)))%M;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
int f[N],b[N];
void calc_fact(){
  f[0]=b[0]=1;
  rep(i,1,N-1){
    f[i]=mul(f[i-1],i);
    b[i]=powM(f[i],M-2);
  }
}
int C(int n,int r){
  assert(n<N);assert(r<N);
  if(r>n or r < 0 or n < 0)return 0;
  return (f[n]*mul(b[r],b[n-r])%M)%M;
}
int a[N], n, q, m, dp[N][2], p[N];
void solve(){
	cin >> n;
	rep(i, 1, n)
		cin >> a[i];
	int r = 30;
	rep(i, 1, n){
		rep(j, 0, r){
			dp[j][(a[i] >> j) & 1LL]++;
		}
	}
	rep(i, 0, r){
		vi A(dp[i][1] + 1), B(dp[i][0] + 1);
		if(dp[i][1] == 0)continue;
		rep(j, 0, dp[i][1]){
			if(j & 1)
				A[j] = C(dp[i][1], j);
		}
		rep(j, 0, dp[i][0])
			B[j] = C(dp[i][0], j);
		vi C = multiply(A, B);
		rep(j, 0, n)
			p[j] = add(p[j], mul(C[j], powM(2, i)));
	}
	rep(I, 1, n){
		p[I] = add(p[I - 1], p[I]);
	}
	cin >> q;
	while(q--){
		cin >> m;
		cout << p[m] << "\n";
	}
}
int32_t main()
{
  ibs;cti;
  calc_fact();
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();}
  return 0;
}