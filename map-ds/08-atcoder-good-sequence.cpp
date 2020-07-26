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

    for0(i, n) {
        cin>>arr[i];
    }

    // <val, freq>
    unordered_map<int,int> mp;
    for0(i, n) {
        mp[arr[i]]++;
    }
    int ans = 0;
    for(auto m: mp) {
        if(m.first < m.second) {
            ans += (m.second - m.first);
        } else if(m.first > m.second) {
            ans += m.second;
        }
    }

    cout<<ans<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

