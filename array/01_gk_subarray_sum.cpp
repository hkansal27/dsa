// Subarray with given sum
// brute force approach

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
    int n, m;
    cin>>n>>m;
    int arr[n];

    int prefix[n + 1];
    prefix[0] = 0;
    for0(i, n) {
        cin>>arr[i];
        prefix[i+1] = prefix[i] + arr[i];
    }
    bool find = false;
    for0(i, n) {
        forc(j, i, n-1) {
            if(prefix[j + 1] - prefix[i] == m) {
                cout<<i + 1<<" "<<j + 1<<endl;
                find = true;
                break;
            }
        }
        if(find) {
            break;
        }
    }
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

