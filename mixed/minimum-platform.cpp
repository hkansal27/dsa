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
    int n;
    cin>>n;
    int arr[n];
    int pre[2500];
    for0(i, 2500) {
        pre[i] = 0;
    }

    for0(i, n) {
        cin>>arr[i];
        pre[arr[i]]++;
    }
    int dep[n];
    for0(i, n) {
        cin>>dep[i];
        pre[dep[i] + 1]--;
    }
    int maxx = INT_MIN;
     for(int i = 1; i < 2500; i++) {
        pre[i] = pre[i] + pre[i-1];
        maxx = max(pre[i], maxx);
    }
    cout<<maxx<<endl;
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

