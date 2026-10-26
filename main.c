#include <stdio.h>
#include <kv.h>

int main(void) {
    kv_t *table = kv_init(1024);
    printf("%p\n", table);
    printf("%ld\n", table->capacity);

    kv_put(table, "hehe", "hoho");
    kv_put(table, "color", "blue");
    kv_put(table, "protein", "egg");
    char *val1 = kv_get(table, "hehe");
    char *val2 = kv_get(table, "color");
    char *val3 = kv_get(table, "protein");

    printf("%s\n", val1);
    printf("%s\n", val2);
    printf("%s\n", val3);
}
