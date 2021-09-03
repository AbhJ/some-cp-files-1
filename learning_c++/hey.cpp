#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int g=0,p=0;
		int n=0,i=0;
		cin>>g;
		cin>>p;
		cin>>n;
		int s1=0,s2=0,price=0;
		for(i=0;i!=n;i++){
				cin>>s1;
				cin>>s2;
				price +=s1*g+s2*p;
		}
		cout<<price;
	}
return 0;
}