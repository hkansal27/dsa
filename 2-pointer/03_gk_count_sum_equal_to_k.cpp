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
    int n,k;

    cin>>n>>k;
    int arr[n];

    for0(i, n) {
        cin>>arr[i];
    }


    sort(arr, arr+n);

    int cnt = 0, i = 0, j = n - 1;

    int f1 = 0, f2 = 0, p1, p2;

    while(i < j) {
        if(arr[i] + arr[j] < k) {
            i++;
        } else if(arr[i] + arr[j] > k){
            j--;
        } else {
            if(arr[i] == arr[j]) {
                cnt += ((j-i+1)*(j-i))/2;
                break;
            } else {
                f1 = 0, f2 = 0, p1 = arr[i], p2 = arr[j];
                while(arr[i] == p1) {
                    i++, f1++;
                }
                while(arr[j] == p2) {
                    j--, f2++;
                }
                cnt += f1*f2;
            }
        }
    }

    cout<<cnt<<endl;
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

