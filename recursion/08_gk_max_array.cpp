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

int findMax(int i, int j, int arr[]) {
    if( i == j) {
        return arr[i];
    }
    int mid = (i+j)/2;
    return max(findMax(i, mid, arr), findMax(mid + 1, j, arr));
}

void solution() {
    int arr[] = {7,1,10,3,2,6,5};

    int n(7);
    cout<<findMax(0, 6, arr)<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

