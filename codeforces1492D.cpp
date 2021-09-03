//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 24 in 16 : 57 : 18
//title - D_Genius_s_Gambit.cpp
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
int a, b, k;
void solve(){
	cin >> a >> b >> k;
	string A = string(b, '1') + string(a, '0');
	if(k == 0){
		cout << "Yes\n" << A << "\n" << A;
		return;
	}
	if(a + b - k < 2){
		cout << "No";
		return;
	}
	int cnt = b - 1 + min(a, k);
	string B = A;
	if(b - 1 == 0){
		cout << "No";
		return;
	}
	B[b - 1] = '0', B[cnt] = '1';
	int one = k - min(a, k);
	if(one == 0){
		cout << "Yes\n";
		cout << A << "\n" << B;
		return;
	}
	per(j, b - 2, 0)if(one != 0 and B[j + 1] == '0' and B[j] == '1'){
		one--;
		B[j] = '0', B[j + 1] = '1';
	}
	if(one == 0){
		cout << "Yes\n";
		cout << A << "\n" << B;
		return;
	}
	cout << "No";
	return;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}