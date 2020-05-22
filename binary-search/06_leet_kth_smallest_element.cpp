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

  
// Returns factorial of n 
int fact(int n) 
{ 
    int res = 1; 
    for (int i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
} 

int nCr(int n, int r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 


int smallestDistancePair(int nums[], int k, int size) {
    int maxx = INT_MIN, minn = INT_MAX;
    for0(i, size) {
        maxx = max(nums[i], maxx);
        minn = min(nums[i], minn);
    }

    int freq[maxx+1], prefix[maxx+1];

    for0(i, maxx+1) {
        freq[i] = 0;
        prefix[i] = 0;
    }
    for0(i, size) {
        freq[nums[i]]++;
    }

    // find prefix array
    prefix[0] = freq[0];
    for(int i = 1; i <= maxx; i++) {
        prefix[i] = prefix[i-1] + freq[i];
    }

    int l = 0, h = maxx - minn;
    cout<<l<<" "<<h<<endl;
    int mid, c1, c2;
    while(l <= h) {
        mid = (l+h)/2;
        cout<<"mid"<<mid<<endl;
        // find the count that have distance less than or equal to mid
        c1=0;
        for(int i = 0; i < (maxx - mid +1); i++) {
            if(freq[i] > 0) {
                int temp = ((prefix[i+mid]) - ((i == 0) ? 0 : prefix[i - 1]));
                c1 += nCr(temp, 2);
            }
        }
        cout<<c1<<" c1"<<endl;
        if(c1 > k) {
            h = mid - 1;
        } else {
            c2=0;
            for(int i = 0; i < (maxx - mid); i++) {
                if(freq[i] > 0) {
                    int temp = ((prefix[i+mid+1]) - ((i == 0) ? 0 : prefix[i - 1]));
                    c2 += nCr(temp, 2);
                }
            }
            if(c2 > k) {
                cout<<"Hi"<<mid<<endl;
                break;
            } else {
                l = mid + 1;
            }
        }
    }

    return 0;
}

void solution() {
    int n(6);
    // cin>>n;

    int arr[] = {1,3,1};

    // for0(i, n) {
    //     cin>>arr[i];
    // }
    int k(7);
    // cin>>k;
    smallestDistancePair(arr, k, n);
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

