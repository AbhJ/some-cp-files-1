#include <bits/stdc++.h>
using namespace std;
int main(){
	int K=0;
	string a;
	cin>>a;
	cin>>K;
	int len=a.length();
	int i=0;
	string str[len];
	for(i=0;i<len;i++){
		str[i]=a.substr(i,len);
	}
	sort(str, str+len);
	cout<<str[K-1];
return 0;
}