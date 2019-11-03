#include <bits/stdc++.h>
#define ll long long int
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
int a[50];
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti;
    int T;
    cin>>T;
    
    while(T--){
        string n;
        cin>>n;
        char ans='0';
        ll index=0;
        ll x=stoi(n);
        if(x<10){
            cout<<x<<"\n";
            continue;
        }
        if(n.at(1)=='0')
            {
                index=0;
                continue;
            }
        for (ll i = n.length()-1;i>-1; --i)
        {
            if(n.at(i)>=ans){
                ans=n.at(i);
                index=i;
            }
            
        }
        n.erase(n.begin() + index);
        x=stoi(n);
        cout<<x<<"\n";
    }
    return 0;
}