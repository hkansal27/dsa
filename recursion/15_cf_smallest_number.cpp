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

vector<char> ops(3);
ll ans(LLONG_MAX);

vector<ll> funt(vector<ll> nums, int i, int j, char op) {
    vector<ll> temp;
    ll t = op == '+' ? (nums[i] + nums[j]) : (nums[i]*nums[j]);
    temp.push_back(t);

    for(int k = 0; k < nums.size(); k++) {
        if((k != i) && (k != j)) {
            temp.push_back(nums[k]);
        }
    }
    return temp;
}

void smallestComputation(vector<ll> nums, int index, ll &ans) {
    if(index == 3) {
        ans = min(nums[0], ans);
        return;
    }
    vector<ll> temp;
    for(int i = 0; i < nums.size() - 1; i++) {
        for(int j = i+1; j < nums.size(); j++) {
            temp = funt(nums, i, j, ops[index]);
            smallestComputation(temp, index+1, ans);
        }
    }

}

void solution() {
    vector<ll> nums(4);
    for0(i, 4) {
        cin>>nums[i];
    }

    for0(i, 3) {
        cin>>ops[i];
    }

    smallestComputation(nums, 0, ans);
    cout<<ans<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

