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

int A[10000000];

void merge(int arr[], int s1, int e1, int s2, int e2) {

    int i = s1, j = s2, k = s1;

    while(i<=e1 && j<=e2) {
        if(arr[i] <= arr[j]) {
            A[k++] = arr[i++];
        } else {
            A[k++] = arr[j++];
        }
    }

    while(i<=e1) {
        A[k++] = arr[i++];
    }

    while(j<=e2) {
        A[k++] = arr[j++];
    }

    for(int p = s1; p <= e2; p++) {
        arr[p] = A[p];
    }
}

void mergeSort(int arr[], int i, int j) {

    if(i==j) return;
    int m=(i+j)/2;
    mergeSort(arr,i,m);
    mergeSort(arr,m+1,j);
    merge(arr,i,m,m+1,j);
}

void solution() {
    int n;
    cin>>n;

    int arr[n];
    for0(i, n) {
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);

    for0(i, n) {
        cout<<arr[i]<<endl;
    }
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

