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

int ans = 0;
vector<int> adjL[100009];
int haveCat[100009];
int m;

void findResturant(int node, int parent, int cats) {
    if((cats == m) && haveCat[node]) {
        return;
    } 

    if(adjL[node].size() == 1) {
        ans++;
        return;
    }
    for(int i = 0; i < adjL[node].size(); i++ ) {
        if(adjL[node][i] != parent) {
            findResturant(adjL[node][i], node, (haveCat[node] ? cats+1: 0));
        }
    }
}

void solution() {
    int n;
    cin>>n>>m;

    if(n==0) {
        cout<<ans<<endl;
        return;
    }

    int x, y;
    for0(i, n) {
        cin>>x;
        haveCat[i+1] = x;
    }

    for(int i = 0; i < n - 1; i++) {
        cin>>x>>y;
        adjL[x].pb(y);
        adjL[y].pb(x);
    }
    adjL[1].push_back(0);
    findResturant(1, 0, 0);
    cout<<ans<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

