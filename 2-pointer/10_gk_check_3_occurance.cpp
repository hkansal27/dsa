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
    int arr[] = {1,2,4,3,3,4,4,3,1,1};

    sort(arr, arr + 10);

    // i is slow runner and j is fast runner
    int cnt = 0, i = 0, j = 1;

    while(j < 10) {
        if(arr[j] == arr[i]) {
            cnt++;
        } else {
            if(cnt == 2) {
                cnt = 0;
                i = j;
                continue;
            }
            cout<<arr[i]<<endl;
            break;
        }
        j++;
    }
    return;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

