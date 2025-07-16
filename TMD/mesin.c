/*Saya Muhammad Akhtar Rizki Ramadha mengerjakan evaluasi Tugas Masa Depan 
dalam mata kuliah Algoritma dan Pemrograman II untuk keberkahanNya 
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

// Fungsi untuk mengambil kata pertama dari sebuah string
void STARTKATA (char pita[]) {
    // Inisialisasi indeks dan panjangkata dengan 0
    indeks = 0;
    panjangkata = 0;
     // Melompati spasi di awal string
    while(pita[indeks] == ' ') {
        indeks++;
    }
    // Menyalin karakter-karakter dari pita ke dalam ckata hingga ditemukan spasi atau titik koma
    while((pita[indeks] != ' ') && (pita[indeks] != ';')) {
        ckata[panjangkata] = pita[indeks];
        indeks++;
        panjangkata++;
    }
    // Menambahkan null terminator di akhir ckata
    ckata[panjangkata] = '\0';
}

// Fungsi untuk mengosongkan ckata
void RESETKATA () {
    panjangkata = 0;
    ckata[panjangkata] ='\0';
}

// Fungsi untuk mengambil kata berikutnya dari sebuah string
void INCKATA (char pita[]) {
    panjangkata = 0;
    // Melompati spasi di awal string
    while (pita[indeks] == ' ') {
        indeks++;
    }
    // Menyalin karakter-karakter dari pita ke dalam ckata hingga ditemukan spasi atau titik koma
    while ((pita[indeks] != ' ') && (pita[indeks] != ';')) {
        ckata[panjangkata] = pita[indeks];
        indeks++;
        panjangkata++;
    }
    // Menambahkan null terminator di akhir ckata
    ckata[panjangkata] = '\0';
}

// Fungsi untuk mendapatkan nilai ckata
char* GETCKATA() {
    return ckata;
}

// Fungsi untuk mendapatkan nilai panjangkata
int GETPANJANGKATA() {
    return panjangkata;
}

// Fungsi untuk memeriksa apakah telah mencapai akhir string
int EOPKATA(char pita[]) {
    if(pita[indeks] == ';') {
         // Jika karakter saat ini adalah titik koma, maka mengembalikan 1 (akhir string)
        return 1;
    }else{
        // Jika tidak, mengembalikan 0 (bukan akhir string)
        return 0;
    }
}


//Mesin Untuk Sequential File

// Fungsi untuk menunda eksekusi program selama beberapa detik
void DELAY(int seconds) {
    int i, j;

     // Loop untuk menghabiskan waktu
    for (i = 0; i < seconds; i++) {
        for (j = 0; j < 100000000; j++) {
            
        }
    }
}

// Fungsi untuk menampilkan tampilan pembuka program
void OPENING() {
     for (int i = 0; i < 1; i++) {
        // Mencetak tanggal dan waktu saat ini
        printf("%s                                     %s\n", __DATE__, __TIME__);
        DELAY(8);
        // Mencetak baris pembuka
        printf("00000000000000000000000000000000000000000000000000000000\n");
        DELAY(8); 
        printf("          Welcome To AcademicInformationSystem\n");
        DELAY(8);
        printf("00000000000000000000000000000000000000000000000000000000\n");
        DELAY(8);
        printf("Version 1.1\n");
        DELAY(8);
        printf("\n");
        DELAY(8);
        printf("\n");
        DELAY(8);
        
    }
}

// Fungsi untuk membaca data dari file teks dan menyimpannya dalam array source dari tipe first
void READ(int *n, first source[], char fileName[]) { 
    FILE *fTemp; // Deklarasi pointer file
    fTemp = fopen(fileName, "r"); // Membuka file dengan mode baca
    int returnVal = fscanf(fTemp, "%s %s %s %s", source[*n].nim, source[*n].nama, source[*n].prodi, source[*n].dosen); // Membaca data dari file

    // Jika data yang dibaca adalah "####" atau akhir file, maka file kosong       
    if (strcmp(source[*n].nim, "####") == 0 || returnVal == EOF) printf("File Kosong\n"); 
    else{ // Jika tidak
        // Selama data yang dibaca tidak "####"
        while (strcmp(source[*n].nim, "####") != 0) { 
            *n = *n + 1; // Increment nilai n
            fscanf(fTemp, "%s %s %s %s", source[*n].nim, source[*n].nama, source[*n].prodi, source[*n].dosen); // Membaca data berikutnya dari file
        }
    }
    fclose(fTemp); // Menutup file
}

// Fungsi untuk membaca data dari file teks dan menyimpannya dalam array source dari tipe second
void READ2(int *n, second source[], char fileName[]) { 
    FILE *fTemp; // Deklarasi pointer file
    fTemp = fopen(fileName, "r"); // Membuka file dengan mode baca
    int returnVal = fscanf(fTemp, "%s %s", source[*n].kode, source[*n].nama); // Membaca data dari file

    // Jika data yang dibaca adalah "####" atau akhir file, maka file kosong
    if (strcmp(source[*n].kode, "####") == 0 || returnVal == EOF) printf("File Kosong\n"); 
    else{ // Jika tidak
        // Selama data yang dibaca tidak "####"
        while (strcmp(source[*n].kode, "####") != 0) { //kondisi lagi, selama data id belum data null
            *n = *n + 1; // Increment nilai n
            fscanf(fTemp, "%s %s", source[*n].kode, source[*n].nama); // Membaca data berikutnya dari file
        }
        
    }
    fclose(fTemp); // Menutup file
}

// Fungsi untuk menulis data dari array source ke dalam file teks
void WRITE(int *n, first source[], char fileName[]) { 
    FILE *fTemp; // Deklarasi pointer file
    fTemp = fopen(fileName, "w"); // Membuka file dengan mode tulis
    for (int i = 0; i < *n; i++) {// Perulangan sebanyak nilai n
        fprintf(fTemp, "%s %s %s %s\n", source[i].nim, source[i].nama, source[i].prodi, source[i].dosen); // Menulis data ke file
    }
    fprintf(fTemp, "%s %s %s %s\n", "####", "######", "####", "####"); // Menulis data null ke file

    fclose(fTemp); // Menutup file
}

// Fungsi untuk menulis data dari array source ke dalam file teks
void WRITE2(int *n, second source[], char fileName[]) { 
    FILE *fTemp; // Deklarasi pointer file
    fTemp = fopen(fileName, "w"); // Membuka file dengan mode tulis
    for (int i = 0; i < *n; i++) { // Perulangan sebanyak nilai n
        fprintf(fTemp, "%s %s\n", source[i].kode, source[i].nama); // Menulis data ke file
    }
    fprintf(fTemp, "%s %s\n", "####", "####"); // Menulis data null ke file

    fclose(fTemp); // Menutup file
}

// Fungsi untuk mencetak data dari array source dalam bentuk tabel
void PRINTJOIN(int *n, first source[]) {
    // dengan menyesuaikan lebar kolom berdasarkan panjang data terpanjang
    int spacenim = 0, spacename = 0, spacedosen = 0, spaceprodi = 0;

     // Mencari panjang data terpanjang untuk setiap kolom
    for (int i = 0; i < *n; i++) {
        if (strlen(source[i].nim) > spacenim) {
            spacenim = strlen(source[i].nim);
        }
        if (strlen(source[i].nama) > spacename) {
            spacename = strlen(source[i].nama);
        }
        if (strlen(source[i].prodi) > spaceprodi) {
            spaceprodi = strlen(source[i].prodi);
        }
        if (strlen(source[i].dosen) > spacedosen) {
            spacedosen = strlen(source[i].dosen);
        }
    }

     // Mencetak header tabel
    printf("NIM ");
    if (spacenim < 3) {
        for (int i = 0; i < 3 - 3; i++) {
            printf(" ");
        }
    }else{
        for (int i = 0; i < spacenim - 3; i++) {
            printf(" ");
        }
    }
    printf("NamaMahasiswa ");
    if (spacename <  13) {
        for (int i = 0; i < 13 - 13; i++) {
            printf(" ");
        }  
    }else{
        for (int i = 0; i < spacename - 13; i++) {
            printf(" ");
        }    
    }
    printf("NamaProdi ");
    if (spaceprodi < 9) {
        for (int i = 0; i < 9 - 9; i++) {
            printf(" ");
        } 
    }else{
        for (int i = 0; i < spaceprodi - 9; i++) {
            printf(" ");
        }    
    }
    printf("NamaDosen");
    if (spacedosen <  9) {
        for (int i = 0; i < 9 - 9; i++) {
            printf(" ");
        }
    }else{
        for (int i = 0; i < spacedosen - 9; i++) {
            printf(" ");
        }
    }
    printf("\n");

    // Mencetak data dalam tabel
    for(int i = 0; i < *n; i++) {
        printf("%s ", source[i].nim);
        if (spacenim < 3) {
            for (int j = 0; j < 3 - strlen(source[i].nim); j++) {
                printf(" ");
            }
        }else{
            for (int j = 0; j < spacenim - strlen(source[i].nim); j++) {
                printf(" ");
            }
        }
        printf("%s ", source[i].nama);
        if (spacename < 13) {
            for (int j = 0; j < 13 - strlen(source[i].nama); j++) {
                printf(" ");
            }
        }else{
            for (int j = 0; j < spacename - strlen(source[i].nama); j++) {
                printf(" ");
            }    
        }
        printf("%s ", source[i].prodi);
        if (spaceprodi < 9) {
            for (int j = 0; j < 9 - strlen(source[i].prodi); j++) {
                printf(" ");
            }  
        }else{
            for (int j = 0; j < spaceprodi - strlen(source[i].prodi); j++) {
                printf(" ");
            }    
        }
        printf("%s", source[i].dosen);
        if (spacedosen < 9) {
            for (int j = 0; j < 9 - strlen(source[i].dosen); j++) {
                printf(" ");
            }
        }else{
            for (int j = 0; j < spacedosen - strlen(source[i].dosen); j++) {
                printf(" ");
            }
        }
        printf("\n");
    }    
}

// Fungsi untuk mencetak data NIM dan Nama Mahasiswa dari array source
void PRINTMHS(int *n, first source[]) {

    int spacenim = 0, spacename = 0;

    // Mencari panjang data terpanjang untuk kolom NIM dan Nama Mahasiswa
    for (int i = 0; i < *n; i++) {
        if (strlen(source[i].nim) > spacenim) {
            spacenim = strlen(source[i].nim);
        }
        if (strlen(source[i].nama) > spacename) {
            spacename = strlen(source[i].nama);
        }
    }

    // Mencetak header tabel
    printf("NIM ");
    if (spacenim < 3) {
        for (int i = 0; i < 3 - 3; i++) {
            printf(" ");
        }
    }else{
        for (int i = 0; i < spacenim - 3; i++) {
            printf(" ");
        }
    }
    printf("NamaMahasiswa ");
    if (spacename <  13) {
        for (int i = 0; i < 13 - 13; i++) {
            printf(" ");
        }  
    }else{
        for (int i = 0; i < spacename - 13; i++) {
            printf(" ");
        }    
    }
    
    printf("\n");
    // Mencetak data dalam tabel
    for(int i = 0; i < *n; i++) {
        printf("%s ", source[i].nim);
        if (spacenim < 3) {
            for (int j = 0; j < 3 - strlen(source[i].nim); j++) {
                printf(" ");
            }
        }else{
            for (int j = 0; j < spacenim - strlen(source[i].nim); j++) {
                printf(" ");
            }
        }
        printf("%s ", source[i].nama);
        if (spacename < 13) {
            for (int j = 0; j < 13 - strlen(source[i].nama); j++) {
                printf(" ");
            }
        }else{
            for (int j = 0; j < spacename - strlen(source[i].nama); j++) {
                printf(" ");
            }    
        }
        printf("\n");
    }    
}

// Fungsi untuk mencetak data Kode dan Nama Prodi dari array source
void PRINTPD(int *n, second source[]) {

    int spacekode = 0, spacename = 0;

    // Mencari panjang data terpanjang untuk kolom Kode dan Nama Prodi
    for (int i = 0; i < *n; i++) {
        if (strlen(source[i].kode) > spacekode) {
            spacekode = strlen(source[i].kode);
        }
        if (strlen(source[i].nama) > spacename) {
            spacename = strlen(source[i].nama);
        }
    }

    // Mencetak header tabel
    printf("Kode ");
    if (spacekode < 4) {
        for (int i = 0; i < 4 - 4; i++) {
            printf(" ");
        }
    }else{
        for (int i = 0; i < spacekode - 4; i++) {
            printf(" ");
        }
    }
    printf("NamaProdi ");
    if (spacename <  9) {
        for (int i = 0; i < 9 - 9; i++) {
            printf(" ");
        }  
    }else{
        for (int i = 0; i < spacename - 9; i++) {
            printf(" ");
        }    
    }
    
    printf("\n");
    // Mencetak data dalam tabel
    for(int i = 0; i < *n; i++) {
        printf("%s ", source[i].kode);
        if (spacekode < 3) {
            for (int j = 0; j < 3 - strlen(source[i].kode); j++) {
                printf(" ");
            }
        }else{
            for (int j = 0; j < spacekode - strlen(source[i].kode); j++) {
                printf(" ");
            }
        }
        printf("%s ", source[i].nama);
        if (spacename < 9) {
            for (int j = 0; j < 9 - strlen(source[i].nama); j++) {
                printf(" ");
            }
        }else{
            for (int j = 0; j < spacename - strlen(source[i].nama); j++) {
                printf(" ");
            }    
        }
        printf("\n");
    }    
}

// Fungsi untuk mencetak data Kode dan Nama Dosen dari array source
void PRINTDS(int *n, second source[]) {

    int spacekode = 0, spacename = 0;
    // Mencari panjang data terpanjang untuk kolom Kode dan Nama Dosen
    for (int i = 0; i < *n; i++) {
        if (strlen(source[i].kode) > spacekode) {
            spacekode = strlen(source[i].kode);
        }
        if (strlen(source[i].nama) > spacename) {
            spacename = strlen(source[i].nama);
        }
    }

    // Mencetak header tabel
    printf("Kode ");
    if (spacekode < 4) {
        for (int i = 0; i < 4 - 4; i++) {
            printf(" ");
        }
    }else{
        for (int i = 0; i < spacekode - 4; i++) {
            printf(" ");
        }
    }
    printf("NamaDosen ");
    if (spacename <  9) {
        for (int i = 0; i < 9 - 9; i++) {
            printf(" ");
        }  
    }else{
        for (int i = 0; i < spacename - 9; i++) {
            printf(" ");
        }    
    }
    
    printf("\n");
     // Mencetak data dalam tabel
    for(int i = 0; i < *n; i++) {
        printf("%s ", source[i].kode);
        if (spacekode < 3) {
            for (int j = 0; j < 3 - strlen(source[i].kode); j++) {
                printf(" ");
            }
        }else{
            for (int j = 0; j < spacekode - strlen(source[i].kode); j++) {
                printf(" ");
            }
        }
        printf("%s ", source[i].nama);
        if (spacename < 9) {
            for (int j = 0; j < 9 - strlen(source[i].nama); j++) {
                printf(" ");
            }
        }else{
            for (int j = 0; j < spacename - strlen(source[i].nama); j++) {
                printf(" ");
            }    
        }
        printf("\n");
    }    
}
