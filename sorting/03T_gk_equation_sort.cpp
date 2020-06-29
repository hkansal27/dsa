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
    ll a,b,c;
    cin>>a>>b>>c;

    int n;
    cin>>n;
    ll A[n];

    ll temp;

    for0(i, n) {
        cin>>temp;
        A[i] = a*(temp*temp) + (b*temp) + c;
    }

    sort(A, A+n);

    for0(i, n) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

