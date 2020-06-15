#include <iostream>
#include <vector>
#include <climits>

#define for0(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

vector<pair<int, int> > dir;
int maze[10][10];
int n, temp;

bool isSafe(int i, int j) {
    if( (i >= 0 && i < n) && (j >= 0 && j < n) && (maze[i][j] > 0 || (i == n-1 && j == n -1))) return true;
    return false;
}

bool isFind = false;
int minn = INT_MIN;

void funct(int i, int j, int hop) {
    if(i == n-1 && j == n-1) {
        maze[i][j] = -1;
        for0(i, n) {
            for0(j, n) {
                if(maze[i][j] == -1) {
                    cout<<1<<" ";
                } else {
                    cout<<0<<" ";
                }
            }
            cout<<endl;
        }
        isFind = true;
        return;
    }

    temp = maze[i][j];
    maze[i][j] = -1;

    for(int k = 0; k < dir.size(); k++) {
        for(int l = temp; l > 0; l--) {
            if(isSafe(i+(dir[k].first*l), j+(dir[k].second*l))) {
                // cout<<i+(dir[k].first*l)<<" "<<j+(dir[k].second*l)<<endl;
                funct(i+(dir[k].first*l), j+(dir[k].second*l), hop+1);
                if(isFind) return;
            }
        }
    }
    maze[i][j] = temp;
    return;
}

void solution() {
    isFind = false;
    cin>>n;
    for0(i, n) {
        for0(j, n) {
            cin>>maze[i][j];
        }
    }  
    funct(0,0,0);
    if(!isFind) cout<<-1<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    dir.push_back(make_pair(0,1));
    dir.push_back(make_pair(1,0));
    while (t--) {solution();}
    return 0 ;
}

