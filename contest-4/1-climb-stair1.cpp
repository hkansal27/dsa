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

int n;

void findTotalPath(int arr[], int i, int &ans) {
    if(i == n) {
        ans += 1;
    }

    if(i > n) return;

    if(arr[i+1] != 0) findTotalPath(arr, i+1, ans);
    if(arr[i+2] != 0) findTotalPath(arr, i+2, ans);
    if(arr[i+3] != 0) findTotalPath(arr, i+3, ans);

    return;
}

void solution() {
    cin>>n;

    int arr[n+1];
    for0(i, n+1) {
        arr[i] = 1;
    }

    int m, temp;
    cin>>m;

    for0(i, m) {
        cin>>temp;
        arr[temp] = 0;
    }
    int ans = 0;

    findTotalPath(arr, 0, ans);
    cout<<ans<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

