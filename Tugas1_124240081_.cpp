#include <iostream>
using namespace std;

void menu(int &pil)
{
    cout << "============ Toko Kelontong B-2 ============" << endl;
    cout << "=================== Menu ===================" << endl;
    cout << "============================================" << endl;
    cout << "1. Input Data Barang" << endl;
    cout << "2. Tampilkan Data Barang" << endl;
    cout << "3. Cari Data Barang" << endl;
    cout << "4. Keluar" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Masukkan Pilihan Anda : ";
    cin >> pil;
    system("cls");
}

struct data
{
    string nama;
    int jumlah, harga;
} DATA[9999];

void input_data(int &banyak)
{
    int tambahdata;
    cout << "============ Toko Kelontong B-2 ============" << endl;
    cout << "============ Input Data Barang =============" << endl;
    cout << "============================================" << endl;
    cout << "Berapa Data Barang yang Ingin diMasukkan : ";
    cin >> tambahdata;
    for (int i = banyak; i < banyak + tambahdata; i++)
    {
        cout << " " << endl;
        cout << " " << i + 1;
        cout << "   Nama   : ";
        cin.ignore();
        getline(cin, DATA[i].nama);
        cout << "     Jumlah : ";
        cin >> DATA[i].jumlah;
        cout << "     Harga  : ";
        cin >> DATA[i].harga;
    }
    banyak += tambahdata;
}

void BubbleSort(int banyak)
{
    for (int i = 0; i < banyak - 1; i++)
    {
        for (int j = 0; j < banyak - 1 - i; j++)
        {
            if (DATA[j].nama > DATA[j + 1].nama)
            {
                swap(DATA[j], DATA[j + 1]);
            }
        }
    }
}

void output_data(int banyak)
{
    cout << "============ Toko Kelontong B-2 ============" << endl;
    cout << "=========== Tampilan Data Barang ===========" << endl;
    cout << "============================================" << endl;
    cout << "Index     Nama      Jumlah     Harga (Rp)" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < banyak; i++)
    {
        cout << i << "         " << DATA[i].nama << "        " << DATA[i].jumlah << "         " << DATA[i].harga << endl;
    }
    cout << "-------------------------------------------" << endl;
}

void SequentialSearch(int &banyak)
{
    int cari;
    bool found = false; // var found utk mengetahui data ditemukan atau tidak
    cout << "============ Toko Kelontong B-2 ============" << endl;
    cout << "=============== Menu Search ================" << endl;
    cout << "============================================" << endl;
    cout << "Masukkan Harga yang Akan Anda Cari :  ";
    cin >> cari;

    cout << "============================================" << endl;
    cout << "Index     Nama      Jumlah     Harga (Rp)" << endl;
    cout << "--------------------------------------------" << endl;

    for (int i = 0; i < banyak; i++)
    {
        if (DATA[i].harga == cari)
        {
            found = true;
            cout << i << "     " << DATA[i].nama << "        " << DATA[i].jumlah << "     " << DATA[i].harga << endl;
        }
    }

    cout << "--------------------------------------------" << endl;

    if (!found)
    {
        cout << "Data dengan Harga Barang " << cari << " Tidak Ditemukan" << endl;
    }
}

void BinarySearch(int &banyak)
{
    string cari2;
    bool found = false;
    int awal, tengah, akhir;

    cout << "============ Toko Kelontong B-2 ============" << endl;
    cout << "=============== Menu Search ================" << endl;
    cout << "============================================" << endl;
    cout << "Masukkan Nama yang Akan Anda Cari :  ";
    cin.ignore();
    getline(cin, cari2);

    awal = 0;
    akhir = banyak - 1;

    while (awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (DATA[tengah].nama == cari2)
        {
            found = true;
            cout << "============================================" << endl;
            cout << "Index     Nama      Jumlah     Harga (Rp)" << endl;
            cout << "--------------------------------------------" << endl;
            cout << tengah << "     " << DATA[tengah].nama << "        " << DATA[tengah].jumlah << "     " << DATA[tengah].harga << endl;
        }
        if (cari2 < DATA[tengah].nama)
        {
            akhir = tengah - 1;
        }
        else
        {
            awal = tengah + 1;
        }
    }

    cout << "--------------------------------------------" << endl;

    if (!found)
    {
        cout << "Data dengan Nama Barang " << cari2 << " Tidak Ditemukan" << endl;
    }
}

int main()
{

    int pilihan, cari1;
    int banyak = 0;
    char pilihya;
    bool kembali = true;

    do
    {
        menu(pilihan);

        switch (pilihan)
        {
        case 1:
            input_data(banyak);
            cout << "Tekan Enter Untuk Kembali Ke Menu..." << endl;
            getchar();
            getchar();
            system("cls");
            break;

        case 2:
            BubbleSort(banyak);
            output_data(banyak);
            cout << "Apakah Anda Ingin Kembali ke Menu Awal? (y/t) : ";
            cin >> pilihya;
            cin.ignore();
            if (pilihya == 'y' || pilihya == 'Y')
            {
                kembali = true;
            }
            else if (pilihya == 't' || pilihya == 'T')
            {
                kembali = false;
            }
            system("cls");
            break;

        case 3:
            do
            {
                cout << "============ Toko Kelontong B-2 ============" << endl;
                cout << "=============== Menu Search ================" << endl;
                cout << "============================================" << endl;
                cout << "1. Berdasarkan Harga (Sequential Search)" << endl;
                cout << "2. Berdasarkan Nama (Binary Search)" << endl;
                cout << "3. Kembali" << endl;
                cout << "--------------------------------------------" << endl;
                cout << "Masukkan Pilihan Search Anda : ";
                cin >> cari1;
                system("cls");

                switch (cari1)
                {
                case 1:
                    SequentialSearch(banyak);
                    cout << "Tekan Enter Untuk Kembali Ke Menu Search" << endl;
                    getchar();
                    getchar();
                    system("cls");
                    break;

                case 2:
                    BinarySearch(banyak);
                    cout << "Tekan Enter Untuk Kembali Ke Menu Search" << endl;
                    getchar();
                    system("cls");
                    break;

                case 3:
                    break;

                default:
                    cout << "Pilihan Menu Anda Tidak Tersedia" << endl;
                    cout << "Silahkan Tekan Enter untuk Kembali ke Menu Search" << endl;
                    getchar();
                    getchar();
                    system("cls");
                }
            } while (cari1 != 3);
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "Pilihan Menu Anda Tidak Tersedia" << endl;
            cout << "Silahkan Tekan Enter untuk Kembali ke Menu Awal" << endl;
            getchar();
            getchar();
            system("cls");
        }

    } while (pilihan != 4 && kembali);
}