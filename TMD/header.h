/*Saya Muhammad Akhtar Rizki Ramadha mengerjakan evaluasi Tugas Masa Depan 
dalam mata kuliah Algoritma dan Pemrograman II untuk keberkahanNya 
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <string.h>

// Mendefinisikan struktur data first yang terdiri dari nim, nama, prodi, dan dosen
typedef struct {
    char nim[10];
    char nama[50];
    char prodi[50];
    char dosen[10];
}first;

// Mendefinisikan struktur data second yang terdiri dari kode dan nama
typedef struct {
    char kode[10];
    char nama[50];
}second;

// Deklarasi variabel global indeks, panjangkata, dan ckata
int indeks;
int panjangkata;
char ckata[50];

// Deklarasi fungsi untuk memproses kata-kata dalam sebuah string
void STARTKATA (char pita[]);
void RESETKATA ();
int EOPKATA(char pita[]);
void INCKATA (char pita[]);
char* GETCKATA();
int GETPANJANGKATA();

// Deklarasi fungsi untuk membaca data dari file
void READ(int *n, first source[], char fileName[]);
void READ2(int *n, second source[], char fileName[]);

// Deklarasi fungsi untuk menulis data ke dalam file
void WRITE(int *n, first source[], char fileName[]);
void WRITE2(int *n, second source[], char fileName[]);

// Deklarasi fungsi untuk mencetak data ke layar
void PRINTJOIN(int *n, first source[]);
void PRINTMHS(int *n, first source[]);
void PRINTPD(int *n, second source[]);
void PRINTDS(int *n, second source[]);

// Deklarasi fungsi untuk menunda eksekusi program dan menampilkan tampilan pembuka
void DELAY(int seconds);
void OPENING();