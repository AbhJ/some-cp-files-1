// #include <bits/stdc++.h>
// using namespace std;
// int main(){
// 	unsigned long long n=0,i=0;
// 	unsigned long long q=0;
// 	cin>>n;
// 	unsigned long long a[n];
// 	for(i=0;i!=n;i++){
// 		cin>>a[i];
// 	}
// 	sort(a,a+n,greater<unsigned long long>());
// 	cin>>q;
// 	int flag=0;
// 	unsigned long long num=0;
// 	unsigned long long ans=0;
// 	// 	for(i=0;i!=n;i++){
// 	// 	cout<<a[i]<<"\t";
// 	// }
// 	while(q--){
// 	    ans=0;
// 		cin>>flag;
// 		cin>>num;
// 		if (flag==1){//considering the numbers greater than num
// 			for(i=0;i!=n;i++){
// 				if(a[i]>num)
// 					ans++;
// 				if(a[i]=num)
// 				    break;
// 			}
// 		}
// 		else{//considering the numbers greater than equal to num
// 			for(i=0;i!=n;i++){
// 				if(a[i]>=num)
// 					ans++;
// 				if(a[i]<num)
// 			        break;
// 			}
// 		}
// 	cout<<ans<<endl;

// 	}
// return 0;
// }
#include<bits/stdc++.h>
using namespace std;

int main()
{
int n;
cin>>n;
vector<int> a(n);
for(int i=0;i<n;i++)
{
cin>>a[i];
}
sort(a.begin(),a.end());
int q;
cin>>q;
while(q--)
{
int x,y;
cin>>x>>y;

if(x==0)
{
int result=lower_bound(a.begin(),a.end(),y)-a.begin();
cout<<n-result<<"\n";

}

else
{
int result=upper_bound(a.begin(),a.end(),y)-a.begin();
cout<<n-result<<"\n";

}
}
return 0;
}