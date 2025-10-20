#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa
{
    long long npm;
    string nama;
};

void tampilkanDaftarMahasiswa(Mahasiswa mhs[], int n)
{
    cout << "========================================\n";
    cout << "  SISTEM PENCARIAN DATA MAHASISWA\n";
    cout << "     Binary Search by NPM\n";
    cout << "========================================\n\n";
    cout << "Daftar NPM Mahasiswa Terdaftar:\n";
    cout << "------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << mhs[i].npm << "\n";
    }
    cout << "------------------------------------\n\n";
}

int binarySearchNPM(Mahasiswa mhs[], int n, long long target)
{
    int l = 0, r = n - 1;
    int counter;

    while (l <= r) {
        int m = l + (l - r) / 2;

        if (mhs[m].npm == target) {
            cout << "Ketemu di " << counter;
        } else if (mhs[m].npm < target) {
            cout << "Tidak ketemu, mencari ke kanan";
            l = m + 1;
        } else {
            cout << "Tidak ketemu, mencari di kiri";
            r = m - 1;
        }
    }

    return -1;
}

void tampilkanHasilPencarian(Mahasiswa mhs[], int pos, long long target)
{
    if (pos != -1)
    {
        cout << "\nMahasiswa ditemukan!\n";
        cout << "NPM  : " << mhs[pos].npm << "\n";
        cout << "Nama : " << mhs[pos].nama << "\n";
    }
    else
    {
        cout << "\nMahasiswa tidak ditemukan!\n";
        cout << "NPM " << target << " tidak terdaftar.\n";
    }
}

int main()
{
    const int n = 32;
    Mahasiswa mahasiswa[n] = {
        {2415061002, "Vivian Rizkiana Fauzi"},
        {2415061004, "Nayla Citra Andira"},
        {2415061005, "Putri Hepti Amelia"},
        {2415061016, "Yostiar Aminudin"},
        {2415061021, "Rizky Novrizal"},
        {2415061023, "Salsabila Aulia Putri"},
        {2415061031, "Rizky Ahmad Fahrezi"},
        {2415061032, "Yaza Nurzahira"},
        {2415061037, "Fany Nuurviana"},
        {2415061039, "Ridho Azhari Putra"},
        {2415061040, "Putri Nabilla Atifa"},
        {2415061046, "Valerie Alana Yusri"},
        {2415061053, "Ica Nuria Ilmawati"},
        {2415061056, "M.Faqih Dwinanda"},
        {2415061057, "Regina Salwa Lestari"},
        {2415061058, "Satriyo Novriyanto"},
        {2415061059, "Kanaya Traylingga Pratama"},
        {2415061067, "Jehan Reza Pahlevi"},
        {2415061070, "Revalina Wanda Sari"},
        {2415061072, "Kadek Dwi Octo Lesa Candigo"},
        {2415061079, "Kholifah Wulandari"},
        {2415061081, "Ledi Daiyana Alfara"},
        {2415061082, "M.Zinedine Zidane"},
        {2415061090, "Rifki Yudika Perdana"},
        {2415061091, "Riffa Yudika Permana"},
        {2415061105, "Hengky Kurniawan"},
        {2415061114, "Edbert Frederick"},
        {2415061119, "Maxwel Raski H Marbun Lumban Gaol"},
        {2455061003, "Hafizh Al-Fayyadh"},
        {2455061007, "Bintang Prastyo Kusumo W."},
        {2455061008, "Rafi Zakwan Kurniawan"},
        {2455061010, "Joshua Andrew Siahaan"}};

    tampilkanDaftarMahasiswa(mahasiswa, n);

    long long targetNPM;
    cout << "Masukkan NPM yang ingin dicari: ";
    cin >> targetNPM;

    int hasil = binarySearchNPM(mahasiswa, n, targetNPM);

    tampilkanHasilPencarian(mahasiswa, hasil, targetNPM);

    cout << "\n==================================\n";
    cout << "  Terima kasih dan sampai jumpa!\n";
    cout << "==================================\n";

    return 0;
}