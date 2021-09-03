//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 22 in 19 : 11 : 36
//title - Mission_Impossible_3.cpp
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
const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
vector<int> ThreeEqualParts(vector<int> A)
{
    int imp[] = {-1, -1};
    vector<int> IMP(imp, imp + 2);

    // Finding total number of ones
    int Sum = accumulate(A.begin(),
                         A.end(), 0);

    if (Sum % 3)
    {
        return IMP;
    }

    int K = Sum / 3;

    // Array contains all zeros.
    if (K == 0)
    {
        return {0, (int)A.size() - 1};
    }

    vector<int> interval;
    int S = 0;

    for (int i = 0 ;i < A.size(); i++)
    {
        int x = A[i];
        if (x)
        {
            S += x;
            if (S == 1 or S == K + 1 or S == 2 * K + 1)
            {
                interval.push_back(i);
            }
            if (S == K or S == 2 * K or S == 3 * K)
            {
                interval.push_back(i);
            }
        }
    }

    int i1 = interval[0], j1 = interval[1],
        i2 = interval[2], j2 = interval[3],
        i3 = interval[4], j3 = interval[5];

    vector<int> a(A.begin() + i1, A.begin() + j1 + 1);
    vector<int> b(A.begin() + i2, A.begin() + j2 + 1);
    vector<int> c(A.begin() + i3, A.begin() + j3 + 1);
    if (!((a == b) and (b == c))) {
        return {-1, -1};
    }
    int x = i2 - j1 - 1;
    int y = i3 - j2 - 1;
    int z = A.size() - j3 - 1;
    if (x < z or y < z)
    {
        return IMP;
    }
    j1 += z;
    j2 += z;
    return {j1, j2 + 1};
}
int mul(int a,int b){
  return ((a)*(b))%M;
}
int add(int a,int b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
void solve(){
	int n;
	cin >> n;
	vi v(n);
	for(auto &i: v)
		cin >> i;
	vi V = ThreeEqualParts(v);
	int f = V[0], l = V[1];
	int b = 1, ans = 0;
	if(l == - 1 and f == - 1){
		cout << l;
		return;
	}
	l--, f++;
	// cout << l << f;
	per(i, l, f){
		ans = add(ans, mul(v[i], b));
		b = mul(b, 2);
	}
	cout << ans;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}