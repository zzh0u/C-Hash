#include "hash_table.h"

// 哈希函数（仅内部使用）
static unsigned int hash(const char *key) {
    unsigned int hash_val = 0;
    int len = strlen(key);
    for (int i = 0; i < len; i++) {
        hash_val = (hash_val + key[i]) % TABLE_SIZE;
    }
    return hash_val;
}

// 创建节点（仅内部使用）
static node *create_node(const char *key, int value) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->key = strdup(key);
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// 插入键值对
void hash_table_insert(node **table, const char *key, int value) {
    unsigned int index = hash(key);
    node *new_node = create_node(key, value);
    new_node->next = table[index];
    table[index] = new_node;
}

// 查找键值对
int hash_table_search(node **table, const char *key) {
    unsigned int index = hash(key);
    node *current = table[index];
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

// 删除键值对
void hash_table_remove(node **table, const char *key) {
    unsigned int index = hash(key);
    node *current = table[index];
    node *prev = NULL;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            if (prev == NULL) {
                table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->key);
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }
}

// 打印哈希表
void print_hash_table(node **table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        node *current = table[i];
        if (current) {
            printf("Bucket %d: ", i);
            while (current) {
                printf("(%s, %d) ", current->key, current->value);
                current = current->next;
            }
            printf("\n");
        }
    }
}