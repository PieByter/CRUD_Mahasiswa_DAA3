#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>

using namespace std;

struct data_mhs
{
    int no;
    string nama;
    string nim;
    string tgl_lhr;
    int jlh_matkul;
    string matkul[25];
};

int jlh_mhs = 0;
struct data_mhs mahasiswa[125];

void new_data(int no)
{
    int jlh;
    fflush(stdin);
    printf("Nama          : ");
    cin.ignore();
    getline(cin, mahasiswa[no].nama);

    printf("NIM           : ");
    cin >> mahasiswa[no].nim;

    printf("Tanggal Lahir : ");
    cin.ignore();
    getline(cin, mahasiswa[no].tgl_lhr);

    printf("Jumlah Mata Kuliah : ");
    cin >> jlh;
    fflush(stdin);
    mahasiswa[no].jlh_matkul = jlh;

    printf("Mata Kuliah   : \n");
    for (int i = 0; i < jlh; i++)
    {
        printf("%d. ", i + 1);
        cin.ignore();
        getline(cin, mahasiswa[no].matkul[i]);
    }
}

void create()
{
    int temp;
    cout << "Masukkan Jumlah Mahasiswa : ";
    cin >> temp;
    for (int i = 0; i < temp; i++)
    {
        printf("\nMahasiswa ke - %i\n", jlh_mhs + 1);
        new_data(jlh_mhs);
        mahasiswa[jlh_mhs].no = jlh_mhs + 1;
        jlh_mhs++;
    }
}

void read()
{
    if (jlh_mhs == 0)
    {
        cout << "Belum ada data silahkan masukkan / insert data terlebih dahulu" << endl;
    }
    else
    {
        printf("+==================================+\n");
        printf("|         Daftar Mahasiswa         |\n");
        printf("+==================================+\n");
        for (int i = 0; i < jlh_mhs; i++)
        {
            if (!mahasiswa[i].no)
                continue;
            printf("Mahasiswa ke - %i\n", i + 1);
            printf("Nomor (id)     : %d\n", mahasiswa[i].no);
            printf("Nama           : %s\n", mahasiswa[i].nama.c_str());
            printf("NIM            : %s\n", mahasiswa[i].nim.c_str());
            printf("Tanggal Lahir  : %s\n", mahasiswa[i].tgl_lhr.c_str());
            printf("Mata Kuliah    : (Jlh = %i)\n", mahasiswa[i].jlh_matkul);
            for (int j = 0; j < mahasiswa[i].jlh_matkul; j++)
            {
                printf("%d. %s\n", j + 1, mahasiswa[i].matkul[j].c_str());
            }
            printf("\n");
        }
    }
    cout << "Tekan sembarang tombol untuk kembali ke menu..." << endl;
    char hold_view;
    hold_view = getch();
}

void update()
{
    int no;
    printf("Nomor mahasiswa: ");
    cin >> no;
    new_data(no - 1);
}

void deleted()
{
    int no;
    printf("Nomor mahasiswa: ");
    cin >> no;
    no--;
    mahasiswa[no].no = 0;
    mahasiswa[no].nama = "";
    mahasiswa[no].nim = "";
    mahasiswa[no].tgl_lhr = "";
    int jlh = mahasiswa[no].jlh_matkul;
    mahasiswa[no].jlh_matkul = 0;
    for (int i = 0; i < jlh; i++)
    {
        mahasiswa[no].matkul[i] = "";
    }
}

int main()
{
    int pil;
    while (true)
    {
        system("cls");
        printf("Data Mahasiswa :\n");
        printf("1. Lihat daftar mahasiswa\n");
        printf("2. Tambah data mahasiswa\n");
        printf("3. Update data mahasiswa\n");
        printf("4. Hapus data mahasiswa\n");
        printf("5. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pil);
        printf("\n");
        switch (pil)
        {
        case 1:
            read();
            break;
        case 2:
            create();
            break;
        case 3:
            update();
            break;
        case 4:
            deleted();
            break;
        default:
            printf("Terima kasih telah menggunakan program CRUD ini");
            return 0;
        }
    }
}
