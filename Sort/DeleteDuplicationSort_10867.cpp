#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
    int num, order, tmp;
    cin >> num ;
    vector<int> v;
    for(int i=0;i<num;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(const auto& n:v){
        cout << n << " ";
    }
}