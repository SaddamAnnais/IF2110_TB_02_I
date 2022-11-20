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
3               // Jumlah makanan yang akan disimpan
11              // ID dari makanan pertama
Ayam Mentah     // Nama dari makanan pertama
1 0 0           // Hari, jam, menit sampai kadaluwarsa
0 0 15          // Hari, jam, menit sampai makanan dikirim
Buy             // Aksi untuk mendapatkan makanan
0               // Durasi aksi untuk mendapatkan makanan (tidak untuk aksi Buy)
21              // ID dari makanan kedua
Ayam Potong     // dan seterusnya ..
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
.               // . : mengakhiri konfigurasi makanan
```
#### Recipe
Open file "resep.txt"
```
3               // Jumlah resep
21 1 11         // Makanan dengan ID 21 dapat diperoleh dari 1 makanan lainnya,yaitu dengan cara melakukan aksi pada makanan dengan ID 11
31 2 21 10      // Makanan dengan ID 31 dapat diperoleh dari 2 makanan lainnya,yaitu dengan cara melakukan aksi pada makanan dengan ID 21 dan 10
37 2 31 15      // Makanan dengan ID 37 dapat diperoleh dari 2 makanan lainnya,yaitu dengan cara melakukan aksi pada makanan dengan ID 31 dan 15
.               // . : mengakhiri konfigurasi makanan
```

Setelah konfigurasi telah selesai, ketik `gcc .\main.c -o main` pada terminal lalu ketik `./main` untuk menjalankan program

## Daftar Fitur
1. Main Menu (Selesai)
* START
* EXIT
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

#### [Tabitha Permalla / 13521111](https://github.com/Bitha17)
* ADT Simulator, Buy, (display) Inventory, (display) Delivery, Splash screen, Laporan 

#### [Saddam Annais Shaquille / 13521121](https://github.com/SaddamAnnais)
* Parser, Inventory, Delivery, Makanan, listMakanan, Undo/Redo, Main program 

#### [Althaaf Khasyi Atisomya / 13521130](https://github.com/althaafka)
* ADT time, catalog, command move, command wait, catalog, notifikasi

#### [Rava Maulana Azzikri / 13521149](https://github.com/RMA1403)
* Matriks, point, tree, resep, peta, pengolahan makanan, kulkas, rekomendasi makanan 

#### [Vanessa Rebecca Wiyono / 13521151](https://github.com/vanessrw)
* ADT makanan, list makanan, time, list dinamis, stack, testing, laporan
