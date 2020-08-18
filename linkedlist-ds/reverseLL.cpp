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


    //    if((head -> next == nullptr)) return head;
        
    //     ListNode *temp = head -> next;
    //     head -> next = NULL;
        
    //     ListNode* newHead = reverseList(temp);
        
    //     temp->next = head;
        
    //     return newHead;

Node* reverseLL(Node *head) {

    if(!head || head -> next == nullptr) return head;

    Node *temp = head -> next;
    head -> next = nullptr;

    Node *tail = reverseLL(temp);

    temp -> next = head;

    return tail;
}

// reverse a LL
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
    Node *h = head;

    int sum;
    cin>>sum;

    while(h && h -> val < sum/2) {
        h = h -> next;
    }

    // handle corner case, even sum
    if(h && h -> next && (h -> val == sum/2)) {
        h = h -> next;
    } else {
        cout<<"Not found"<<endl;
        return;
    }

    Node *tail = reverseLL(h);

    while(head != tail) {
        temp = head -> val + tail -> val;
        if(temp == sum) {
            cout<<"Pair is ("<<head -> val<<", "<<tail -> val<<")"<<endl;
            return;
        } else if(temp < sum) {
            head = head -> next;
        } else {
            tail = tail -> next;
        }
    }

    cout<<"not found"<<endl;
    return;
}

int main() {
    int t(1);
    // cin>>t;
    while (t--) {solution();}
    return 0 ;
}

