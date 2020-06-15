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


void func(vector<int> nums, int rs, int index, int &sum) {
    if(rs == 0) {
        sum++;
        return;
    }

    if(index == nums.size()) {
        return;
    }

    for(int i = 0; i <= rs/nums[index]; i++) {
        func(nums, rs - i*nums[index], index + 1, sum);
    }
    return;
}

int combinationSum4(vector<int>& nums, int target) {
    int sum(0);
    vector<int> temp;
    for0(i, nums.size()) {
        temp.push_back(0);
    }
    func(nums, target, 0, sum);
    return sum;
}

void solution() {
    vector<int> nums;
    // 2,3,5
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    int k = 4;
    cout<<combinationSum4(nums, k)<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

