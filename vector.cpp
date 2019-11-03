#include <bits/stdc++.h>
using namespace std;
int main(){
    // std::vector<int> v;
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);
    // v.push_back(40);
    // for (int i = 0; i < v.size(); ++i)
    // {
        
    //  /* code */cout<<endl<<i<<"\t"<<v[i]<<endl;
    // }
    // v.erase(v.begin());
    // cout<<endl<<endl<<endl;
    // v.clear();
    // for (int i = 0; i < v.size(); ++i)
    // {
    //  /* code */cout<<endl<<i<<"\t"<<v[i]<<endl;
    // }
    // cout<<"Is Vector empty? "<<v.empty()<<endl;
    // cout<<"Max size is of the vector "<<v.max_size()<<endl;
    
    vector<int> g1; 
  
    for (int i = 1; i <= 5; i++) 
        g1.push_back(i); 
  
    cout << "Size : " << g1.size(); 
    cout << "\nCapacity : " << g1.capacity(); 
    cout << "\nMax_Size : " << g1.max_size(); 
  
    // resizes the vector size to 4 
    g1.resize(4); 
  
    // prints the vector size after resize() 
    cout << "\nSize : " << g1.size(); 
  
    // checks if the vector is empty or not 
    if (g1.empty() == false) 
        cout << "\nVector is not empty"; 
    else
        cout << "\nVector is empty"; 
  
    // Shrinks the vector 
    g1.shrink_to_fit(); 
    cout << "\nVector elements are: "; 
    for (auto it = g1.begin(); it != g1.end(); it++) 
        cout << *it << " "; 
  
    return 0;
}