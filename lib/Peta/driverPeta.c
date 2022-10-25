#include "peta.c"

int main() {
  Peta p;
  readPeta(&p, "konfigPeta.txt");
  displayPeta(p);
  moveEast(&p);
  displayPeta(p);
  moveSouth(&p);
  displayPeta(p);
  moveWest(&p);
  displayPeta(p);
  moveNorth(&p);
  displayPeta(p);
  return 0;
}