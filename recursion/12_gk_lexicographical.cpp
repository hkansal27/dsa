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

void printLexiographical(string str, int index, char temp[], int len) {

    if(len > 0 ) {
        for(int i = 0; i < len; i++) {
            cout<<temp[i];
        }
        cout<<endl;
    }

    if(index == str.size()) {
        return;
    }
    for(int i = index; i < str.size(); i++) {
        temp[index] = str[i];
        printLexiographical(str, i+1, temp, len+1);
    }
}

void solution() {
    string str;
    cin>>str;
    sort(str.begin(), str.end());
    char temp[str.size()];
    printLexiographical(str, 0, temp, 0);
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}
