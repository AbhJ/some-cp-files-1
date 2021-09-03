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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, a[N];
int X(int l, int r){
    cout << "XOR ";
    cout << l << " " << r << "\n";
    cout.flush();
    int x;cin >> x;
    return x;
}
int A(int l, int r){
    cout << "AND ";
    cout << l << " " << r << "\n";
    cout.flush();
    int a;cin >> a;
    return a;
}
else if(v[0].empty() == 0){
        b = v[0].back();
        int aa = O(1, b);
        a[1] = aa;
        c = 3;
    }
void solve(){
    cin >> n;
    // a[1], a[2], a[3] 5 op + n - 3
    int and1 = A(1, 2), and2 = A(2, 3), and3 = A(1, 3);
    int xor1 = X(1, 2), xor2 = X(2, 3), xor3 = xor1 ^ xor2;
    int sum1 = xor1 + 2 * and1;
    int sum2 = xor2 + 2 * and2;
    int sum3 = xor3 + 2 * and3;
    int a_minus_c = sum1 - sum2;
    int c = ((sum3 - a_minus_c) / 2);
    int aa = a_minus_c + c;
    int b = sum1 - aa;
    a[3] = c;
    rep(i, 3, n - 1){
        int x = X(i, i + 1);
        a[i + 1] = a[i] ^ x;
    }
    cout << "! ";
    cout << aa <<" " << b << " " << c << " ";
    rep(i, 4, n)cout << a[i] << " ";
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}