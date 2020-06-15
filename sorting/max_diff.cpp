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

    int w[n];
    ll sum(0);
    for0(i, n) {
        cin>>w[i];
        sum += w[i];
    }

    // sort the input weights -- insertion sort
    int j;
    for(int i = 1; i < n; i++) {
        j =  i;
        while(j && w[j] < w[j-1]) {
            swap(w[j], w[j-1]);
            j--;
        }
    }
    int sumK(0);
    if(k <= n/2) {  
        for(int i = 0; i < k; i++) {
            sumK += w[i];
        }
    } else {
        for(int i = 0; i < (n-k); i++) {
            sumK += w[i];
        }
    }
    cout<<(sum - 2*sumK)<<endl;
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

