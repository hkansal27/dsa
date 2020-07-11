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
    ll k, z, x;
    cin>>k>>z>>x;

    float a = 0, b = 0, total = 0;
    bool flag = false;
    // for a 
    if(a + k >= (x- b/2)) {
        float a1 = (x- b/2) - a;
        a += a1;
        flag = true;
    } else {
        a += k;
    }
    if(!flag) {
        b += (z*((int)(total/z) + 1) - total);
    }
    total = a + b;
    int temp = x/((int)total);
    a *= temp;

    b *= temp;
    total = a + b;

    if(a + k >= (x- b/2)) {
        // cout<<a<<" "<<b<<endl;
        float a1 = (x- b/2) - a;
        a += a1;
        // cout<<a1<<" "<<a<<endl;
        flag = true;
    } else {
        a += k;
    }
    if(!flag) {
        b += (z*((int)(total/z) + 1) - total);
    }
    total = a+b;
    cout<<total<<endl;

}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}