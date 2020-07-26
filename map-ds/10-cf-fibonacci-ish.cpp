#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>

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

    ll arr[n];

    for0(i, n) {
        cin>>arr[i];
    }

    // <elem, freq>
    unordered_map<int, ll> mp;
    for0(i, n) {
        mp[arr[i]]++;
    }

    ll maxx = 0, a, b, c, l, temp;
    for0(i, n) {
        for0(j, n) {
            if(i != j) {
                if((arr[i] == 0) && (arr[j] == 0)) {
                    maxx = max(maxx, mp[0]);
                    continue;
                }
                a = arr[i];
                b = arr[j];
                mp[a]--;
                mp[b]--;
                l = 2;
                while((mp.find(a+b) != mp.end()) && mp[a+b] > 0) {
                    mp[a+b]--;
                    temp = b;
                    b = a+b;
                    a = temp;
                    l++;
                }
                maxx = max(maxx, l);

                // unpollute the map
                while(l > 0) {
                    mp[b]++;
                    temp = b;
                    b = a;
                    a = temp - b;
                    l--;
                }
            }
        }
    }

    cout<<maxx<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

