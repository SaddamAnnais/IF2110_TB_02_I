#include "peta.h"
#include <stdio.h>

int main() {
  Peta p;
  Simulator s;
  STARTWORD();
  CreateSimulator(&s, currentWord);
  readPeta(&p, "./Peta/konfigPeta.txt", &s);
  displayLokasi(s);
  displayPeta(p);

  moveSouth(&p, &s);
  displayLokasi(s);
  displayPeta(p);
  moveEast(&p, &s);
  displayLokasi(s);
  displayPeta(p);
  moveNorth(&p, &s);
  displayLokasi(s);
  displayPeta(p);
  moveWest(&p, &s);
  displayLokasi(s);
  displayPeta(p);

  printf("%d\n", isNearMixing(p, s));
  moveSouth(&p, &s);
  displayLokasi(s);
  displayPeta(p);
  printf("%d\n", isNearMixing(p, s));
  moveSouth(&p, &s);
  displayLokasi(s);
  displayPeta(p);
  moveEast(&p, &s);
  displayLokasi(s);
  displayPeta(p);

  return 0;
}