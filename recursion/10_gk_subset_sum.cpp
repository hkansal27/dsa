#include <iostream>
#include <algorithm>
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

void subsetSum(int arr[], int n, int sum, int callIndex, vector<int> &ans ) {
    if(callIndex == n) {
        ans.push_back(sum);
        return;
    }

    subsetSum(arr, n, sum, callIndex + 1, ans);
    subsetSum(arr, n, sum+arr[callIndex], callIndex + 1, ans);
}

void solution() {
    int n;
    cin>>n;

    int arr[n];
    for0(i, n) {
        cin>>arr[i];
    }
    vector<int> ans;
    subsetSum(arr, n, 0, 0, ans);
    sort(ans.begin(), ans.end());
    for (auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it << " ";
    }
    cout<<endl;
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

