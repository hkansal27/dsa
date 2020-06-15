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

ll num;
vector<ll> ans;
void findNum(int f5, int n9, int tD, ll temp) {

    if(temp >= num && f5 == n9) {
        ans.push_back(temp);
        return;
    }

    if(f5 + n9 == tD) {
        return;
    }

    temp *= 10;
    temp += 5;
    findNum(f5+1, n9, tD, temp);

    temp /= 10;
    temp *= 10;
    temp += 9;
    findNum(f5, n9+1, tD, temp);
    temp /= 10;
}

void solution() {
    cin>>num;
    ll temp = num;
    int count(0);
    while(temp != 0) {
        count++;
        temp /= 10;
    }
    findNum(0, 0, count+1, 0);

    sort(ans.begin(), ans.end());
    cout<<ans[0]<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

