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

void pushBottom(int x, stack<int> &st) {
    if(st.empty()) {
        st.push(x);
        return;
    }

    int a = st.top(); 
    st.pop(); 
    pushBottom(x, st);
    st.push(a);
}

void reverse(stack<int> &st) {
    if(st.empty()) {
        return;
    }
    int a = st.top(); 
    st.pop();
    reverse(st);
    pushBottom(a, st);
}

void solution() {
    stack<int> st;
    int n;
    cin>>n;

    int temp;
    for0(i, n) {
        cin>>temp;
        st.push(temp);
    }

    reverse(st);

    while(!st.empty()) {
        temp = st.top(); 
        st.pop();
        cout<<temp<<endl;
    }
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

