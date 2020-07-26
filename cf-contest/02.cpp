#include <iostream>
#include <vector>
#include <climits>

#define for0(i, n) for (int i = 0; i < (int)(n); ++i) // 0 based indexing
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive

//short hand for usual tokens
#define pb push_back
#define fi first
#define se second

#define mod 10000009

using namespace std;

// Shorthand for commonly used types
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef double ld;

void solution() {
    int n;
    cin>>n;

    vector<int> arr;
    int temp;
    for0(i, n) {
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<"Hi"<<endl;
    bool isFirst = true;
    while(arr.size() > 0) {
        int i = 1;
        while(arr.size() > 1 && arr[i] == 1 && i < arr.size()) {
            i++;
        }
        cout<<i<<endl;
        if(i == arr.size()) {
            if(i%2 == 0) {
                arr[0] = 1;
            } else {
                arr.erase(arr.begin());
            }
            continue;
        }
        if(arr.size() == 1) {
            arr.erase(arr.begin());
            break;
        } 
        if(arr[0] == 1) {
            arr.erase(arr.begin());
        } else if(arr[0] > 1) {
            arr[0] = 1;
        }
        isFirst = !isFirst;
    }

    if(isFirst) {
        cout<<"First"<<endl;
    } else {
        cout<<"Second"<<endl;
    }
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

