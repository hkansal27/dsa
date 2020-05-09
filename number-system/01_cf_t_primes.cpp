#include <iostream>
#include <vector>
#include <climits>
#include <math.h>  

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
    ll maxx = INT_MIN;

    for0(i, n) {
        cin>>arr[i];
        maxx = max(maxx, arr[i]);
    } 

    // find primes array upto sqrt of max
    ll p = sqrt(maxx);
    
    int primes[p + 1];
    primes[0] = 0;
    primes[1] = 0;

    forc(i, 2, p) {
        primes[i] = 1;
    }

    for(int i = 2; i*i <= p; i++) {
        if(primes[i] == 1) {
            for(int j = i; i*j <= p; j++) {
                primes[i*j] = 0;
            }
        }
    }

    for0(i, n) {
        p = sqrt(arr[i]);
        if(p*p != arr[i]) {
            cout<<"NO"<<endl;
            continue;
        } else {
            if(primes[p] == 1) {
                cout<<"YES"<<endl;
                continue;
            }
            cout<<"NO"<<endl;
        }
    }
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

