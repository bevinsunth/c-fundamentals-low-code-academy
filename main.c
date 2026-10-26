#include <stdio.h>
#include <kv.h>

int main (void) {
  kv_t *table = kv_init(1024);
  printf("%p\n", table);
  printf("%ld\n", table->capacity);

  kv_put(table, "hehe", "haha");
  kv_put(table, "hehe", "hoho");
  kv_put(table, "color", "blue");

char *val1 =  kv_get(table, "hehe");
char *val2 =  kv_get(table, "hoho");

  printf("%p\n", val1);
  printf("%p\n", val2);
}
