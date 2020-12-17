#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct dictEntry {
    void *key;

    union {
        void *val;
        uint64_t u64;
        int64_t s64;
        double d;
    } v;

    struct dictEntry *next;
} dictEntry;

typedef struct dictht {
    dictEntry **table;
    unsigned long size;
    // equal size - 1, 为了方便计算索引值: a % b = a & (b - 1), b = 2 ^ n
    unsigned long sizemask;
    unsigned long used;
} dictht;

int main() {
    int ht_size = sizeof(dictht);
    int entry_size = sizeof(dictEntry);
    printf("dictht size is %d, entry size is %d\n", ht_size, entry_size);

    dictht *ht = (dictht *)malloc(ht_size);
    ht->table = NULL;
    ht->size = 0;
    ht->sizemask = 0;
    ht->used = 0;

    int init_size = 4;
    ht->table = malloc(init_size * sizeof(dictEntry *));
    ht->size = 4;
    ht->sizemask = 4 - 1;

    ht->table[0] = (dictEntry *)malloc(entry_size);
    ht->table[0]->key = "123";
    ht->table[0]->next = NULL;

    printf("%s\n", ht->table[0]->key);

    free(ht->table);
    free(ht);
}