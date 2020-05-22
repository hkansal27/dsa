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

ll maxSubArraySum(int size, int arr[], int n) {
    ll sum = 0;
    for0(i, size) {
        sum += arr[i];
    }
    ll maxx = sum;
    for(int i = 1; i < (n - size + 1); i++) {
        sum -= arr[i-1];
        sum += arr[i+size- 1];
        maxx = max(sum, maxx);
    }
    return maxx;
}

void solution() {
    int n;
    ll x;
    cin>>n>>x;

    int arr[n];
    for0(i, n) {
        cin>>arr[i];
    }

    int l = 0, h = n;
    int mid;
    ll c1, c2;

    while(l <= h) {
        mid = (l+h) / 2;
        c1 = maxSubArraySum(mid, arr, n);
        if(c1 > x) {
            h = mid - 1;
        } else {
            c2 = maxSubArraySum(mid+1, arr, n);
            if(c2>x) {
                break;
            } else {
                l = mid + 1;
            }
        }
    }
    cout<<mid<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

