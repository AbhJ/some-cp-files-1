#include<bits/stdc++.h>
using namespace std;
int main(){
	int N=0,i=0,j=0;
	cin>>N;
	string a[N];
	string t[N];
	int maxlen;
	int I=0;
	for(i=0;i!=N;i++){
		cin>>a[i];
		// taking input the N strings and 
		// finding out the length of the
		// biggest string
		if(i=0||(maxlen<a[i].length()))
			maxlen=a[i].length();
	}
	i=1;
	while(5*i<maxlen){
	    cout<<"\n";
		for(j=0;j!=N;j++){
			t[j]=a[j].substr(((a[j].length())-5*(i)),((a[j].length())-5*(i-1)));
		}

	   	int k=0; 
	   	for (k = 0;  k< N-1; k++){
	  
	       // Last i elements are already in place    
	       for (j = 0; j < N-j-1; j++){
	           if (t[j] > t[j+1])
	              swap(a[j], a[j+1]); 
	      	}
	  	}
  		for (k = 0;  k< N-1; k++){
	  
	       // Last i elements are already in place    
	       cout<<a[k]<<" ";
	  	}
    i++;
    }
return 0;
}