// In code world all genders are considered equal ( It means their is nothing like male or female). Now their are N distinct persons living in this hypothetical world. Each person can pair up with any other person or can even remain single. 
// One day Vbhu planned to visit code world. Being a maths guy , he always try to be mathematical. So he started counting the ways in which N persons living in code world can make pairs or remain single. A single person can make pair with at most one other person.
// Seeing that N can be large , Vibhu ask you for help. Now being a great programmer you need to help Vbhu count the number of ways in which N persons living in code world can make pairs or remain single.

// Note : Its not necessary that everyone is required to make pair with someone. Person can remain single also.

// Input Format : 
// First line contain number of test cases T. Then next T lines contain a single integer N , denoting the number of persons living in code world.

// Output Format : 
// You need to print the number of ways in which N different persons can make their pairs or stay single. As answer can be large so print it modulo 109+7.

// Constraints :
// 1 <= T <=105 
// 1 <= N <=106

// Warning: Large Input/Output data, be careful with certain languages

// SAMPLE INPUT 
// 2
// 2
// 3

// SAMPLE OUTPUT 
// 2
// 4

// Explanation
// In first test case , For N=2 answer will be 2. Possible ways are : {1},{2} (It means Person 1 and Person 2 are single) {1,2} (It means Person 1 and Person 2 had formed a pair)

// For second test case , For N=3 , answer will be 4. Possible ways are : {1},{2},{3} (It means all three Persons are single) {1,2},{3} (It means Person 1 and Person 2 had formed a pair and Person 3 is single) {1},{2,3} (It means Person 2 and Person 3 had formed a pair and Person 1 is single) {1,3},{2} (It means Person 1 and Person 3 had formed a pair and Person 2 is single)

// Time Limit: 2.0 sec(s) for each input file.
// Memory Limit: 256 MB
// Source Limit: 1024 KB
// Marking Scheme: Marks are awarded if any testcase passes.
// Allowed Languages: Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic
// ACTIVITY
// Save
//   
// 38:2
//  Press Ctrl/Command+Spacebar for autocomplete suggestions (accuracy dependent on connection stability).
//  Provide custom input
// Submission ID: 27087719 / 6 seconds ago
// RESULT:  Time Limit Exceeded
// Score

// 0

 
// Time (sec)

// 20.12703

 
// Memory (KiB)

// 28532

 
// Language

// C++

// Input   Result  Time (sec)  Memory (KiB)    Score
// Input #1        2.015302    8960    0
// Input #2        2.009719    8964    0
// Input #3        2.014545    8964    0
// Input #4        2.007478    8968    0
// Input #5        2.015116    8972    0
// Input #6        2.016424    8972    0
// Input #7        2.007526    8224    0
// Input #8        2.014793    16100   0
// Input #9        2.011804    11220   0
// Input #10       2.014323    28532   0
// Compilation Log
// No compilation log for this submission.

#include <bits/stdc++.h>
#define ll long long int
#define N 100000
#define M 1000000007
#define f(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define rf(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define cot cout.tie(0)
ll a[1000000];
using namespace std;
long long int h(ll n){

	if(a[n])
    	return(a[n]);
	if(n<=2)return n;    
	ll store=h(n-1)+(n-1)*h(n-2);
	a[n]=store;
	return (store);
}
int main()
{
    ibs;
    // cti;
    int t=0;
    ll n=0;
    cin >> t;
    f(i,1,t){
    	cin>>n;
    	cout<<h(n)%M<<"\n";
    }
    return 0;
}