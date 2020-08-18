#include <iostream>
#include <vector>
#include <climits>
#include <stack>

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
    string s;
    cin>>s;

    stack<char> st;

    for0(i, s.size()) {
        if(!st.empty() && st.top() == s[i]) {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    stack<char> temp;

    while(!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    while(!temp.empty()) {
        cout<<temp.top();
        temp.pop();
    }
    cout<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

