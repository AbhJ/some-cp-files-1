#include<bits/stdc++.h>
using namespace std;
int main(){
	int t=0,n=0,k=0,a=0,b=0,i=0,j=0;
	int A[1000];
	cin>>t;
	while(t--){
		cin>>n>>k;
		if(k>90)
			cout<<1<<endl;
		//if n is odd
		b=k%10;
		a=k/10;
		for(i=0;i<n;i++){
			if(i%2==0)
				cout<<a;
			else
				cout<<b;
		}
		cout<<endl;
		
	}
	return 0;
}