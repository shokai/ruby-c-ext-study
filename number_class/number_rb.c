#include "ruby.h"

int add(int a, int b);

VALUE wrap_add(self, aa, bb)
     VALUE self, aa, bb;
{
  int a, b, result;
  a = FIX2INT(aa);
  b = FIX2INT(bb);
  result = add(a,b);
  return INT2FIX(result);
}

void Init_number(){
  VALUE number_class;
  number_class = rb_define_class("Number", rb_cObject);
  rb_define_method(number_class, "add", wrap_add, 2);
}
