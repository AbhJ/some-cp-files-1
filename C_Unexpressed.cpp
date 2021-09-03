//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 27 in 17 : 36 : 39
//title - C_Unexpressed.cpp
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
#define N 1000005
#define MAX 1e10

// Vector to store powers greater than 3
vector<int> powers;

// set to store perfect squares
set<int> squares;

// set to store powers other
// than perfect squares
set<int> s;

void powersPrecomputation()
{
    for (int i = 2; i < N; i++)
    {
        // pushing squares
        squares.insert(i * i);

        // if the values is already
        // a perfect square means
        // present in the set
        if (squares.find(i) != squares.end())
                continue;

        int temp = i;

        // run loop until some
        // power of current number
        // doesn't exceed MAX
        while (i * i <= MAX / temp)
        {
            temp *= (i * i);

            /* pushing only odd powers
            as even power of a number
            can always be expressed as
            a perfect square which is
            already present in set squares  */
            s.insert(temp);
        }
    }

    // Inserting those sorted
    // values of set into a vector
    for (auto x : s)
        powers.push_back(x);
}

int calculateAnswer(int L,int R)
{
    // calculate perfect squares in
    // range using sqrtl function
int perfectSquares = floor(sqrtl(R)) -
                            floor(sqrtl(L - 1));

    // calculate upper value of R
    // in vector using binary search
int high = (upper_bound(powers.begin(),
            powers.end(), R) - powers.begin());

    // calculate lower value of L
    // in vector using binary search
int low = (lower_bound(powers.begin(),
            powers.end(), L) - powers.begin());

    // add into final answer
    perfectSquares += (high - low);

    return perfectSquares;
}
int n;
void solve(){
	cin >> n;
	cout << n + 1 - calculateAnswer(1, n);
}
int32_t main()
{
  ibs;cti;
  powersPrecomputation();
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}