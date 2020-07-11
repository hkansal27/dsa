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
    int n, q;
    cin>>n>>q;

    ll arr[n];

    for0(i, n) {
        cin>>arr[i];
    }

    sort(arr, arr+n);

    ll temp;
    for0(i, q) {
        cin>>temp;

        if(temp <= arr[0]) {
            cout<<-1<<endl;
            continue;
        }

        if(temp >= arr[n-1]) {
            cout<<-1<<endl;
            continue;
        }

        ll l = 0, h = n - 1;
        ll mid;

        while(l <= h) {
            mid = (l+h) / 2;

            if(arr[mid] == temp) break;
            else if(arr[mid] > temp) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if(l > h) {
            cout<<(arr[l] - arr[h])<<endl;
        } else  {
            int l2 = mid, h2 = mid;
            while(arr[l2] == arr[mid]) {
                l2--;
            }
            while(arr[h2] == arr[mid]) {
                h2++;
            }
            // cout<<"Hi"<<endl;
            // cout<<mid<<endl;
            // cout<<h2<<" "<<l2<<endl;
            cout<<(arr[h2] - arr[l2])<<endl;
        }
    }
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

