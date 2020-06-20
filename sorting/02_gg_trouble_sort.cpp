#include <iostream>
#include <vector>
#include <algorithm>

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing

using namespace std;

void solution(int t) {
    int n;
    cin>>n;

    vector<int> o;
    vector<int> e;
    int temp;
    for0(i, n) {
        cin>>temp;
        if(i%2 == 0) {
            e.push_back(temp);
        } else {
            o.push_back(temp);
        }
    }

    sort(e.begin(), e.end());
    sort(o.begin(), o.end());

    int count = 0;
    bool flag = false;
    for0(i, n/2) {
        if(e[i] > o[i]) {
            count = i;
            flag = true;
        }
    }

    cout<<"Case #";
    if(!flag) {
        cout<<t+1<<": OK"<<endl;
    } else {
        cout<<t+1<<" "<<count<<endl;
    }
}

int main() {
    int t(1);
    cin>>t;
    for(int i = 0; i < t; i++) {
        solution(i);
    } 
    return 0 ;
}

