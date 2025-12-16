# Tugas-Besar-IF4803-Kelompok-1

Sistem Manajemen Menu dan Transaksi Pelanggan menggunakan Struktur Data Linked List

## Deskripsi Aplikasi

Aplikasi ini adalah **Sistem Manajemen Menu dan Pelanggan** yang dikembangkan sebagai tugas besar untuk mata kuliah IF4803 (Struktur Data). Aplikasi mengelola menu restoran/kafe dan informasi pelanggan dengan dua mode operasional: mode pelanggan untuk melakukan pemesanan dan mode admin untuk manajemen menu.

### Fitur Utama:

#### Mode Pelanggan:
- **Registrasi Pelanggan:** Daftarkan data pelanggan dengan ID, nama, saldo awal, dan status VIP
- **Lihat Menu:** Menampilkan semua menu yang tersedia beserta ID, nama, harga, dan stok
- **Lakukan Pemesanan:** Pesan menu dengan jumlah tertentu (saldo akan dikurangi otomatis)
- **Tambah Saldo:** Melakukan deposit saldo ke akun pelanggan
- **Lihat Pesanan:** Menampilkan riwayat pesanan pelanggan per menu
- **Prioritas VIP:** Customer VIP dimasukkan di awal antrian (insertFirst), sementara regular customer di akhir antrian (insertLast)

#### Mode Admin:
- **Tambah Menu:** Menambahkan menu baru dengan sorting alfabetis
- **Tambah Stock Menu:** Menambah stok menu yang sudah ada
- **Lihat Customer Menu:** Menampilkan semua pelanggan yang memesan menu tertentu
- **Lihat Customer VIP:** Menampilkan semua pelanggan dengan status VIP di semua menu

### Struktur Data:

- **Single Linked List (Menu):** Daftar terpaut tunggal untuk menyimpan item menu
- **Doubly-Linked List (Pelanggan):** Daftar terpaut dua arah untuk menyimpan pelanggan setiap item menu
- **Struktur Hierarki:** Setiap item menu memiliki linked list pelanggan sendiri

### Struktur File:

```
Tugas-Besar-IF4803-Kelompok-1/
├── main.cpp                      # Program utama dengan menu dan navigasi
├── customer.h                    # Header untuk struktur dan fungsi pelanggan
├── customer_103012430041.cpp     # Implementasi fungsi pelanggan (kelompok 1)
├── customer_103012400011.cpp     # Implementasi fungsi pelanggan (kelompok 2)
├── menu.h                        # Header untuk struktur dan fungsi menu
├── menu_103012430041.cpp         # Implementasi fungsi menu (kelompok 1)
├── menu_103012400011.cpp         # Implementasi fungsi menu (kelompok 2)
├── Tugas-Besar-IF4803-Kelompok-1.cbp   # File project Code::Blocks
├── Tugas-Besar-IF4803-Kelompok-1.depend # File dependensi
├── Tugas-Besar-IF4803-Kelompok-1.layout # Layout Code::Blocks
└── bin/                          # Output executable
    └── Debug/
```

### Teknologi:

- **Bahasa:** C++
- **Struktur Data:** Linked Lists (Tunggal dan Dua Arah)
- **Compiler:** G++ (GNU C++ Compiler)
- **IDE:** Code::Blocks

### Cara Compile dan Run:

#### Menggunakan G++ (Windows/Linux):
```bash
g++ *.cpp -o program.exe
./program.exe
```

#### Menggunakan Code::Blocks:
1. Buka file `Tugas-Besar-IF4803-Kelompok-1.cbp`
2. Klik Build → Rebuild atau tekan Ctrl+F11
3. Klik Run atau tekan Ctrl+F10

### Dokumentasi Fungsi:

Setiap fungsi dilengkapi dengan dokumentasi lengkap yang menjelaskan:
- **I.S (Initial State):** Kondisi awal sebelum fungsi dijalankan
- **F.S (Final State):** Kondisi akhir setelah fungsi dijalankan

Contoh dokumentasi:
```cpp
/*
    I.S : List customer tidak kosong. prec berada di tengah list dan p belum terhubung.
    F.S : p disisipkan setelah prec, relasi next dan prev diperbarui. Transaksi diproses.
*/
void insertAfterCustomer(adrMenu &M, adrCustomer p, adrCustomer prec, int quantity)
```