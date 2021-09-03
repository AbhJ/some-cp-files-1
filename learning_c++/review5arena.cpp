// One day Benny was walking and realized that her life was boring. Everything was grey, even roads in the best park were grey.

// Therefore she decided to make roads a little bit brighter. She know that every road in the park is a segment laying on the X axis with coordinates Xl, Xr (Xl ≤ Xr). Roads may intersect or overlap.

// She chooses any subset of roads and paints them in red. After that she wants to get one continuous red segment. As she really likes number L the length of this segment has to be equal to L.

// Your task is to determine if it is possible to choose some subset of roads and paint them to get one red segment with the length equal to L?

// If it's possible print in a single line "Yes"(without quotes), otherwise print "No" (without quotes).

// Input format

// The first line contains one integer T - the number of test cases. Each test case starts with two integers N and L, denoting the number of roads and Benny's favorite number L. The next N lines contain two integers Xl, Xr, denoting the left and right borders of the road.

// Output format

// For every test case output "Yes" if it is possible to paint some roads and "No" otherwise.

// Constraints

// 1 ≤ sum of all N ≤ 2 * 103
// 1 ≤ L ≤ 106
// 1 ≤ Xl ≤ Xr ≤ 106
// 1 ≤ N ≤ 20, 1 ≤ Xl ≤ Xr ≤ 200, holds for test cases worth 10% of the problem's score.
// 1 ≤ N ≤ 100, 1 ≤ Xl ≤ Xr ≤ 200, holds for test cases worth 20% of the problem's score.
// Sample Explanation

// In the first test case you can choose roads (1; 2) (2; 3) and (3; 4) the result segment is (1; 4) and its length equals 3 (4 - 1 = 3).

// In the second case you can not choose any subset that will create segment with the length equal to 4.

// SAMPLE INPUT 
// 2
// 5 3
// 1 2
// 2 3
// 3 4
// 1 5
// 2 6
// 2 3
// 1 2
// 2 6
// SAMPLE OUTPUT 
// Yes
// No
// Time Limit: 2.0 sec(s) for each input file.
// Memory Limit: 256 MB
// Source Limit: 1024 KB
// Marking Scheme: Marks are awarded if any testcase passes.
// Allowed Languages: Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic
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
    int a[N],b[N];
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,l;
        cin >> n >> l;
        int ar[2][n];
        for(int i = 0; i < n; i++){
            cin >> ar[0][i] >> ar[1][i];
        }
        //BUBBLE SORT
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - i -1; j++){
                if(ar[1][j] > ar[1][j+1]){
                    int t1,t2;
                    t1 = ar[0][j];
                    t2 = ar[1][j];
                    ar[0][j] = ar[0][j+1];
                    ar[1][j] = ar[1][j+1];
                    ar[0][j+1] = t1;
                    ar[1][j+1] = t2;
                }
            }
        }
    
        int f = 0;
        for(int i = 0; i < n && f==0; i++){
            int diff = ar[1][i] - ar[0][i];
            if(diff == l){
                f = 1;
                break;
             }
            else if(diff < l){
                for(int j = i+1; j < n; j++){
                    if(ar[0][j] == ar[1][j-1]){
                        diff = ar[1][j] - ar[0][i];
                        if(diff == l){
                            f = 1;
                            break;
                        }
                        else if(diff < l){
                            continue;
                        }
                        else
                            break;
                    }
                }
            }
        }
        
        if(f){
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }
}