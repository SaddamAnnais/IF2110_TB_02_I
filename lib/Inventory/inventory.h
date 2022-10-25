/* File: inventory.h */
/* Definisi ADT Inventory */

#ifndef inventory_H
#define inventory_H

#include "../priorityQueueDin/prioqueuedin.h"

typedef PrioQueueTime Inventory;

/* ************ Prototype ************ */
/* *** KONSTRUKTOR *** */
void createInventory(Inventory *I);
/* I.S. Sembarang */
/* F.S. Terbentuk Queue Inventory kosong. */

// Semua operasi yang ada di PrioQueueDin digunakan pada inventory

#endif