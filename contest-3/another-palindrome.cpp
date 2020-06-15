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

void solution() {
    int n;
    cin>>n;

    string s;
    cin>>s;

    int i = 0, j = n-1;
    bool isFind = false;
    while(i < j) {
        if(s[i] == s[j] || s[i] == '?' || s[j] == '?') {
            i++; j--;
            continue;
        }
        else {
            i++; j--;
            isFind = true;
            break;
        }
    }

    if(isFind) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
    }
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

