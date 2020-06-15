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

void transformation(ll &a, ll &b, vector<int> &temp, ll current, bool &isfind) {
    // cout<<current<<endl;
    if(current > b) {
        return;
    }

    if(current == b) {
        isfind = true;
        cout<<"YES"<<endl;
        cout<<temp.size()<<endl;

        for(int i =0; i < temp.size(); i++) {
            cout<<temp[i]<<" ";
        }
        cout<<endl;
    }
    if(isfind) return;
    temp.push_back(current*2);
    transformation(a, b, temp, current*2, isfind);
    
    if(isfind) return;
    temp.pop_back();
    temp.push_back(10*current+1);
    transformation(a, b, temp, 10*current+1, isfind);
    temp.pop_back();
}

void solution() {
    ll a,b;
    cin>>a>>b;
    vector<int> temp;
    temp.push_back(a);
    bool isfind = false;
    transformation(a,b, temp, a, isfind);

    if(!isfind) {
        cout<<"NO"<<endl;
    }
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

