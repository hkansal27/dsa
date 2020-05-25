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

int digitSum(ll x) {
    if(x == 0) {
        return 0;
    }
    return x%10 + digitSum(x/10);
}

void superNum(ll x) {
    int y = digitSum(x);
    if(y == x) {
        cout<<x<<endl;
        return;
    }
    superNum(y);
}

void solution() {
    ll n, k;
    cin>>n>>k;
    superNum(k*digitSum(n));
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

