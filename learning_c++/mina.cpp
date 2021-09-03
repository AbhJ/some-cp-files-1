#include<bits/stdc++.h>
using namespace std;
int main(){
	int Q=0,i=0,j=0,flag=0,k=0,flag1=1,i1=0,j1=0,len=0;
	cin>>Q;
	string s,a;
	int n=0;
	while(Q--){
		i=0;
		j=0;
		k=0;
		flag=0;
		flag1=1;
		i1=0;
		j1=0;
		len=0;
		cin>>n;
		cin>>s;
		string sub[n];
		for (i = 0; i < n; ++i){
			if(flag==0){
				sub[j][k]=s[i];
				cout<<sub[j][k]<<endl;
				k++;//welcome to new string
				flag=1;//we are in a new string
			}
			else{
			    len=0;
				a=sub[j];
				for(len=0;a[len]!='\0';++len);
				for(i1=0,j1=len-1;i1<len/2;++i1,--j1)
				{
    				if(a[j1]!=a[i1])
    				flag1=0;
				}
				if(flag1){
					j++;
					k=0;
					flag=0;//send to new string
				}
				else{
					sub[j][k]=s[i];
					k++;//continue the string
				}
			}
		}
		for(k=0;k<10;++k)
		    cout<<sub[k]<<endl;
// 	cout<<j+1<<endl;
	}

return 0;
}