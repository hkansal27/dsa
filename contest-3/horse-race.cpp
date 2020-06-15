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
    int n, k;
    cin>>n>>k;

    vector<int> num;
    int temp;
    for0(i, n-1) {
        cin>>temp;
       num.push_back(temp);
    }

    sort(num.begin(), num.end());

    if( k == 1) {
        cout<<0<<" "<<num[0]-1;
    } else if(k == n) {
        cout<<num[n-2]+1<<" "<<1000000<<endl;
    } else {
        cout<<num[k-2]+1<<" "<<num[k-1]-1<<endl;
    }
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

