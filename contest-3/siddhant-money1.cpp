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
    ll n, K;
    cin>>n;
    cin>>K;
    if(K <= 0) {
        cout<<1<<endl;
        return;
    }
    int num[n];
    int temp;
    int ans(0);
    for0(i, n) {
        cin>>temp;
        num[i] = temp;
    }
    ll sum(0);

    for(int k = 0; k < K; k++) {
        for (int i = 0; i < n - k + 1; i++) { 
            int current_sum = 0; 
            for (int j = 0; j < k; j++) 
                current_sum = current_sum + num[i + j]; 
                if(current_sum == K) {
                    ans++;
                }
        } 
    }
    cout<<ans<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

