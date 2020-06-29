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
    ll a,b,c;
    cin>>a>>b>>c;

    int n;
    cin>>n;
    ll A[n];
    ll temp[n];

    for0(i, n) {
        cin>>A[i];
    }

    long double x = (-1*b)/(2*a);
    cout<<x<<endl;
    int i;
    for(i = 0; i < n; i++) {
        if(A[i] >= x) {
            break;
        }
    }
    cout<<i<<endl;
    int j = i - 1;
    int k;
    k = a < 0 ? n-1 : 0;
    ll a1, a2;
    while(j >= 0 && i < n) {
        a1 = a*(A[i]*A[i]) + b*A[i] + c;
        a2 = a*(A[j]*A[j]) + b*A[j] + c;
        if(a1 >= a2) {
            temp[k] = a1;
            k += a < 0 ? -1 : 1;
            i++;
        } else {
            temp[k] = a2;
            k += a < 0 ? -1 : 1;
            j--;
        }
    }

    while(j >= 0) {
        a2 = a*(A[j]*A[j]) + b*A[j] + c;
        temp[k] = a2;
        k += a < 0 ? -1 : 1;
        j--;
    }
    
    while(i < n) {
        a1 = a*(A[i]*A[i]) + b*A[i] + c;
        temp[k] = a1;
        k += a < 0 ? -1 : 1;
        i++;
    }

    for0(i, n) {
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

