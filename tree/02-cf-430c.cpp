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

vector<int> adj[100009];
bool init[100009], goal[100009];
vector<int> ans;

void cntFlips(int node, int parent, int pFlipCnt, int gFlipCnt) {

    int isFlip = 0;
    if(gFlipCnt & 1) {
        init[node] = !init[node];
    }

    if(init[node] != goal[node]) {
        isFlip = 1;
        ans.pb(node);
    }

    for(int i = 0; i < adj[node].size(); i++) {
        if(adj[node][i] != parent) {
            cntFlips(adj[node][i], node, gFlipCnt + isFlip, pFlipCnt);
        }
    } 
}

void solution() {
    int n;
    cin>>n;

    int x,y;
    for0(i, n-1) {
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    bool temp;
    for0(i, n) {
        cin>>temp;
        init[i+1] = temp;
    }
    for0(i, n) {
        cin>>temp;
        goal[i+1] = temp;
    }

    cntFlips(1, 0, 0, 0);

    cout<<ans.size()<<endl;
    for(auto i: ans) {
        cout<<i<<endl;
    }
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

