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

void printUniqueCombination(int n, int k, int temp[], int tempSize, int index) {
    
    if(tempSize == k ) {
        // print array
        for(int i = 0; i < tempSize; i++) {
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        return;
    } 
    
    if( index > n) {
        return;
    }

    printUniqueCombination(n, k, temp, tempSize, index+1);
    temp[tempSize] = index;
    printUniqueCombination(n, k, temp, tempSize+1, index+1);
}

void solution() {
    int n, k;
    cin>>n>>k;
    int temp[k];
    printUniqueCombination(n, k, temp,0,1);
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

