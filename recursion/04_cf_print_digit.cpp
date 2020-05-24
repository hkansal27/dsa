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

void printDigit(ll n) {
    if(n == 0) {
        return;
    }
    int x = n % 10;
    n /= 10;
    printDigit(n);
    cout<<x<<" ";
}

void solution() {
    ll n;
    cin>>n;
    if(n == 0) {
        cout<<n<<endl;
        return;
    }
    printDigit(n);
    cout<<endl;
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

