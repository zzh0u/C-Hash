#include "hash_table.h"

int main() {
    node *table[TABLE_SIZE] = {NULL};  // 所有元素设置为 NULL

    hash_table_insert(table, "Ming", 20);
    hash_table_insert(table, "zzh0u", 21);
    hash_table_insert(table, "Mephisto", 22);
    hash_table_insert(table, "Jolan", 23);
    hash_table_insert(table, "templari", 23);

    printf("search Ming's age: %d\n", hash_table_search(table, "Ming"));

    print_hash_table(table);

    hash_table_remove(table, "zzh0u");
    printf("zzh0u's age after removal: %d\n",hash_table_search(table, "zzh0u"));

    return 0;
}