//
// Created by james on 10/17/17.
//

#include "obj/list.h"

void list_clean(aobj id);

static aobj_meta_s list_meta = {
    .isa = FOUR_CHARS_TO_INT('L', 'I', 'S', 'T'),
    .refcnt = 0,
    .clean = list_clean,
};

aobj list_init(void *ptr, void *data) {
  list_t id = aobj_init(ptr, &list_meta);
  if (id) {
    id->car = id->cdr = NULL;
  }
  return id;
}

void list_clean(aobj id) {
  if (TAGGED_AOBJECT(id)) {
    list_t con = id;
    _release(con->car);
    _release(con->cdr);
    // TODO: optimize recursion for avoid stack overflow
  }
}

list_t list_cons(aobj a, aobj b) {
  list_t con = aobj_alloc(list_s, list_init);
  if (con != NULL) {
    _retain(a);
    con->car = a;
    _retain(b);
    con->cdr = b;
  }
  return con;
}

aobj list_car(list_t list) {
  return list->car;
}

aobj list_cdr(list_t list) {
  return list->cdr;
}