#include <bits/stdc++.h>
#define ll long long int
#define N 1000
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
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    ibs;cti;
    int T;
    cin>>T;
    while(T--){
        ll n; cin>>n;
        bool v[n][10];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                cin>>v[i][j];
            }
            // if (i)
            // {
            //     cout<<"\n\n\n";
            //     for (int j = 0; j < 10; ++j)
            //     {
            //         if ((v[i-1][j]==1&&v[i][j]==0)||(v[i-1][j]==0&&v[i][j]==1))
            //         {
            //             v[i][j]=1;
            //         }
            //         else v[i][j]=0;
            //          cout<<v[i][j];

            //     }
            //      cout<<"\n\n\n";
            // }
        }
        ll count=0;
        cout<<"\n\n\n";
        for (int j = 0; j < 10; ++j)
        {
            cout<<v[n-1][j];
            if(v[n-1][j])
                count++;
        }
        cout<<"\n\n"<<"\n\n\n"<<count<<"\n";

    }
    return 0;
}