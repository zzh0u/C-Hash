#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct node {
    char *key;
    int value;
    struct node *next;
} node;

// 函数声明
void hash_table_insert(node **table, const char *key, int value);
int hash_table_search(node **table, const char *key);
void hash_table_remove(node **table, const char *key);
void print_hash_table(node **table);

#endif