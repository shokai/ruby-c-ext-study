#include "ruby.h"

int number_add(int a, int b);
int number_sub(int a, int b);
int number_mul(int a, int b);
int number_div(int a, int b);

VALUE wrap_add(self, a, b){
  return INT2FIX( number_add( FIX2INT(a), FIX2INT(b) ) );
}

VALUE wrap_sub(self, a, b){
  return INT2FIX( number_sub( FIX2INT(a), FIX2INT(b) ) );
}

VALUE wrap_mul(self, a, b){
  return INT2FIX( number_mul( FIX2INT(a), FIX2INT(b) ) );
}

VALUE wrap_div(self, a, b){
  return INT2FIX( number_div( FIX2INT(a), FIX2INT(b) ) );
}

void Init_number(){
  VALUE number_class;
  number_class = rb_define_class("Number", rb_cObject);
  rb_define_method(number_class, "add", wrap_add, 2);
  rb_define_method(number_class, "sub", wrap_sub, 2);
  rb_define_method(number_class, "mul", wrap_mul, 2);
  rb_define_method(number_class, "div", wrap_div, 2);
}
