#include <stdlib.h>

#define TABLE_SIZE 10007

typedef struct Node {
    int key;           // number
    int index;         // its index
    struct Node* next; // for collision handling
} Node;

// Hash function
int hash(int key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE;
}

// Insert into hash table
void insert(Node* table[], int key, int index) {
    int h = hash(key);
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->index = index;
    newNode->next = table[h];
    
    table[h] = newNode;
}

// Search in hash table
int find(Node* table[], int key) {
    int h = hash(key);
    Node* temp = table[h];
    
    while (temp) {
        if (temp->key == key)
            return temp->index;
        temp = temp->next;
    }
    
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    Node* table[TABLE_SIZE] = {0};
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        int index = find(table, complement);
        
        if (index != -1) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = index;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
        
        insert(table, nums[i], i);
    }
    
    *returnSize = 0;
    return NULL; // as per problem, won't happen
}