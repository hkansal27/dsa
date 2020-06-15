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

void rev(int a[], int i, int j) {
    int temp;
    while(i < j) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;

        i++; j--;
    }
}

void LR(int a[], int i, int j) {
    rev(a, i, j);
    rev(a, i+1, j);
}

void RR(int a[], int i, int j) {
    rev(a, i, j);
    rev(a, i, j-1);
}

void permutation(int a[], int size, int index , int temp[], vector<vector<int> > &ans) {

    if(index == (size)) {
        vector<int> temp(a, a+size);

        for (vector<int>::iterator it = temp.begin(); it != temp.end(); it++) {
            cout << *it << " ";
        }
        cout<<endl;
        ans.push_back(temp);
        return;
    }

    for(int i = index; i < size; i++) {
        LR(a, index, i);
        temp[index] = a[index];
        permutation(a, size, index+1, temp, ans);
        RR(a, index, i);
    }

}


void solution() {
    int a[] = {7, 0, 8, 15};
    vector<vector<int> > ans;
    permutation(a, 4, 0, a, ans);
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

