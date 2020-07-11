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

    int arr[n], pre[n+1];
    pre[0] = 0;
    for0(i, n) {
        cin>>arr[i];
        pre[i+1] = pre[i] + arr[i];
    }

    // now have presum n+1
    int i = 1, j = 1;
    while(j <= n) {
        // cout<<i<<" "<<j<<endl;
        if((pre[j] - pre[i-1]) == k) {
            cout<<i<<" "<<j<<endl;
            break;
        } else if((pre[j] - pre[i-1]) < k) {
            j++;
        } else {
            if(j-i == 0) {
                j++;
            }
            i++;
        }
    }
    if(j > n) {
        cout<<-1<<endl;
    }
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

