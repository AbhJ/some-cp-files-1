//Coded by Abhijay Mitra
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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, a[N];
const int K = 25;int ma[N][K + 1], mi[N][K + 1];
int mini(int l, int r){
    int j = log2(r - l + 1);
    int minimum = min(mi[l][j], mi[r - (1 << j) + 1][j]);
    return minimum;
}
int maxi(int l, int r){
    int j = log2(r - l + 1);
    int maximum = max(ma[l][j], ma[r - (1 << j) + 1][j]);
    return maximum;
}
void solve(){
    cin >> n;
    rep(i, 0, n - 1)cin >> a[i];
    for (int i = 0; i < n; i++)
        ma[i][0] = mi[i][0] = a[i];

    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            ma[i][j] = max(ma[i][j-1], ma[i + (1 << (j - 1))][j - 1]);
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            mi[i][j] = min(mi[i][j-1], mi[i + (1 << (j - 1))][j - 1]);
    int j = 0;
    // 0 j
    // j + 1 i - 1
    //i n - 1
    per(i, n - 1, 0){
        while(maxi(0, j) < maxi(i, n - 1) and j < i - 2)j++;
        if(!(j < i - 1))continue;
        if(maxi(0, j) != maxi(i, n - 1))continue;
        if(maxi(0, j) == mini(j + 1, i - 1) and i - 1 >= j + 1){
            cout << "YES\n" << j + 1 << " " << i - 1 - j - 1 + 1 << " " << n - 1 - i + 1;return;
        }
    }
    rep(i, 0, n - 1){
        //0 i
        //i + 1 m
        //m + 1 n - 1
        int l = i + 1, r = n - 1, m, a, b, c;
        a = maxi(0, i);
        while(r - l > 1){
            m = ((l + r) >> 1);
            b = mini(i + 1, m);
            c = maxi(m + 1, n - 1);
            if(b > a or a < c or (a == b and a == c))
                l = m;
            else r = m;
        }
        m = l;
        b = mini(i + 1, m);
        c = maxi(m + 1, n - 1);
        if(a == b and a == c and m - i - 1 + 1 != 0 and n - 1 - m - 1 + 1 != 0){
            cout << "YES\n" << i + 1 << " " << m - i - 1 + 1 << " " << n - 1 - m - 1 + 1;return;
        }
    }
    cout << "NO";
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}