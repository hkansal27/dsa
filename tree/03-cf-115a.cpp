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

vector<int> adj[100000];

int findHeight(int node, int parent) {
    if(adj[node].size() == 1) {
        return 1;
    }
    int maxx = 0;
    for(int i = 0; i < adj[node].size(); i++) {
        if(adj[node][i] != parent) {
            maxx = max(findHeight(adj[node][i], node), maxx);
        }
    }
    return maxx + 1;
}

void solution() {
    int n;
    cin>>n;

    int x, y;
    for0(i, n) {
        cin>>x;
        x = x == -1 ? 0: x;
        adj[i+1].pb(x);
        adj[x].pb(i+1);
    }

    int maxx = 0;
    for0(i, adj[0].size()) {
        maxx = max(maxx, findHeight(adj[0][i], 0));
    }
    cout<<maxx<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

