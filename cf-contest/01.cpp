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
    int n, m;
    cin>>n>>m;

    int a[n], b[m];
    for0(i, n) {
        cin>>a[i];
    }

    for0(i, m) {
        cin>>b[i];
    }

    sort(a, a+n);
    sort(b, b+m);

    int i = 0, j = 0;

    bool isFind = false;

    while(i < n && j < m) {
        if(a[i] < b[j]) {
            i++;
        } else if(a[i] > b[j]) {
            j++;
        } else {
            cout<<"Yes"<<endl;
            cout<<1<<" "<<a[i]<<endl;
            isFind = true;
            break;
        }
    }

    if(!isFind) {
        cout<<"No"<<endl;
    }
    return;
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

