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
    int n, m;
    cin>>n>>m;

    int arr[n];

    // finding sliding window
    int sum(0), i(0);
    while(sum < m) {
        sum += arr[i++];
    }

    if(sum == m) {
        cout<<0<<" "<<i-1<<endl;
    }

}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

