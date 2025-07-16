/*Saya Muhammad Akhtar Rizki Ramadha mengerjakan evaluasi Tugas Masa Depan 
dalam mata kuliah Algoritma dan Pemrograman II untuk keberkahanNya 
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"
#include <stdio.h>

int main() {

    OPENING();  // Menampilkan tampilan pembuka program
    int mark = 0, markpd = 0, markds = 0;   // Variabel penanda untuk pengecekan keberadaan data
    int i, j, k;    // Variabel iterasi
    int checkmhs = 0, checkpd = 0, checkds = 0; // Variabel untuk menyimpan jumlah data yang dibaca dari file
    first mahasiswa[50];    // Array untuk menyimpan data mahasiswa
    first mahasiswafinal[50];   // Array untuk menyimpan data mahasiswa beserta foreign key
    second dosen[50];   // Array untuk menyimpan data dosen
    second prodi[50];   // Array untuk menyimpan data prodi
    char pita[300]; // String untuk menyimpan input pengguna
    int pd = 0, ds = 0, mhs = 0;    // Variabel untuk menghitung jumlah data

    READ (&checkmhs, mahasiswa, "Mahasiswa.txt");   // Membaca data mahasiswa dari file
    READ2(&checkds, dosen, "Dosen.txt");    // Membaca data dosen dari file
    READ2(&checkpd, prodi, "Prodi.txt");    // Membaca data prodi dari file

    do{
        printf("dbms TArz > "); // Menampilkan prompt untuk input pengguna
        scanf(" %299[^\n]s", &pita); // Membaca input pengguna ke dalam variabel pita
    // memulai mesin kata
    STARTKATA (pita);   // Memulai pengambilan kata dari pita
    if (strcmp(GETCKATA(), "INSERT") == 0) {    // Jika kata pertama adalah "INSERT"
        INCKATA(pita);  // Mengambil kata berikutnya
        if (strcmp(GETCKATA(), "tmahasiswa") == 0) {    // Jika kata berikutnya adalah "tmahasiswa"
            INCKATA(pita);  // Mengambil kata berikutnya (NIM mahasiswa)

            i = 0;
            while((i < checkmhs) && (mark == 0)) {  // Mencari keberadaan NIM dalam data mahasiswa yang telah dibaca
            if (strcmp(GETCKATA(), mahasiswa[i].nim) == 0) {
                    mark = 1;   // NIM sudah ada
                }else{
                    i++;
                }
            }

            if (mark == 1) {
                printf("System Error, Primary Key Already Exists\n\n"); // Menampilkan pesan error jika NIM sudah ada
            }else if (mark == 0) {  // Jika NIM belum ada
                strcpy(mahasiswa[checkmhs].nim, GETCKATA());    // Menyalin NIM ke dalam data mahasiswa
                INCKATA(pita);  // Mengambil kata berikutnya (nama mahasiswa)
                strcpy(mahasiswa[checkmhs].nama, GETCKATA());   // Menyalin nama ke dalam data mahasiswa
                INCKATA(pita);  // Mengambil kata berikutnya (kode prodi)
            }
            mark = 0;   // Mereset penanda

            // Mencari keberadaan kode prodi dalam data prodi yang telah dibaca
            j = 0;
            while((j < checkmhs) && (markpd == 0)) {
                if (strcmp(GETCKATA(), prodi[j].kode) == 0) {
                    markpd = 1; // Kode prodi ditemukan
                }else{
                    j++;
                }
            }

            if (markpd == 0) {
                printf("System Error, Foreign Key Doesn't Exists\n\n"); // Menampilkan pesan error jika kode prodi tidak ditemukan
            }else if (markpd == 1) {
                strcpy(mahasiswa[checkmhs].prodi, GETCKATA()); // Menyalin kode prodi ke dalam data mahasiswa
                INCKATA(pita);  // Mengambil kata berikutnya (kode dosen)
            } 
            
            // Mencari keberadaan kode dosen dalam data dosen yang telah dibaca
            k = 0;
            while((k < checkmhs) && (markds == 0)) {
                if (strcmp(GETCKATA(), dosen[k].kode) == 0) {
                    markds = 1; // Kode dosen ditemukan
                }else{
                    k++;
                }
            }

            if ((markds == 0) && (markpd == 1)) {   
                printf("System Error, Foreign Key Doesn't Exists\n\n"); // Menampilkan pesan error jika kode dosen tidak ditemukan
            }else if ((markds == 1) && (markpd == 1)) {
                strcpy(mahasiswa[checkmhs].dosen, GETCKATA());  // Menyalin kode dosen ke dalam data mahasiswa
                printf("System Running, Insert Successfully\n\n");  // Menampilkan pesan sukses
                checkmhs++; // Menambah jumlah data mahasiswa
                mhs += 1;   // Menghitung jumlah data mahasiswa yang ditambahkan
            } 
            markpd = 0; // Mereset penanda kode prodi
            markds = 0; // Mereset penanda kode dosen

        }else if (strcmp(GETCKATA(), "tdosen") == 0) {  // Jika kata berikutnya adalah "tdosen" (untuk menambah data dosen)
            INCKATA(pita);  // Mengambil kata berikutnya (kode dosen)
            i = 0;
            while((i < checkds) && (mark == 0)) {   // Mencari keberadaan kode dosen dalam data dosen yang telah dibaca
            if (strcmp(GETCKATA(), dosen[i].kode) == 0) {   
                    mark = 1;   // Kode dosen sudah ada
                }else{
                    i++;
                }
            }

            if (mark == 1) {
                printf("System Error, Primary Key Already Exists\n\n"); // Menampilkan pesan error jika kode dosen sudah ada
            }else if (mark == 0) {
                strcpy(dosen[checkds].kode, GETCKATA());    // Menyalin kode dosen ke dalam data dosen
                INCKATA(pita);  // Mengambil kata berikutnya (nama dosen)
                strcpy(dosen[checkds].nama, GETCKATA());    // Menyalin nama dosen ke dalam data dosen
                printf("System Running, Insert Successfully\n\n");  // Menampilkan pesan sukses
                checkds++;  // Menambah jumlah data dosen
                ds += 1;    // Menghitung jumlah data dosen yang ditambahkan
            }
            mark = 0;   // Mereset penanda
        }else if (strcmp(GETCKATA(), "tprodi") == 0) {  // Jika kata berikutnya adalah "tprodi" (untuk menambah data prodi)
            INCKATA(pita);  // Mengambil kata berikutnya (kode prodi)

            i = 0;
            while((i < checkpd) && (mark == 0)) {   // Mencari keberadaan kode prodi dalam data prodi yang telah dibaca
            if (strcmp(GETCKATA(), prodi[i].kode) == 0) {
                    mark = 1;   // Kode prodi sudah ada
                }else{
                    i++;
                }
            }

            if (mark == 1) {
                printf("System Error, Primary Key Already Exists\n\n"); // Menampilkan pesan error jika kode prodi sudah ada
            }else if (mark == 0) {
                strcpy(prodi[checkpd].kode, GETCKATA());    // Menyalin kode prodi ke dalam data prodi
                INCKATA(pita);  // Mengambil kata berikutnya (nama prodi)
                strcpy(prodi[checkpd].nama, GETCKATA());    // Menyalin nama prodi ke dalam data prodi
                printf("System Running, Insert Successfully\n\n");  // Menampilkan pesan sukses
                checkpd++;  // Menambah jumlah data prodi
                pd += 1;    // Menghitung jumlah data prodi yang ditambahkan
            }
            mark = 0;   // Mereset penanda
        }else{  // Jika input salah
        checkmhs--; // Mengurangi jumlah data mahasiswa
        checkpd--;  // Mengurangi jumlah data prodi
        checkds--;  // Mengurangi jumlah data dosen
            printf("System Error, Wrong Input\n\n");    // Menampilkan pesan error
        }
    }else if (strcmp(GETCKATA(), "UPDATE") == 0) {  // Jika kata berikutnya adalah "UPDATE"
        INCKATA(pita);
        if (strcmp(GETCKATA(), "tmahasiswa") == 0) {    // Jika kata berikutnya adalah "tmahasiswa"
            INCKATA(pita);  // Mengambil kata berikutnya
            i = 0;
            while((i < checkmhs) && (mark == 0)) {  // Mencari keberadaan NIM dalam data mahasiswa yang telah dibaca
            if (strcmp(GETCKATA(), mahasiswa[i].nim) == 0) {    // NIM ditemukan
                INCKATA(pita);  // Mengambil kata berikutnya
                strcpy(mahasiswa[i].nama, GETCKATA());  // Memperbarui nama mahasiswa
                INCKATA(pita);  // Mengambil kata berikutnya
                j = 0;
                while((j < checkmhs) && (markpd == 0)) {    // Mencari keberadaan kode prodi dalam data prodi yang telah dibaca
                    if (strcmp(GETCKATA(), prodi[j].kode) == 0) {
                        markpd = 1; // Kode prodi ditemukan
                    }else{
                        j++;
                    }
                }
                mark = 1;   // Menandai bahwa data telah ditemukan

                if (markpd == 0) {
                    printf("System Error, Foreign Key Doesn't Exists\n\n"); // Menampilkan pesan error jika kode prodi tidak ditemukan
                }else if (markpd == 1) {
                    strcpy(mahasiswa[i].prodi, GETCKATA()); // Memperbarui kode prodi mahasiswa
                    INCKATA(pita);  // Mengambil kata berikutnya
                }

                k = 0;
                while((k < checkmhs) && (markds == 0)) {    // Mencari keberadaan kode dosen dalam data dosen yang telah dibaca
                    if (strcmp(GETCKATA(), dosen[k].kode) == 0) {
                        markds = 1; // Kode dosen ditemukan
                    }else{
                        k++;
                    }
                }
                
                if ((markds == 0) && (markpd == 1)) {
                    printf("System Error, Foreign Key Doesn't Exists\n\n"); // Menampilkan pesan error jika kode dosen tidak ditemukan
                }else if ((markds == 1) && (markpd == 1)) {
                    strcpy(mahasiswa[i].dosen, GETCKATA()); // Memperbarui kode dosen mahasiswa
                    mhs += 1;   // Menghitung jumlah data mahasiswa yang diperbarui 
                    printf("System Running, Update Succesfully\n\n");   // Menampilkan pesan sukses
                }

                markpd = 0; // Mereset penanda kode prodi
                markds = 0; // Mereset penanda kode dosen

            }else{
                i++;
            }
            }
            mark = 0;
            if (i == checkmhs) {
                printf("System Error, Can't Find\n\n"); // Menampilkan pesan error jika NIM tidak ditemukan
            }
        }else if(strcmp(GETCKATA(), "tdosen") == 0) {   // Jika kata berikutnya adalah "tdosen"
            INCKATA(pita);  // Mengambil kata berikutnya
            i = 0;
            while((i < checkds) && (mark == 0)) {   // Mencari keberadaan kode dosen dalam data dosen yang telah dibaca
            if (strcmp(GETCKATA(), dosen[i].kode) == 0) {   // Kode dosen ditemukan
                INCKATA(pita);  // Mengambil kata berikutnya
                strcpy(dosen[i].nama, GETCKATA());  // Memperbarui nama dosen
                ds += 1;    // Menghitung jumlah data dosen yang diperbarui
                mark = 1;   // Menandai bahwa data telah ditemukan
                printf("System Running, Update Succesfully\n\n");   // Menampilkan pesan sukses
            }else{
                i++;
            }
            }
            mark = 0;
            if (i == checkds) {
                printf("System Error, Can't Find\n\n"); // Menampilkan pesan error jika kode dosen tidak ditemukan
            }
        }else if (strcmp(GETCKATA(), "tprodi") == 0) {  // Jika kata berikutnya adalah "tprodi"
            INCKATA(pita);  // Mengambil kata berikutnya
            i = 0;
            while((i < checkpd) && (mark == 0)) {   // Mencari keberadaan kode prodi dalam data prodi yang telah dibaca
            if (strcmp(GETCKATA(), prodi[i].kode) == 0) {   // Kode prodi ditemukan
                INCKATA(pita);  // Mengambil kata berikutnya
                strcpy(prodi[i].nama, GETCKATA());  // Memperbarui nama prodi
                pd += 1;    // Menghitung jumlah data prodi yang diperbarui
                mark = 1;   // Menandai bahwa data telah ditemukan
                printf("System Running, Update Succesfully\n\n");   // Menampilkan pesan sukses
            }else{
                i++;
            }
            }
            mark = 0;
            if (i == checkpd) {
                printf("System Error, Can't Find\n\n"); // Menampilkan pesan error jika kode prodi tidak ditemukan
            }          
        }else{  // Jika input salah
            checkmhs--; // Mengurangi jumlah data mahasiswa
            checkpd--;  // Mengurangi jumlah data prodi
            checkds--;  // Mengurangi jumlah data dosen
            printf("System Error, Wrong Input\n\n");    // Menampilkan pesan error
        }
    }else if (strcmp(GETCKATA(), "DELETE") == 0) {  // Jika kata berikutnya adalah "DELETE"
        INCKATA(pita);  // Mengambil kata berikutnya
        if (strcmp(GETCKATA(), "tmahasiswa") == 0) {    // Jika kata berikutnya adalah "tmahasiswa"
            INCKATA(pita);  // Mengambil kata berikutnya
            for (i = 0; i < checkmhs; i++) {
                if (strcmp(GETCKATA(), mahasiswa[i].nim) == 0) {    // Jika NIM ditemukan dalam data mahasiswa
                    while (i < checkmhs) {
                        mahasiswa[i] = mahasiswa[i + 1];    // Menggeser data mahasiswa ke depan
                        i++;
                        mhs += 1;   // Menghitung jumlah data mahasiswa yang dihapus
                        mark = 1;   // Penanda data ditemukan
                    }
                checkmhs--; // Mengurangi jumlah data mahasiswa
                printf("System Running, Delete Succesfully\n\n");   // Menampilkan pesan sukses
                }
            }    
            if (mark == 0) {
                printf("System Error, Can't Find\n\n"); // Menampilkan pesan error jika data tidak ditemukan
            }
        }else if (strcmp(GETCKATA(), "tdosen") == 0) {  // Jika kata berikutnya adalah "tdosen"
            INCKATA(pita);  // Mengambil kata berikutnya

            i = 0;
            while((i < checkmhs) && (markds == 0)) {     // Mencari apakah kode dosen digunakan oleh data mahasiswa
            if (strcmp(GETCKATA(), mahasiswa[i].dosen) == 0) {
                    markds = 1; // Kode dosen digunakan oleh data mahasiswa
                }else{
                    i++;
                }
            }

            if (markds == 1) {
                printf("System Error, Foreign Key is in Use\n\n");  // Menampilkan pesan error jika kode dosen digunakan oleh data mahasiswa
            }else if (markds == 0) {
                for (i = 0; i < checkds; i++) {
                    if (strcmp(GETCKATA(), dosen[i].kode) == 0) {   // Jika kode dosen ditemukan dalam data dosen
                        while (i < checkds) {
                            dosen[i] = dosen[i + 1];    // Menggeser data dosen ke depan
                            i++;    
                            ds += 1;    // Menghitung jumlah data dosen yang dihapus 
                            mark = 1;   // Penanda data ditemukan
                        }
                    checkds--;   // Mengurangi jumlah data dosen
                    printf("System Running, Delete Succesfully\n\n");   // Menampilkan pesan sukses 
                    }
                }    
                if (mark == 0) {
                    printf("System Error, Can't Find\n\n"); // Menampilkan pesan error jika data tidak ditemukan
                }
                mark = 0;   // Mereset penanda
            }
            markds = 0; // Mereset penanda
        }else if (strcmp(GETCKATA(), "tprodi") == 0) {  // Jika kata berikutnya adalah "tprodi"
            INCKATA(pita);  // Mengambil kata berikutnya

            i = 0;
            while((i < checkmhs) && (markpd == 0)) {    // Mencari apakah kode prodi digunakan oleh data mahasiswa
            if (strcmp(GETCKATA(), mahasiswa[i].prodi) == 0) {
                    markpd = 1; // Kode prodi digunakan oleh data mahasiswa
                }else{  
                    i++;
                }
            }

            if (markpd == 1) {
                printf("System Error, Foreign Key is in Use\n");    // Menampilkan pesan error jika kode prodi digunakan oleh data mahasiswa
            }else if (markpd == 0) {
                for (i = 0; i < checkpd; i++) {
                    if (strcmp(GETCKATA(), prodi[i].kode) == 0) {    // Jika kode prodi ditemukan dalam data prodi
                        while (i < checkpd) {
                            prodi[i] = prodi[i + 1];    // Menggeser data prodi ke depan
                            i++;
                            pd += 1;    // Menghitung jumlah data prodi yang dihapus
                            mark = 1;   // Penanda data ditemukan
                        }
                    checkpd--;  // Mengurangi jumlah data prodi
                    printf("System Running, Delete Succesfully\n\n");   // Menampilkan pesan sukses 
                    }
                }    
                if (mark == 0) {
                    printf("System Error, Can't Find\n\n"); // Menampilkan pesan error jika data tidak ditemukan
                }
                mark = 0;   // Mereset penanda
            }
            markpd = 0; // Mereset penanda
        }else{
            printf("System Error, Wrong Input\n\n");    // Menampilkan pesan error jika input salah
        }
    }else if (strcmp(GETCKATA(), "SHOW") == 0) {    // Jika kata berikutnya adalah "SHOW"
        INCKATA(pita);  // Mengambil kata berikutnya
        if (strcmp(GETCKATA(), "tmahasiswa") == 0) {    // Jika kata berikutnya adalah "tmahasiswa"
            PRINTMHS(&checkmhs, mahasiswa);  // Memanggil fungsi untuk mencetak data mahasiswa
            printf("\n");
        }else if (strcmp(GETCKATA(), "tdosen") == 0) {  // Jika kata berikutnya adalah "tdosen"
            PRINTDS(&checkds, dosen);   // Memanggil fungsi untuk mencetak data dosen
            printf("\n");
        }else if (strcmp(GETCKATA(), "tprodi") == 0) {  // Jika kata berikutnya adalah "tprodi"
            PRINTPD(&checkpd, prodi);   // Memanggil fungsi untuk mencetak data prodi
            printf("\n");
        }else{
            printf("System Error, Wrong Input\n\n");    // Menampilkan pesan error jika input salah
        }
    }else if (strcmp(GETCKATA(), "JOIN") == 0) {    // Jika kata berikutnya adalah "JOIN"
        INCKATA(pita);  // Mengambil kata berikutnya
        if (strcmp(GETCKATA(), "tmahasiswa") == 0) {    // Jika kata berikutnya adalah "tmahasiswa"

            for (i = 0; i < checkmhs; i++) {
                mahasiswafinal[i] = mahasiswa[i];   // Menyalin data mahasiswa ke array mahasiswafinal

                for (j = 0; j < checkds; j++) { // Mengganti kode dosen dengan nama dosen pada data mahasiswafinal
                    if (strcmp(mahasiswafinal[i].dosen, dosen[j].kode) == 0) {
                        strcpy(mahasiswafinal[i].dosen, dosen[j].nama);
                    }
                }

                for (j = 0; j < checkpd; j++) { // Mengganti kode prodi dengan nama prodi pada data mahasiswafinal
                    if (strcmp(mahasiswafinal[i].prodi, prodi[j].kode) == 0) {
                        strcpy(mahasiswafinal[i].prodi, prodi[j].nama);
                    }
                }
            }

                PRINTJOIN(&checkmhs, mahasiswafinal);  // Memanggil fungsi untuk mencetak data mahasiswafinal yang telah digabungkan
                printf("\n");
        }else{
            printf("System Error, Wrong Input\n\n");    // Menampilkan pesan error jika input salah
        }
    }else if (strcmp(GETCKATA(), "jangan") == 0){   // Jika kata berikutnya adalah "jangan"
        printf("System(Exit)\n");
        printf("\n");
        printf("Bye Bye!\n#CTID\n");
    }else{  // Jika input salah
        checkmhs--; // Mengurangi jumlah data mahasiswa
        checkpd--;  // Mengurangi jumlah data prodi
        checkds--;  // Mengurangi jumlah data dosen
        printf("System Error, Wrong Query\n\n");   // Menampilkan pesan error

    }
    }while (strcmp(pita, "jangan lupa bahagia hari ini;") != 0);    //Syarat looping
    
    // Setelah keluar dari loop
    if (mhs > 0) {
        WRITE(&checkmhs, mahasiswa, "Mahasiswa.txt");   // Menulis data mahasiswa ke file jika ada perubahan
    }if (ds > 0) {
        WRITE2(&checkds, dosen, "Dosen.txt");   // Menulis data dosen ke file jika ada perubahan
    }if (pd > 0) {
        WRITE2(&checkpd, prodi, "Prodi.txt");   // Menulis data prodi ke file jika ada perubahan
    }

    return 0;
}