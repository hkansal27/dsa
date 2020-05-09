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


int mySqrt(int x) {
    int l = 0, h = x;
    long long int mid;
    
    while(l <= h) {
        mid = (l+h)/2;
        
        if(mid*mid > x) {
            h = mid -1;
        } else {
            if((mid+1)*(mid+1) > x) {
                break;
            } else {
                l = mid + 1;
            }
        }
    }
    return mid;
}

void solution() {
    int n;
    cin>>n;

    cout<<mySqrt(n)<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

