#include <bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	int i=0,j=0,count=0,flag=0;
	for(i=0;a[i]!='\0';i++){
		if (flag==0){
			if(a[i]=='a'|a[i]=='e'|a[i]=='i'|a[i]=='o'|a[i]=='u'){
				j++;flag=1;
			}
		}
		else{
			if(a[i]=='a'|a[i]=='e'|a[i]=='i'|a[i]=='o'|a[i]=='u')
				j++;
			else{
				flag=0;
				if(j>count)
					count=j;
				j=0;
			}
		}
		if(j>count)
			count=j;
	}
cout<<count;
return 0;
}