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
int maze[10][10];

bool isSafe(int i, int j) {
    if((i >= 0 && i < n) && ( j >= 0 && j < n) && maze[i][j]) return true;
    return false;
}

void findPath(int i, int j, vector<char> &path) {
    if(!maze[i][j]) return;
    if( i == n-1 && j == n-1) {
        // print 
        for(vector<char>::iterator it = path.begin(); it != path.end(); it++) {
            cout<<*it;
        }
        cout<<" ";
        return;
    }

    maze[i][j] = 0;

    // down
    if(isSafe(i+1, j)) {
        path.push_back('D');
        findPath(i+1, j, path);
        path.pop_back();
    }

    // left
    if(isSafe(i, j-1)) {
        path.push_back('L');
        findPath(i, j-1, path);
        path.pop_back();
    }

    // right
    if(isSafe(i, j+1)) {
        path.push_back('R');
        findPath(i, j+1, path);
        path.pop_back();
    }

    // up
    if(isSafe(i-1, j)) {
        path.push_back('U');
        findPath(i-1, j, path);
        path.pop_back();
    }

    maze[i][j] = 1;
    return;
}

void solution() {
    cin>>n;
    for0(i, n) {
        for0(j, n) {
            cin>>maze[i][j];
        }
    }
    vector<char> path;
    findPath(0,0, path);
    cout<<endl;
    return;
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

