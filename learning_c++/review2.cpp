// The students of college  are getting jealous of the students of college .  managed to beat  in all the sports and games events. 
// The main strength of the students of  is their unity. The students of  decide to destroy this unity. The geeks of  prepared
//  a special kind of perfume. Anyone who inhales this perfume becomes extremely violent. The students of  somehow manage to 
//  spread this perfume throughout 's campus atmosphere.

// // There are N boys  and N girls  in  college. Each boy has a crush on a single girl and each girl has a crush on a single boy
//  . Since the perfume has been inhaled by each and every student of  college, every student decides to beat up his/her crush's 
//  crush, ie. , if boy x has a crush on girl y and girl y has a crush on boy z, x will beat z up, provided, of course, if x and z
//   is not the same person.

// // The doctor of  college foresees this situation. He cannot stop so many people from beating each other up, however, 
//   he can be prepared for the worst-case patient(s). The worst-case patient(s) will be the patient(s) who get(s) beaten 
//   \up by the maximum number of students. The doctor comes to you for help. He has 2 questions for you :

// 1. What is the number of beatings received by the worst-case patient(s) ?

// 2. What is the total number of pairs of students who ended up beating up each other ?

// Input :

// The first line comprises of T, the number of test cases. Each test case comprises of 3 lines. The first line consists of N.

// The next line consists of N space separated natural numbers between 1 and N inclusive such that the  number denotes the the crush of boy i.

// The next line consists of N space separated natural numbers between 1 and N inclusive such that the  number denotes the the crush of girl i.

// Output :

// For every test case, on a new line, print two space separated integers, the answer to doctor's question 
// 1 followed by answer to doctor's question 2.

// Constraints :



// SAMPLE INPUT 
// 2
// 3
// 2 2 1
// 3 2 1
// 4
// 2 3 4 1
// 2 3 4 1
// SAMPLE OUTPUT 
// 1 0
// 1 4





#include <bits/stdc++.h>
using namespace std;
int mostFrequent(int arr[], int n) 
{ 
    // Sort the array 
    sort(arr, arr + n); 
  
    // find the max frequency using linear traversal 
    int max_count = 1, res = arr[0], curr_count = 1; 
    for (int i = 1; i < n; i++) { 
        if (arr[i] == arr[i - 1]) 
            curr_count++; 
        else { 
            if (curr_count > max_count) { 
                max_count = curr_count; 
                res = arr[i - 1]; 
            } 
            curr_count = 1; 
        } 
    } 
  
    // If last element is most frequent 
    if (curr_count > max_count) 
    { 
        max_count = curr_count; 
        res = arr[n - 1]; 
    } 
  
    return res; 
}
int frequency(int a[], int n, int x) 
{ 
    int count = 0; 
    for (int i=0; i < n; i++) 
       if (a[i] == x)  
          count++; 
    return count; 
} 
  
int main(){
	int t=0;
	int n=0,i=0,j=0,beat=0,pair=0,no=0;
	int b[10000];
	int g[10000];
	cin>>t;
	while(t--){
	    cin>>n;
	    for(i=0;i<n;i++){
	        cin>>b[i];
	    }
	    for(i=0;i<n;i++){
	        cin>>g[i];
	    }
	    for(i=0;i<n;i++){
	        if(g[b[i]]==b[g[i]])
	            pair++;
	    }
	    no=mostFrequent(b, n);
	    beat=frequency(b, n, no);
	    if(mostFrequent(g, n)>no){
	        no=mostFrequent(g, n);
            beat=frequency(g, n, no);
	    }
        
	    cout<<beat<<" "<<pair<<endl;
	    
	}
    return 0;
}