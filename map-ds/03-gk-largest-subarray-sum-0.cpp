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

    // <preSum[i], first index>
    unordered_map<int, int> mp;
    int preSum = 0;
    mp[0] = -1;

    int ans = 0;
    for0(i, n) {
        preSum = (preSum + arr[i]);
        if(mp.find(preSum) != mp.end()) {
            ans = max(ans, (i - mp[preSum ]));
            continue;
        }
        mp[preSum] = i;
    }

    cout<<ans<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}
