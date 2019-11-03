#include <bits/stdc++.h>
#define ll unsigned long long int
#define N 100000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
// ll A[10000];
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti;
    int t,n;
    cin>>t;
    while(t--){
        pair<int,int>p;
        cin>>n;
        vector<pair<pair<int,int>,int>>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i].first.second;
            v[i].second=i;
        }
        for(int i=0;i<n;i++){
            cin>>v[i].first.first;
            // v[i].second=i;
        }
        
        sort(v.begin(),v.end());
        int flag=0;
        cout<<v[flag].second+1<<" ";
        for (int i = 1; i < n; ++i)
        {
            if(v[i].first.second>=v[flag].first.first){
                flag=i;
                cout<<v[flag].second+1<<" ";
            }                
        }

        cout<<"\n";
    }
    return 0;
}