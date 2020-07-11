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

ll cnt = 0;

void solution() {
    ll n, d;
    cin>>n>>d;

    ll pnt[n];
    for0(i, n) cin>>pnt[i];

    ll i = 0, j = 2;
    
    // 
    while(j < n) {
        if((pnt[j] - pnt[i]) <= d) {
            cnt+= ((j-i)*(j-i-1))/2;
            j++;
        }
        else {
            if((j-i) == 2) j++;
            i++;
        }
    }

    cout<<cnt<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

