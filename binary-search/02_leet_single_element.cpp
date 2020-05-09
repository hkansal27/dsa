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

int singleNonDuplicate(vector<int>& nums) {
    int size = nums.size();

    if(size == 1) {
        return nums[0];
    }
    
    int l = 0, h = size -1;
    int mid, fI, sI;
    
    while(l <= h) {
        
        mid = (l+h) / 2;
        
        if(mid == 0) {
            if(nums[mid] != nums[mid + 1]) {
                break;
            } else {
                l = mid + 1;
            }
        } else if(mid == size - 1) {
            if(nums[mid] != nums[mid - 1]) {
                break;
            } else {
                h = mid - 1;
            }
        } else if((nums[mid] != nums[mid - 1]) && (nums[mid] != nums[mid+1])) {
            break;
        } else {
            if(nums[mid] != nums[mid - 1]) {
                fI = mid;
                sI = mid + 1;
            } else {
                fI = mid - 1;
                sI = mid;
            }
            
            if(fI % 2 == 0) {
                l = mid +1;
            } else {
                h = mid - 1;
            }
        }
    }
    return nums[mid];
}

void solution() {
    int arr[] = { 1,1,2,3,3,4,4,8,8 }; 
    vector<int> vect(arr, arr + 9);
    cout<<singleNonDuplicate(vect)<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

