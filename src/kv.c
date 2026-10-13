#include <stdlib.h>
#include <kv.h>
#include <string.h>
 
#define TOMBSTONE 0x1

size_t hash(char *value, size_t capacity)
{
  size_t hash = 0x1222222DEADBEEF;

  while(*value)
  {
    hash ^= *value;
    hash = hash << 8;
    hash += *value;
    
    value++;
  }

  return hash % capacity;
}

int kv_put(kv_t *db, char *key, char *value)
{
  if (!db || !key || !value)
    return -1;
  size_t index = hash(key, db->capacity);
  for(int i=0; i<db->capacity; i++)
  {
  size_t real_idx = (index+1) % db->capacity;
   kv_entry_t *entry = &db->entries[real_idx];
  if(entry->key &&
    entry->key != (void*)TOMBSTONE &&
   !strcmp(entry->key, key))
  {
    char *newval =strdup(value);
      if(!newval) return -1;
      entry->value =  newval;
  }
  if(!entry->key || entry->key == (void*)TOMBSTONE) {
    char *newval =strdup(value);
    char *newkey = strdup(key);
      if(!newval | !newkey)
    {
      free(newkey);
      free(newval);
    }
      entry->value =  newval;
    entry->key  = newkey;
    db->count++;
    return real_idx;
  }
return -1;
  }
}

kv_t *kv_init(size_t capacity)
{
  if(capacity == 0) return NULL;

  kv_t *table  = malloc(sizeof(kv_t));
  if(table == NULL){
    return NULL;
  }

  table->capacity = capacity;
  table->count = 0;
 
  table->entries = calloc(sizeof(kv_entry_t), capacity);
  if (table->entries == NULL) {
    return NULL;
  }
  return table;
}
