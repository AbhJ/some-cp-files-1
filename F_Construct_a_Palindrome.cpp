//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 27 in 18 : 22 : 53
//title - F_Construct_a_Palindrome.cpp
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
#define all(x) x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
void solve(){
	scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%c",&ch);
            for(j=0;j<n;j++){
                scanf("%c",&ch);
                len[i][j]=0;
                st[i][j]="";
                if(i>=j) continue;
                len[i][j]=1;
                st[i][j]+=ch;
                d[i][j]=ch;
            }
        }
        for(k=1;k<n;k++){
            for(i=0;i<n;i++){
                if(i+k>=n) break;
                j=i+k;
                for(l=i+1;l<j;l++){
                    for(m=l;m<j;m++){
                        if(d[i][l]==d[m][j]){
                            tmp=d[i][l]+st[l][m]+d[m][j];
                            if(len[l][m]+2>len[i][j]){
                                len[i][j]=len[l][m]+2;
                                st[i][j]=tmp;
                            }
                            else if(len[l][m]+2==len[i][j] && st[i][j]>tmp) st[i][j]=tmp;
                        }
                    }
                }
            }
        }
        printf("%s\n",st[0][n-1].c_str());
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}