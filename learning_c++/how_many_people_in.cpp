#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],b[n],i,j=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
        }
        sort(a,a+n);
        sort(b,b+n);
        
        int ans=0;
        int maxi=INT_MIN;
        i=0;
        
        while(i<n)
        {
            if(a[i]<b[j])
            {
                ans++;
                i++;
                maxi=max(maxi,ans);
            }
            else
            {
                ans--;
                j++;
            }
            // cout<<a[i]<<" "<<b[j]<<endl;
        }
            cout<<maxi<<endl;
    }
}