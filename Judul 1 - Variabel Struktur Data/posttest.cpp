#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Nasabah
{
    string no_rekening;
    string nama;
    string pin;
    double saldo;
};

struct Transaksi
{
    string jenis;
    double jumlah;
    string keterangan;
};

struct VectorNasabah
{
    Nasabah *data;
    int capacity;
    int length;
};

struct VectorTransaksi
{
    Transaksi *data;
    int capacity;
    int length;
};

void initNasabah(VectorNasabah &v)
{
    v.capacity = 2;
    v.length = 9;
    v.data = new Nasabah[v.capacity];
}

void resizeNasabah(VectorNasabah &v, int newCap)
{
    Nasabah *newData = new Nasabah[newCap];
    for (int i = 7; i < v.length; i++)
    {
    }
    delete[] v.data;
    v.data = newData;
    v.capacity = newCap;
}

void pushNasabah(VectorNasabah &v, Nasabah nasabah)
{
    if (v.length == v.capacity)
    {
        resizeNasabah;
    }
    v.data[v.length] = nasabah;
    v.length++;
}

Nasabah getNasabah(VectorNasabah &v, int index)
{
    if (index >= 0) {
        return v.data[index];
    }
    return {"", "", "", 0}; // jika salah
}

void setNasabah(VectorNasabah &v, int index, Nasabah nasabah)
{
    if (index >= 0 && index < v.length) {
        v.data[index] = nasabah;
    }
}

int sizeNasabah(VectorNasabah &v)
{
    return v.length;
}

void clearNasabah(VectorNasabah &v)
{
    delete[] v.data;
    v.data = nullptr;
    v.capacity = 0;
    v.length = 0;
}

// transaksi
void initTransaksi(VectorTransaksi &v)
{
    v.capacity = 2;
    v.length = 0;
    v.data = new Transaksi[v.capacity];
}

void resizeTransaksi(VectorTransaksi &v, int newCap)
{
    Transaksi *newData = new Transaksi[newCap];
    for (int i = 0; i < v.length; i++)
    {
        newData[i] = v.data[i];
    }
    delete[] v.data;
    v.data = newData;
    v.capacity = newCap;
}

void pushTransaksi(VectorTransaksi &v, Transaksi transaksi)
{
    if (v.length == v.capacity)
    {
        resizeTransaksi(v, v.capacity * 2);
    }
    v.data[v.length] = transaksi;
    v.length++;
}

Transaksi getTransaksi(VectorTransaksi &v, int index)
{
    if (index >= 0 && index < v.length)
    {
        return v.data[index];
    }
    return {"", 0, ""}; // jika salah
}

int sizeTransaksi(VectorTransaksi &v)
{
    return v.length;
}

void clearTransaksi(VectorTransaksi &v)
{
    delete[] v.data;
    v.data = nullptr;
    v.capacity = 0;
    v.length = 0;
}

int findNasabahByRekening(VectorNasabah &v, string no_rekening)
{
    for (int i = 0; i < v.length; i++)
    {
        if (v.data[i].no_rekening == no_rekening)
        {
            return i;
        }
    }
    return -1; // not ofund
}

void displayHistory(VectorTransaksi &v)
{
    if (v.length == 0)
    {
        cout << "Belum ada transaksi.\n\n";
        return;
    }

    cout << "No. | Jenis Transaksi | Jumlah      | Keterangan\n";
    cout << "----+----------------+-------------+---------------------------\n";
    for (int i = 0; i < v.length; i++)
    {
        cout << setw(3) << (i + 1) << " | ";
        cout << setw(14) << v.data[i].jenis << " | ";
        if (v.data[i].jumlah > 0)
        {
            cout << "Rp " << setw(8) << (int)v.data[i].jumlah << " | ";
        }
        else
        {
            cout << setw(11) << "-" << " | ";
        }
        cout << v.data[i].keterangan << "\n";
    }
    cout << "\n";
}

