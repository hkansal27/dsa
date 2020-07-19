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
    ll arr[n];
    ll preSum[n+1];

    int overall_xor = 0;
    for0(i, n) {
        cin>>arr[i];
        overall_xor = (overall_xor ^ arr[i]);
    }

    preSum[0] = 0;
    for(int i = 1; i < n; i++) {
        preSum[i] = (preSum[i-1]^(i));
    }

    for(int i = 1; i <= n; i++) {
        if((n/i)%2) {
            overall_xor = (overall_xor ^ preSum[i-1]);
        }
        overall_xor = (overall_xor ^ preSum[n%i]);
    }

    cout<<overall_xor<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

