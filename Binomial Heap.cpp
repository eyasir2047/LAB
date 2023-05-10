#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    int degree; // number of child
    Node *child; // left most child
    Node *sibling; // node at right side
    Node *parent;

    Node(int key) {
        data = key;
        degree = 0;
        child = NULL;
        sibling = NULL;
        parent = NULL;
    }
};

Node* track[1003];

// combines two binomial trees with the same degree
// root1 is combined into root2
Node* combineBinomialTrees(Node *root1, Node *root2) {
    if(root1->data < root2->data) swap(root1, root2);

    root1->parent = root2;
    root1->sibling = root2->child;
    root2->child = root1;
    root2->degree++;

    return root2;
}


Node* mergeBinomialHeaps(Node *head1, Node *head2) {
    Node *head = NULL;

    
    if(head1 == NULL && head2 == NULL) return NULL;
    else if(head2 == NULL) return head1;
    else if(head1 == NULL) return head2;
    else if(head1->degree <= head2->degree) {
        head = head1;
        head1 = head1->sibling;
    }
    else {
        head = head2;
        head2 = head2->sibling;
    }

    Node *temp = head;

    while(head1 != NULL && head2 != NULL) {
        if(head1->degree <= head2->degree) {
            temp->sibling = head1;
            temp = temp->sibling;
            head1 = head1->sibling;
        }
        else {
            temp->sibling = head2;
            temp = temp->sibling;
            head2 = head2->sibling;
        }
    }

    while(head1 != NULL) {
        temp->sibling = head1;
        temp = temp->sibling;
        head1 = head1->sibling;
    }

    while(head2 != NULL) {
        temp->sibling = head2;
        temp = temp->sibling;
        head2 = head2->sibling;
    }

    return head;
}

Node* unionBinomialHeaps(Node *head1, Node *head2) {
    Node *head = mergeBinomialHeaps(head1, head2);

    if(head == NULL || head->sibling == NULL) {
        return head;
    }

    Node *px = NULL, *x = head, *nx = head->sibling, *snx = head->sibling->sibling;

    while(nx != NULL) {
        if(x->degree != nx->degree || (snx != NULL && nx->degree == snx->degree)) {
            px = x;
            x = nx;
            nx = snx;
            if(snx != NULL) snx = snx->sibling;
        }
        else {
            x = combineBinomialTrees(x, nx);
            if(px == NULL) {
                head = x;
            }
            else {
                px->sibling = x;
            }
            x->sibling = snx;
            nx = snx;
            if(snx != NULL) snx = snx->sibling;
        }
    }

    return head;
}

void insertion(Node *&head, int key) {
    Node *newnode = new Node(key);
    track[key] = newnode;
    head = unionBinomialHeaps(head, newnode);
}

void reverseLinkedList(Node *&head) {
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        curr->parent = NULL;
        Node *temp = curr->sibling;
        curr->sibling = prev;
        prev = curr;
        curr = temp;
    }

    head = prev;
}

Node* deleteNode(Node *head, Node *node) {
    Node *px = NULL, *x = head;
    while(1) {
        if(x == node) {
            break;
        }
        px = x;
        x = x->sibling;
    }

    if(px != NULL) {
        px->sibling = x->sibling;
    }
    else {
        head = x->sibling;
    }

    Node *newHead = x->child;
    reverseLinkedList(newHead);

    track[x->data] = NULL;
    delete(x);

    return unionBinomialHeaps(head, newHead);
}

int extractMin(Node *&head) {
    Node *Min = head;
    Node *temp = head->sibling;

    while(temp != NULL) {
        if(temp->data < Min->data) {
            Min = temp;
        }
        temp = temp->sibling;
    }
    int min = Min->data;

    head = deleteNode(head, Min);

    return min;
}

int getMin(Node *head) {
    Node *Min = head;
    Node *temp = head->sibling;

    while(temp != NULL) {
        if(temp->data < Min->data) {
            Min = temp;
        }
        temp = temp->sibling;
    }

    return Min->data;
}

void decreaseKey(Node *&head, int key, int decreaseTo) {
    Node *node = track[key];
    node->data = decreaseTo;
    track[decreaseTo] = node;
    track[key] = NULL;

    while(node->parent != NULL && node->parent->data > node->data) {
        swap(node->data, node->parent->data);
        swap(track[node->data], track[node->parent->data]);
        node = node->parent;
    }
}

void deletion(Node *&head, int key) {
    decreaseKey(head, key, 0);
    head = deleteNode(head, track[0]);
}

void print(Node *head) {
    if(head == NULL) return;
    print(head->child);
    cout << head->data << ' ';
    print(head->sibling);
}

int main() {
    Node *head = NULL;
    int arr[] = {4, 6, 3, 11, 9, 5, 14, 10, 21, 7, 13, 20, 2};
    for(int i = 0; i < 13; i++) {
        insertion(head, arr[i]);
    }
    print(head); cout << '\n';

    cout << extractMin(head) << '\n';
    cout << extractMin(head) << '\n';
    print(head); cout << '\n';

    //cout << extractMin(head) << '\n';

    decreaseKey(head, 14, 3);
    print(head); cout << '\n';

    deletion(head, 20);
    print(head); cout << '\n';
}
