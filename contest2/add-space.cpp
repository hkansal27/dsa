#include <iostream>
#include <vector>
#include <climits>
#include <string>

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

void addSpace(string pre, char c = '1', string suffix = "") {

    if(suffix.length() == 0) {
        if(!(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
            cout<<pre<<" "<<c<<endl;
        } 
        cout<<pre<<c<<endl;
        return;
    }
    if(!(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
        string temp = pre + ' ' + c;
        addSpace(temp, suffix[0], suffix.substr(1));
    } 
    
    addSpace(pre+c, suffix[0], suffix.substr(1));

}

void solution() {
    int n;
    cin>>n;
    string str("BAABB");
    cin>>str;
    addSpace("", str[0], str.substr(1));
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

