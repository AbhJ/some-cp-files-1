//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 22 in 20 : 27 : 39
//title - Mission_Impossible_1.cpp
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
// const double Pi = M_PI;
#define F first
#define S second
void compute_z(string s, int z[])
{
    int l = 0, r = 0;
    int n = s.length();
    for (int i = 1; i <= n - 1; i++) {
        if (i > r) {
            l = i, r = i;
            while (r < n && s[r - l] == s[r])
                r++;
            z[i] = r - l;
            r--;
        }
        else {
            int k = i - l;
            if (z[k] < r - i + 1) {
                z[i] = z[k];
            }
            else {
                l = i;
                while (r < n && s[r - l] == s[r])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
}

// Function to get the count of the cyclic
// permutations of b that given 0 when XORed with a
int countPermutation(string a, string b)
{
    // concatenate b with b
    b = b + b;

    // new b now contains all the cyclic
    // permutations of old b as it's sub-strings
    b = b.substr(0, b.size() - 1);

    // concatenate pattern with text
    int ans = 0;
    string s = a + "$" + b;
    int n = s.length();

    // Fill z array used in Z algorithm
    int z[n];
    compute_z(s, z);

    for (int i = 1; i <= n - 1; i++) {

        // pattern occurs at index i since
        // z value of i equals pattern length
        if (z[i] == a.length())
            ans++;
    }
    return ans;
}
string s, t;
void solve(){
	cin >> s >> t;
	cout << countPermutation(s, t);
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}