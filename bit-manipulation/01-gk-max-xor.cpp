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
    int l, r;
    cin>>l>>r;

    int xor_range = (l ^ r);
    int mask = 1 <<31;

    while(mask) {
        if(xor_range & mask) {
            break;
        }
        mask >>= 1;
    }
    int i;
    for(i = l+1; i <= r; i++) {
        if(i&mask) {
            break;
        }
    }

    cout<<((i-1)^i)<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

