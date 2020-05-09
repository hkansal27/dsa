// Find the only repeating element in a sorted array of size n
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
    int arr[n];
    for0(i, n) {
        cin>>arr[i];
    }

    int l = 0, h = n-1;
    int m;
    while(l <= h) {
        m = (l+h) / 2;

        if(arr[m] == m + 1) {
            l = m + 1;
        } else {
            if(arr[m] == arr[m-1]) {
                break;
            } else {
                h = m - 1;
            }
        }
    }

    cout<<m<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

