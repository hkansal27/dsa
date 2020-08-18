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
    int n;
    cin>>n;

    stack<int> side;

    int sNo = 1;
    int temp;

    for0(i, n) {
        cin>>temp;
        if(temp != sNo) {
            while(!side.empty()) {
                if(side.top() == sNo) {
                    side.pop();
                    sNo++;
                } else {
                    break;
                }
            }
            side.push(temp);
        } else {
            sNo++;
        }
    }
    cin>>temp;

    while(!side.empty()) {
        if(side.top() == sNo) {
            side.pop();
            sNo++;
        } else {
            break;
        }
    }

    if(side.empty()) {
        cout<<"yes"<<endl;
    } else {
        cout<<"no"<<endl;
    }
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

