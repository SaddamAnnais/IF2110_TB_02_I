# IF2110_TB_02_I
Tugas Besar IF2110 Algoritma dan Struktur Data

## Daftar Isi
* [Penjelasan Ringkas Program](#penjelasan-ringkas-program)
* [Cara Kompilasi Program](#cara-kompilasi-program)
* [Cara Menjalankan Program](#cara-menjalankan-program)
* [Daftar Fitur](#daftar-fitur)
* [Pembagian Tugas](#pembagian-tugas)

## Penjelasan Ringkas Program
Tugas Besar IF2110 ini merupakan program berbasis CLI dalam
bahasa C yang mensimulasikan tentang aktivitas memasak. Pemain
dapat membeli bahan makanan serta memproses bahan tersebut menjadi suatu hidangan sesuai dengan apa yang tertera pada buku resep. Program juga akan menampilkan berapa lama waktu kedaluwarsa suatu makanan dan berapa lama waktu pengantaran suatu makanan. Selain itu, terdapat juga fitur kulkas untuk menyimpan makanan sehingga waktu kedaluwarsanya tidak berkurang.

## Cara Kompilasi Program
1. Periksa bahwa gcc compiler versi terbaru telah terpasang (`gcc --version` pada terminal untuk mengecheck versi compiler).
2. jalankan command `gcc .\main.c -o main` pada terminal untuk melakukan kompilasi program
3. Jika kompilasi berhasil, maka akan terdapat `main.exe` pada directory program.

## Cara Menjalankan Program
Buka folder config untuk mengkonfigurasi maps, food, dan recipe.

#### Maps
Open file "peta.txt"
```
10 10           // Peta dengan ukuran (N x M)
S#########      // S : lokasi simulator
####T##X##      // T : lokasi telephone (buy food)
#M#####X##      // # : ruang kosong
#######X##      // X : obstacle
####XXXX##
#X########
#X######C#      // C : lokasi aksi CHOP
#XXX##F###      // F : lokasi aksi FRY
##########
######B###      // B : lokasi aksi BOIL
.               // . : mengakhiri konfigurasi peta
```
#### Food
Open file "makanan.txt"
```
3               // Number of food that will be stored
11              // ID of the first food
Ayam Mentah     // Name of the first food
1 0 0           // Days, Hours, Minutes until expired of the first food
0 0 15          // Days, Hours, Minutes of delivery time of the first food
Buy             // Action to obtained the food
0               // Duration of action to obtained the food (not for buy action)
21              // ID of the second food
Ayam Potong     // and so on..
0 2 0
0 0 0
Chop
4
5
Tepung
0 1 0
0 0 30
Buy
10
.               // . to end food config
```
#### Recipe
Open file "resep.txt"
```
3               // Number of recipe
21 1 11         // Food with the ID of 21 can be obtained from 1 other food, by doing an action from food with the ID of 11
31 2 21 10      // Food with the ID of 31 can be obtained from 2 other foods, by doing an action from food with the ID of 21 and 10
37 2 31 15      // Food with the ID of 37 can be obtained from 2 other foods, by doing an action from food with the ID of 31 and 15
.               // . to end recipe config
```

Setelah konfigurasi telah selesai, ketik `./run` pada terminal lalu ketik `./main` untuk menjalankan program

## Daftar Fitur
1. Main Menu (Selesai)
* START (Selesai)
* EXIT (Selesai)
2. Mekanisme Waktu (Selesai)
* WAIT
* DELIVERY
3. Makanan (Selesai)
* BUY
* FRY
* BOIL
* CHOP
* MIX
* INVENTORY
4. Resep (Selesai)
* CATALOG
* COOKBOOK
5. Delivery (Selesai)
6. Peta (Selesai)
7. Lokasi dan Command (Selesai)
* MOVE NORTH, SOUTH, EAST, WEST 
* UNDO / REDO
8. Waktu pengolahan makanan (Selesai)
8. Kulkas (Selesai)
9. Rekomendasi makanan (Selesai)

## Pembagian Tugas

#### Tabitha Permalla / 13521111
ADT Simulator, Buy, (display) Inventory, (display) Delivery, Splash screen, Laporan 

#### Saddam Annais Shaquille / 13521121 
Parser, Inventory, Delivery, Makanan, listMakanan, Undo/Redo, Main program 

#### Althaaf Khasyi Atisomya / 13521130 
ADT time, catalog, command move, command wait, catalog, notifikasi

#### Rava Maulana Azzikri / 13521149 
Matriks, point, tree, resep, peta, pengolahan makanan, kulkas, rekomendasi makanan 

#### Vanessa Rebecca Wiyono / 13521151 
ADT makanan, list makanan, time, list dinamis, stack, testing, laporan 