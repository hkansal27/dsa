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

int findPath(int r, int c, int tr, int tc) {

    if(r == tr - 1) return 1;
    if(c == tc - 1) return 1;

    return (findPath(r+1, c, tr, tc) + findPath(r, c+1, tr, tc));
}

void solution() {
    int n, m;
    cin>>n>>m;
    cout<<findPath(0,0, n, m)<<endl;
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

