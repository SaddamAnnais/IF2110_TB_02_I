#include "set.c"
#include <stdio.h>

int main() {
  Set s;
  createSet(&s);
  addToSet(&s, 1);
  addToSet(&s, 2);
  addToSet(&s, 3);
  addToSet(&s, 1);
  displaySet(s);
  addToSet(&s, 4);
  removeFromSet(&s, 1);
  displaySet(s);
  addToSet(&s, 1);
  addToSet(&s, 4);
  displaySet(s);


  Set s2;
  createSet(&s2);
  addToSet(&s2, 2);
  addToSet(&s2, 4);
  printf("%d\n", isSubset(s2, s));
  addToSet(&s2, 5);
  printf("%d\n", isSubset(s2, s));

  return 0;
}
