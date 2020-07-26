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
    int n;
    cin>>n;

    int arr[n+2];
    arr[0] = 0;
    for0(i, n) {
        cin>>arr[i+1];
    }
    arr[n+1] = 0;

    string temp;
    int index = 0;
    for(int i = 0; i < n+1; i++) {
        if(max(arr[i], arr[i+1]) == 0) {
            temp += 'a' + index;
            index++;
        } else {
            int x = i == 0 ? arr[i+1] : arr[i];
            for(int j = 0; j < x ; j++) {
                char c = 'a' + (j % 25);
                temp += c;
            }
        }
        cout<<temp<<endl;
        temp = "";
    }
}

int main() {
    int t(1);
    cin>>t;
    while (t--) {solution();}
    return 0 ;
}

