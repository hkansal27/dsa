#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
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

vector<string> words;
string word, wd;
char boggle[7][7];
int n, m;

vector<pair<int,int> > dir;

bool isSafe(int i, int j, int index) {
    if((i >= 0 && i < n) && (j >= 0 && j <m) && (boggle[i][j] == wd[index])) return true;
    return false;
}
bool isFind = false;
vector<string> ans;
void exploreWord(int i, int j, int index) {
    if(isFind) return;
    if(index == wd.size()-1) {
        ans.push_back(wd);
        isFind = true;
        return;
    }
    char c = boggle[i][j];
    boggle[i][j] = '*';
    for(int k = 0; k < dir.size(); k++) {
        if(isSafe(i+dir[k].first, j+dir[k].second, index+1)) {
            exploreWord(i+dir[k].first, j+dir[k].second, index+1);
            if(isFind) return;
        }
    }
    boggle[i][j] = c;
    return;
}

void solution() {
    int w;
    cin>>w;
    ans.clear();
    for0(i, w) {
        cin>>word;
        words.push_back(word);
    }
    cin>>n>>m;
    for0(i, n) {
        for0(j, m) {
            cin>>boggle[i][j];
        }
    }

    for0(k, w) {
        isFind = false;
        for0(i, n) {
            for0(j, m) {
                wd = words[k];
                if(words[k][0] == boggle[i][j]) {
                    exploreWord(i, j, 0);
                }
            }
        }
    }
    if(ans.size() == 0) {cout<<-1<<endl; return;}
    sort(ans.begin(), ans.end());
    for0(i, ans.size()) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int t(1);
    // {0,1}, {1,1},{1,0}, {1,-1}, {0,-1},{-1,-1}, {-1,0}, {-1,1}
    dir.push_back(make_pair(0,1));
    dir.push_back(make_pair(1,1));
    dir.push_back(make_pair(1,0));
    dir.push_back(make_pair(1,-1));
    dir.push_back(make_pair(0,-1));
    dir.push_back(make_pair(-1,-1));
    dir.push_back(make_pair(-1,0));
    dir.push_back(make_pair(-1,1));
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