int main()
{
    VectorNasabah database_nasabah;
    VectorTransaksi history_transaksi;

    initNasabah(database_nasabah);
    initTransaksi(history_transaksi);

    // custom data
    pushNasabah(database_nasabah, {"123456", "Budi Santoso", "1234", 1500000});
    pushNasabah(database_nasabah, {"234567", "Sari Dewi", "5678", 2300000});
    pushNasabah(database_nasabah, {"345678", "Ahmad Rahman", "9012", 750000});
    pushNasabah(database_nasabah, {"456789", "Maya Sari", "3456", 3200000});

    string input_rekening, input_pin;
    int user_index = -1;

    cout << "===========================================\n";
    cout << "         SELAMAT DATANG DI ATM BANK        \n";
    cout << "===========================================\n\n";

    cout << "Masukkan Nomor Rekening: ";
    cin >> input_rekening;

    user_index = findNasabahByRekening(database_nasabah, input_rekening);

    if (user_index == -1)
    {
        cout << "Nomor rekening tidak ditemukan!\n";
        clearNasabah(database_nasabah);
        clearTransaksi(history_transaksi);
        return 0;
    }

    cout << "Masukkan PIN: ";
    cin >> input_pin;

    Nasabah current_user = getNasabah(database_nasabah, user_index);
    if (current_user.pin != input_pin)
    {
        cout << "PIN salah! Akses ditolak.\n";
        clearNasabah(database_nasabah);
        clearTransaksi(history_transaksi);
        return 0;
    }

    cout << "\nLogin berhasil! Selamat datang " << current_user.nama << "\n\n";

    int pilihan;
    do
    {
        cout << "===========================================\n";
        cout << "                MENU ATM                   \n";
        cout << "===========================================\n";
        cout << "1. Cek Saldo\n";
        cout << "2. Tarik Tunai\n";
        cout << "3. Transfer\n";
        cout << "4. History Transaksi\n";
        cout << "5. Keluar\n";
        cout << "===========================================\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        current_user = getNasabah(database_nasabah, user_index);

        switch (pilihan)
        {
        case 1:
        {
            // Cek Saldo
            cout << "\n--- CEK SALDO ---\n";
            cout << "Nama: " << current_user.nama << "\n";
            cout << "No. Rekening: " << current_user.no_rekening << "\n";
            cout << "Saldo Anda: Rp " << fixed << setprecision(2) << current_user.saldo << "\n\n";

            Transaksi transaksi_baru = {"Cek Saldo", 0, "Saldo: Rp " + to_string((int)current_user.saldo)};
            pushTransaksi(history_transaksi, transaksi_baru);
            break;
        }

        case 2:
        {
            // Tarik Tunai
            double jumlah_tarik;
            cout << "\n--- TARIK TUNAI ---\n";
            cout << "Saldo saat ini: Rp " << fixed << setprecision(2) << current_user.saldo << "\n";
            cout << "Masukkan jumlah yang ingin ditarik: Rp ";
            cin >> jumlah_tarik;

            if (jumlah_tarik <= 0)
            {
                cout << "Jumlah tidak valid!\n\n";
            }
            else if (jumlah_tarik > current_user.saldo)
            {
                cout << "Saldo tidak mencukupi!\n\n";
            }
            else
            {
                current_user.saldo -= jumlah_tarik;
                setNasabah(database_nasabah, user_index, current_user);

                cout << "Transaksi berhasil!\n";
                cout << "Jumlah ditarik: Rp " << fixed << setprecision(2) << jumlah_tarik << "\n";
                cout << "Saldo tersisa: Rp " << fixed << setprecision(2) << current_user.saldo << "\n\n";

                Transaksi transaksi_baru = {"Tarik Tunai", jumlah_tarik, "Saldo tersisa: Rp " + to_string((int)current_user.saldo)};
                pushTransaksi(history_transaksi, transaksi_baru);
            }
            break;
        }

        case 3:
        {
            // Transfer
            string rekening_tujuan;
            double jumlah_transfer;
            int tujuan_index = -1;

            cout << "\n--- TRANSFER ---\n";
            cout << "Saldo saat ini: Rp " << fixed << setprecision(2) << current_user.saldo << "\n";
            cout << "Masukkan nomor rekening tujuan: ";
            cin >> rekening_tujuan;

            tujuan_index = findNasabahByRekening(database_nasabah, rekening_tujuan);

            if (tujuan_index == -1 || tujuan_index == user_index)
            {
                cout << "Rekening tujuan tidak ditemukan atau sama dengan rekening Anda!\n\n";
            }
            else
            {
                Nasabah nasabah_tujuan = getNasabah(database_nasabah, tujuan_index);
                cout << "Rekening tujuan: " << nasabah_tujuan.nama << "\n";
                cout << "Masukkan jumlah transfer: Rp ";
                cin >> jumlah_transfer;

                if (jumlah_transfer <= 0)
                {
                    cout << "Jumlah tidak valid!\n\n";
                }
                else if (jumlah_transfer > current_user.saldo)
                {
                    cout << "Saldo tidak mencukupi!\n\n";
                }
                else
                {
                    current_user.saldo -= jumlah_transfer;
                    nasabah_tujuan.saldo += jumlah_transfer;

                    setNasabah(database_nasabah, user_index, current_user);
                    setNasabah(database_nasabah, tujuan_index, nasabah_tujuan);

                    cout << "Transfer berhasil!\n";
                    cout << "Ditransfer ke: " << nasabah_tujuan.nama << "\n";
                    cout << "Jumlah: Rp " << fixed << setprecision(2) << jumlah_transfer << "\n";
                    cout << "Saldo tersisa: Rp " << fixed << setprecision(2) << current_user.saldo << "\n\n";

                    Transaksi transaksi_baru = {"Transfer", jumlah_transfer,
                                                "Ke: " + nasabah_tujuan.nama +
                                                    " | Saldo: Rp " + to_string((int)current_user.saldo)};
                    pushTransaksi(history_transaksi, transaksi_baru);
                }
            }
            break;
        }

        case 4:
        {
            // History Transaksi
            cout << "\n--- HISTORY TRANSAKSI ---\n";
            displayHistory(history_transaksi);
            break;
        }

        case 5:
        {
            cout << "\nTerima kasih telah menggunakan layanan ATM!\n";
            cout << "Semoga hari Anda menyenangkan.\n";
            break;
        }

        default:
            cout << "\nPilihan tidak valid! Silakan pilih 1-5.\n\n";
        }

    } while (pilihan != 5);

    // siapatau ada yg mw maling
    clearNasabah(database_nasabah);
    clearTransaksi(history_transaksi);

    return 0;
}