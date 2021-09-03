#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	string s1, s2;
	while(t--){
		cin>>s1;
		s2=s1;
		reverse(s2.begin(), s2.end());
		if(!s1.compare(s2)){
			cout<<"YES ";
			if(s1.length()%2)
				cout<<"ODD"<<endl;
			else cout<<"EVEN"<<endl;
		}
		else cout<<"NO"<<endl;
	}
}