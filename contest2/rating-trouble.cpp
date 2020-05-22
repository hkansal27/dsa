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

int findNearestPrime(int index, int primes[], int n) {
    if(index == 1) {
        return 2;
    }
    if(primes[index] == 1) {
        return index;
    } 
    int j = 1;
    if(index - j < 0) {
        while(primes[index + j] != 1) {
            j++;
        }
    } else if(index + j > n) {
        while(primes[index - j] != 1) {
            j++;
        }
    } else {
        while(primes[index - j] != 1 && primes[index + j] != 1) {
            j++;
        }
    }

    if(primes[index - j] == 1) return index-j;
    else return index + j;
}

void solution() {
    int n;
    cin>>n;

    int arr[n], maxx=INT_MIN;
    for0(i,n) {
        cin>>arr[i];
        maxx=max(maxx, arr[i]);
    }

    int primes[maxx+1];
    primes[0] = 0;
    primes[1] = 0;

    for(int i = 2; i <= maxx; i++) {
        primes[i] = 1;
    }
    // primes array
    for(int i = 2; i*i <= maxx; i++) {
        if(primes[i] == 1) {
            for(int j = i; i*j <= maxx; j++) {
                primes[i*j] = 0;
            }
        }
    }

    for0(i, n) {
        cout<<findNearestPrime(arr[i], primes, maxx+1)<<endl;
    }
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

