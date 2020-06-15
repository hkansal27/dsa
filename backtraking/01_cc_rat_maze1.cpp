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
vector<pair<char, pair<int, int>>> path{ {'D', {1,0}}, {'R', {0,1}}, {'L', {0,-1}}, {'U', {-1,0}} };

int maze[10][10];


void findPath(int i, int j, vector<char> &ans) {

    if(maze[i][j]) return;

    if((i == n-1 )&& (j = n-1)) {
        // for(auto &c: ans) {
        //     cout<<c;
        // }
        cout<<"Hi"<<endl;
        return;
    }

    int temp = maze[i][j];
    for(int k = 0; k < path.size(); k++) {
        if(!maze[i+path[k].second.first][j+path[k].second.second]) {
            ans.push_back(path[k].first);
            findPath(i+path[k].second.first, j+path[k].second.second, ans);
            ans.pop_back();
        }
    }
    maze[i][j] = temp;

    return;
}

void solution() {
    cin>>n;

    for0(i, n) {
        for0(j, n) {
            cin>>maze[i][j];
        }
    }

    vector<char> ans;
    findPath(0,0,ans);
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

