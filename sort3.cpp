#include<bits/stdc++.h>
int n[1000];
using namespace std;
int main(){
	int N=0,i=0,j=0;
	cin>>N;
	string a[N];
	for(i=0;i!=N;i++){
		cin>>a[i];
		for(j=0;j!=i;j++){
			if(a[j].compare(a[i])<0)
				n[i]++;
		}
		cout<<n[i]<<endl;
	}

return 0;
}