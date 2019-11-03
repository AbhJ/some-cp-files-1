#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string a;
		cin>>a;
		transform(a.begin(), a.end(), a.begin(), ::tolower);
		int count=0;
		for(int i=0;a[i]!='\0';i++){
			if( (a[i]=='a')||(a[i]=='e')||(a[i]=='i')||(a[i]=='o')||(a[i]=='u'))
				count++;
		}
	cout<<count<<endl;
	}
return 0;
}