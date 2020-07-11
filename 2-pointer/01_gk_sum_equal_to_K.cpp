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
    vector<int> nums;
    nums.pb(5);
    nums.pb(4);
    nums.pb(-1);
    nums.pb(6);
    nums.pb(10);
    nums.pb(9); 
    nums.pb(7);
    nums.pb(5);

    int k = 10, q;

    sort(nums.begin(), nums.end());

    int i = 0, j = nums.size(), mid;

    for(int p = 0; p < nums.size(); p++) {
        q = k - nums[p];
        i = p+1;
        j = nums.size() - 1;

        while(i <= j) {
            mid = (i+j) / 2;
            if(nums[mid] > q) {
                j = mid - 1;
            } else if(nums[mid] < q) {
                i = mid + 1;
            } else {
                cout<<"find"<<endl;
                break;
            }
        }
    }
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

