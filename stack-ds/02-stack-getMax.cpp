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

stack<int> st;
int currMax = INT_MIN;

void solution() {
    int t, num;
    cin>>t;

    if(t == 1) {
        cin>>num;
        if(st.empty()) {
            st.push(num);
            currMax = num;
            return;
        }
        if(currMax >= num) {
            st.push(num);
            return;
        }
        st.push(2*num - currMax);
        currMax = num;
    } else if(t == 2) {
        if(st.top() > currMax) {
            currMax = (2 * currMax -  st.top());
        }
        st.pop();
    } else {
        cout<<currMax<<endl;
    }
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

