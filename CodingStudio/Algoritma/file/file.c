#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Filebase

    // Read, Write, Append
    /*
        r -> read (membaca isi file)
        w -> write (menulis dgn overwrite all)
        a -> append (menambahkan tulisan)
        r+ -> read, write (overwrite di posisi tertentu)
        > Membuka file untuk membaca dan menulis.
        > File harus sudah ada, jika tidak, operasi akan gagal.
        > Pointer file (file pointer) dimulai di awal file.
        w+ -> read, write (overwrite all) (Membuat file jika tidak ada)
        > Membuka file untuk menulis dan membaca.
        > Jika file sudah ada, isinya akan dihapus; jika tidak, file baru akan dibuat.
        > Pointer file dimulai di awal file.
        a+ -> append, read
        > Membuka file untuk menambah (append) dan membaca.
        > Jika file tidak ada, file baru akan dibuat.
        > Pointer file dimulai di akhir file, sehingga penulisan selalu dilakukan di akhir file.
    */

    // open, process, close

    char txt[200];
    FILE *fp;

    // fp = fopen("data.txt", "w");
    // fprintf(fp, "Hello World!\n");

    // fp = fopen("data.txt", "r");
    // // fscanf(fp, "%s", txt); --> Akan terpotong setelah ada terminator
    // fscanf(fp, "%[^\n]", txt);
    // printf("%s", txt);

    // fp = fopen("data.txt", "a");
    // fprintf(fp, "Hello World 2!\n");

    fp = fopen("data.txt", "w+");
    fprintf(fp, "HaiHai");
    fscanf(fp, "%[^\n]", txt);
    printf("%s", txt);
    

    fclose(fp);
}