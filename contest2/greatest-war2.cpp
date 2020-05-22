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

int countGreaterEqualThan(int elem, int arr[], ll n) {
    int c(0);
    for0(i, n) {
        if(arr[i] >= elem) {
            c++;
        }
    }
    return c;
}
void solution() {
    int n, k;
    cin>>n>>k;
    if(k > n) {
        cout<<0<<endl;
        return;
    }
    int arr[n], minn = INT_MAX, maxx = INT_MIN;

    for0(i, n) {
        cin>>arr[i];
        minn = min(minn, arr[i]);
        maxx = max(maxx, arr[i]);
    }

    int l = minn, h = maxx, mid;
    int c1, c2;
    while(l <= h) {
        mid = (l+h)/2;
        c1 = countGreaterEqualThan(mid, arr, n);
        if( c1 >= k) {
            c2 = countGreaterEqualThan(mid+1, arr, n);
            if(c2 < k) {
                break;
            }
            l = mid + 1;
        } else {
            h = mid - 1;
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
