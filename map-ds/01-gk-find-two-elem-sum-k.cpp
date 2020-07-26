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
    int n, k;
    cin>>n>>k;

    int arr[n];

    for0(i, n) {
        cin>>arr[i];
    }

    unordered_map<int, int> mp;
    bool isFind = false;
    for0(i, n) {
        if(mp.find(k-arr[i]) != mp.end()) {
            cout<<"Yes"<<endl;
            isFind = true;
            break;
        }
        mp.insert(make_pair(arr[i], 1));
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

