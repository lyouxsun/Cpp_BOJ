#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

bool compare(string a, string b){
        if(a.length()<b.length()){
            return true;
        }
        else if(a.length()>b.length()){
            return false;
        }
        else{
            return strcmp(a.c_str(),b.c_str())<0;
        }
}

int main(){
    int num;
    int min=100;
    string tmp;
    cin >> num;
    vector <string> v;
    for(int i=0;i<num;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());
    for(const auto& n:v) cout<<n<<"\n";
}