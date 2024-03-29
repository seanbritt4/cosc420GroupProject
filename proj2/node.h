#ifndef NODE_H
#define NODE_H

// can be used for both HashTable buckets and keyword nodes
// do we want seperate structs for each?
typedef struct Node {
    char* data;     // HashTable: unused?
                    // article node: article ids???

    int key;        // hashap: key of bucket,
                    // keyword: which bucket it belongs to

    struct Node* next; //next keyword node in bucket
} Node;

void initKeywordNode(Node* node, char* s){
    node->data = s;
    node->next = NULL;
}

void initBucket(Node* node, int k){
    node->key = k;
    node->next = NULL;
}

#endif
