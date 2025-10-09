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
    cout << "Daftar Mahasiswa Terdaftar:\n";
    cout << "------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". NPM: " << mhs[i].npm << " - " << mhs[i].nama << "\n";
    }
    cout << "------------------------------------\n\n";
}

int binarySearchNPM(Mahasiswa mhs[], int n, long long target)
{
    int l = 0, r = n - 1;
    int counter = 0;

    cout << "\n>>> Memulai Binary Search <<<\n";

    while (l <= r)
    {
        counter++;
        int m = l + (r - l) / 2;

        cout << "\nIterasi ke-" << counter << ":\n";
        cout << "Index median: " << m << " (NPM: " << mhs[m].npm << ")\n";

        if (mhs[m].npm == target)
        {
            cout << "NPM ditemukan pada iterasi ke-" << counter << "!\n";
            return m;
        }
        else if (mhs[m].npm < target)
        {
            cout << "Mencari di kanan (NPM lebih besar)\n";
            l = m + 1;
        }
        else
        {
            cout << "Mencari di kiri (NPM lebih kecil)\n";
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
    const int n = 10;
    Mahasiswa mahasiswa[n] = {
        {2415061001, "I Made Dipa"},
        {2415061021, "Opik Novrizal"},
        {2415061025, "Citra Dewi"},
        {2415061037, "Dian Puspita"},
        {2415061048, "Eko Wijaya"},
        {2415061055, "Fitri Handayani"},
        {2415061090, "Rifki Yudika"},
        {2415061091, "Riffa Yudika"},
        {2415061105, "Hengky Kurniawan"},
        {2455061007, "Bintang Prasetyo"}};

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