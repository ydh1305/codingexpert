#include <iostream>
using namespace std;

#define HASH_SIZE 100000
#define PN 23

struct Node {
    int data;
    Node *next;
};
Node node[HASH_SIZE];

struct Bucket {
    int count;
    Node *head;
};
Bucket hash_table[HASH_SIZE];

int idx;
Node *create(void) {
    return &node[idx++];
}

unsigned int get_key(int data) {
    unsigned int key = 0, p = PN;
    if(data < 0) data *= -1;
    key += data * p;
    return key % HASH_SIZE;
}

void insert(int data) {
    unsigned int key = get_key(data);
    Node *newNode = create(); 
    newNode->data = data;
    if(hash_table[key].count != 0)
        newNode->next = hash_table[key].head;
    hash_table[key].head = newNode;
    hash_table[key].count++;
}

int find(int data) {
    unsigned int key = get_key(data);
    Node *cur = hash_table[key].head;
    while(cur) {
        if(cur->data == data) return 1;
        cur = cur->next;
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N;
    for(register int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        insert(tmp);
    }
    cin >> M;
    for(register int i = 0; i < M; i++) {
        int tmp; cin >> tmp;
        cout << find(tmp) << '\n';
    }

    return 0;
}
