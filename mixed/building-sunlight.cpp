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
    int maxx[n];

    for0(i, n) {
        cin>>arr[i];
    }
    maxx[0] = arr[0];
    for(int i = 1; i < n; i++) {
        maxx[i] = max(maxx[i-1], arr[i]);
    }
    int count(0);
    for0(i, n) {
        if(arr[i] == maxx[i]) count++;
    }
    cout<<count<<endl;
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

