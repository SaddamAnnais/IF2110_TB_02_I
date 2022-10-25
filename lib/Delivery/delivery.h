/* File: inventory.h */
/* Definisi ADT Inventory */

#ifndef delivery_H
#define delivery_H

#include "../priorityQueueDin/prioqueuedin.h"

typedef PrioQueueTime Delivery;

/* ************ Prototype ************ */
/* *** KONSTRUKTOR *** */
void createDelivery(Delivery *D);
/* I.S. Sembarang */
/* F.S. Terbentuk Queue delivery kosong. */

// Semua operasi yang ada di PrioQueueDin digunakan pada inventory

#endif