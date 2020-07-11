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
    int n, m, l;

    cin>>n>>m>>l;
    int arr1[n], arr2[m], arr3[l];
    for0(i, n) {
        cin>>arr1[i];
    }
    for0(i, m) {
        cin>>arr2[i];
    }
    for0(i, l) {
        cin>>arr3[i];
    }

    int i = 0, j = 0, k = 0;
    int ans = INT_MAX, sol, a;
    while((i<n) && (j<m) && (k<l)) {
        sol = max(arr1[i], max(arr2[j], arr3[k])) - min(arr1[i], min(arr2[j], arr3[k]));
        ans = min(ans, sol);
        a = min(arr1[i], min(arr2[j], arr3[k]));
        if(a == arr1[i]) i++;
        else if(a == arr2[j]) j++;
        else k++;
    }

    if(ans == INT_MAX) {
        cout<<-1<<endl;
    } else {
        cout<<ans<<endl;
    }
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

