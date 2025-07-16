# Sistem Manajemen Basis Data Sederhana dalam C

Ini adalah proyek **Sistem Manajemen Basis Data (DBMS)** sederhana yang dibuat menggunakan bahasa pemrograman **C**. Program ini dirancang untuk mengelola data akademik yang mencakup informasi mahasiswa, dosen, dan program studi. DBMS ini menggunakan **pemrosesan file sekuensial** untuk menyimpan dan mengakses data dari file teks.

## ✨ Fitur

Program ini mendukung operasi-operasi dasar pada basis data, yaitu:

- **INSERT**: Menambahkan data baru ke dalam tabel mahasiswa (`tmahasiswa`), dosen (`tdosen`), atau program studi (`tprodi`).
- **UPDATE**: Memperbarui data yang sudah ada di dalam tabel.
- **DELETE**: Menghapus data dari tabel. Program memeriksa _foreign key_ untuk mencegah penghapusan data yang masih terhubung.
- **SHOW**: Menampilkan seluruh isi dari tabel tertentu.
- **JOIN**: Menampilkan data gabungan dari tabel mahasiswa dengan nama dosen dan nama program studi yang sesuai, menggantikan kode ID.

## 🚀 Cara Penggunaan

### Kompilasi

Gunakan **GCC** untuk mengompilasi program:

```bash
gcc main.c mesin.c -o dbms
```

### Eksekusi

Setelah berhasil dikompilasi, jalankan program dengan:

```bash
./dbms
```

Program akan menampilkan pesan selamat datang dan siap menerima perintah.

## 📝 Sintaks Perintah

Pastikan setiap perintah diakhiri dengan titik koma (`;`).

### ➕ Menambahkan Data

```sql
INSERT tmahasiswa <NIM> <NamaMahasiswa> <KodeProdi> <KodeDosen>;
INSERT tdosen <KodeDosen> <NamaDosen>;
INSERT tprodi <KodeProdi> <NamaProdi>;
```

### ✏️ Memperbarui Data

```sql
UPDATE tmahasiswa <NIM> <NamaMahasiswaBaru> <KodeProdiBaru> <KodeDosenBaru>;
UPDATE tdosen <KodeDosen> <NamaDosenBaru>;
UPDATE tprodi <KodeProdi> <NamaProdiBaru>;
```

### ❌ Menghapus Data

```sql
DELETE tmahasiswa <NIM>;
DELETE tdosen <KodeDosen>;
DELETE tprodi <KodeProdi>;
```

### 📄 Menampilkan Data

```sql
SHOW tmahasiswa;
SHOW tdosen;
SHOW tprodi;
```

### 🔗 JOIN Tabel

```sql
JOIN tmahasiswa;
```

### 🚪 Keluar dari Program

```text
jangan lupa bahagia hari ini;
```

## 🗂️ Skema Basis Data

DBMS ini menyimpan data dalam tiga file teks:

### tmahasiswa (`Mahasiswa.txt`)

- `nim`: Nomor Induk Mahasiswa (**Primary Key**)
- `nama`: Nama Mahasiswa
- `prodi`: Kode Program Studi (**Foreign Key** ke `tprodi`)
- `dosen`: Kode Dosen (**Foreign Key** ke `tdosen`)

### tdosen (`Dosen.txt`)

- `kode`: Kode Dosen (**Primary Key**)
- `nama`: Nama Dosen

### tprodi (`Prodi.txt`)

- `kode`: Kode Program Studi (**Primary Key**)
- `nama`: Nama Program Studi

## 📁 Struktur File

- `main.c` – Logika utama program dan penanganan input.
- `mesin.c` – Implementasi mesin kata dan fungsi operasi file.
- `header.h` – Deklarasi `struct` dan prototipe fungsi.
- `Mahasiswa.txt` – Penyimpanan data mahasiswa.
- `Dosen.txt` – Penyimpanan data dosen.
- `Prodi.txt` – Penyimpanan data program studi.

---

Selamat mencoba, dan jangan lupa bahagia hari ini! 😊
