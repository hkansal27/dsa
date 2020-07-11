#include <iostream>
#include <vector>
#include <climits>
#include <algorithm> 

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
    int arr[n];

    for0(i, n) {
        cin>>arr[i];
    }

    // sort the array
    sort(arr, arr+n);

    // use two pointer
    int i = 0, j = n - 1;
    while(i < j) {
        if(arr[i] + arr[j] < k) {
            i++;
        } else if(arr[i] + arr[j] > k) {
            j--;
        } else {
            cout<<"Yes"<<endl;
            break;
        }
    }
    if(i >= j) {
        cout<<"No"<<endl;
    }
    return;
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

