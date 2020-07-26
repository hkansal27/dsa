#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

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

    int arr[n];
    int preSum[n+1];
    preSum[0] = 0;
    for0(i, n) {
        cin>>arr[i];
        preSum[i+1] = (preSum[i] + arr[i]);
    }
    
    unordered_map<int, int> mp;
    bool isFind = false;
    for0(i, n+1) {
        if(mp.find(preSum[i]) != mp.end()) {
            isFind = true;
            cout<<"Yes"<<endl;
            break;
        }
        mp.insert(make_pair(preSum[i], 1));
    }

    if(!isFind) {
        cout<<"No"<<endl;
    }

    return;
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

