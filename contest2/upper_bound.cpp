#include <iostream>
#include <vector>
#include <climits>
#include <algorithm> 

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
    int n, m;
    cin>>n>>m;

    ll arr[n];
    vi prefix;
    prefix.pb(0);
    for0(i, n) {
        cin>>arr[i];
        prefix.pb(prefix[i] + arr[i]);
    }
    ll temp;
    for0(i, m) {
        cin>>temp;
        std::vector<int>::iterator high = upper_bound(prefix.begin(), prefix.end(), temp);
        int index = high - prefix.begin();
        cout<<index<<" "<<temp - prefix[index-1]<<endl;
    }
    
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

