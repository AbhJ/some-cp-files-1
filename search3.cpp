#include<bits/stdc++.h>
using namespace std;
int main(){
	int l;
	long int n,i,x,j;
	cin>>n>>x;
	long long int a[n+1];
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=0;
	for(i=1;i<=n;i++){
		a[i]+=a[i-1];
	}
	a[i]=0;
	if(a[n]<=x){
		cout<<n<<"\n";
		return 0;
	}
	l=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=i;j++){
			if(a[n-i+j]-a[j]>x){
			l=1;//this sub-array fails
			break;
			}
		}
		if(l==0)
			break;//the sum of all elements in all arrays of the biggest possible size n-i in the array a is less than x
		else
			l=0;
	}
	cout<<n-i<<endl;
}