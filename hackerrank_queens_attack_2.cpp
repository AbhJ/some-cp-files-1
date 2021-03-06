#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int R, int C, vector<vector<int>> v) {
    int a=R-1,b=n-R,c=C-1,d=n-C;int e=min(b,d),f=min(a,d),g=min(a,c),h=min(b,c);
    // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h;
    for(auto i:v){
        int x=i[0],y=i[1];
        if(y==C and x<R)a=min(a,abs(x-R)-1);
        if(y==C and x>R)b=min(b,abs(x-R)-1);
        if(x==R and y<C)c=min(c,abs(C-y)-1);
        if(x==R and y>C)d=min(d,abs(C-y)-1);
        if(abs(y-C)==abs(x-R)){
            if(x>R and y>C)e=min(e,abs(x-R)-1);
            if(x>R and y<C)f=min(f,abs(x-R)-1);
            if(x<R and y<C)g=min(g,abs(x-R)-1);
            if(x<R and y>C)h=min(h,abs(x-R)-1);
        }
    }
    // cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h;
    // return -1;
    return a+b+c+d+e+f+g+h;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
