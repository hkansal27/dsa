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

int freq[26];
int isCount() {
    int count = 0;
    for0(i, 26){
        if(freq[i] != 0) count++;
    }

    return count;
}

void solution() {
    string str;
    int k;

    cin>>str;
    cin>>k;

    if(k > str.length()) {
        cout<<-1<<endl;
        return;
    }
    
    for0(i, 26) {
        freq[i]=0;
    }

    int i = 0, j = 0;

    while(i < (str.length())) {
        freq[str[i] - 'a']++;
        if(isCount() > k) {
            freq[str[i--] - 'a']--;
            break;
        } 
        i++;
    }
    int maxx = i - j + 1;
    // cout<<maxx<<" "<<i<<endl;

    if(i == str.length()) {
        maxx--;
    }
    i++;
    while(i < str.length()) {
        freq[str[i]-'a']++;
        // cout<<str[i]<<" "<<isCount()<<" "<<i<<" "<<j<<endl;

        while(isCount() > k) {
            freq[str[j] - 'a']--;
            j++;
        }
        maxx = max(maxx, i-j+1);
        // cout<<str[i]<<" "<<maxx<<endl;

        i++;
    }

    cout<<maxx<<endl;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

