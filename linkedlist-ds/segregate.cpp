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

struct Node {
    int val;
    struct Node *next;
};

typedef struct Node Node;

void printList(Node *node) { 
    while(node) { 
        cout<<(node -> val)<<endl; 
        node = node->next; 
    } 
} 

void solution() {
    int n;
    cin>>n;

    int temp;
    Node* head = (Node*)malloc(sizeof(Node));
    cin>>temp;
    head -> val = temp;
    head -> next = nullptr;

    Node *prev = head;

    for(int i = 0; i< (n - 1); i++) {
        Node* node = (Node*)malloc(sizeof(Node));
        cin>>temp;
        node -> val = temp;
        node -> next = nullptr;
        prev -> next = node;
        prev = node;
    }

    Node *e(nullptr), *o(nullptr), *et(nullptr), *ot(nullptr);

    Node *h = head;

    while(h) {
        if((h -> val) & 1) {
            if(!o) {
                o = h;
                ot = h;
            } else {
                ot -> next = h;
                ot = h;
            }
        } else {
            if(!e) {
                e = h;
                et = h;
            } else {
                et -> next = h;
                et = h;
            }
        }
        h = h -> next;
    }
    if(ot) ot -> next = nullptr;
    if(et) et -> next = nullptr;

    if(o && e) et -> next = o;
    if(!e) e = o;

    printList(e);
    return;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

