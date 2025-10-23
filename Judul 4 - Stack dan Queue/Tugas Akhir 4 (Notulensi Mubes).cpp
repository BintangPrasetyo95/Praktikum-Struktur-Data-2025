#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const int MAX = 1000;
struct Notulensi
{
    string text;
    string time;
};

Notulensi st[MAX];
int topIdx = -1;

bool isEmpty(); 
bool isFull();
void insertNotulensi(const string &ntl);
void undo();
void peek();
void display();

string getCurrentTime()
{
    time_t now = time(0);
    string waktu = ctime(&now);
    return waktu.substr(11, 5);
}

int main()
{
    int pilih;
    string temp;

    do
    {
        cout << "\n=== Aplikasi Notulensi Musyawarah Besar ===\n";
        cout << "1. Input Notulensi\n";
        cout << "2. Undo (hapus notulensi terakhir)\n";
        cout << "3. Peek (lihat notulensi terakhir)\n";
        cout << "4. Tampilkan semua notulensi\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        if (!(cin >> pilih))
        {
            cin.clear();
            cin.ignore();
            cout << "Input tidak valid.\n";
            continue;
        }
        cin.ignore();

        if (pilih == 1)
        {
            cout << "Ketik text notulensi: ";
            getline(cin, temp);
            insertNotulensi(temp);
        }
        else if (pilih == 2)
        {
            undo();
        }
        else if (pilih == 3)
        {
            peek();
        }
        else if (pilih == 4)
        {
            display();
        }
        else if (pilih == 5)
        {
            cout << "Terimakasih sudah menggunakan aplikasi ini!\n";
        }
        else
        {
            cout << "Pilihan tidak dikenali.\n";
        }
    } while (pilih != 5);

    return 0;
}

bool isEmpty()
{
    return topIdx == -1;
}

bool isFull()
{
    return topIdx == MAX - 1;
}

void insertNotulensi(const string &ntl)
{
    if (isFull())
    {
        cout << "Notulensi Penuh!, tidak bisa disimpan.\n";
        return;
    }

    Notulensi newNotulensi;
    newNotulensi.text = ntl;
    newNotulensi.time = getCurrentTime();

    st[++topIdx] = newNotulensi;

    cout << "[" << newNotulensi.time << "] You: " << newNotulensi.text << "\n";
}

void undo()
{
    if (isEmpty())
    {
        cout << "Tidak ada Notulensi untuk di-undo.\n";
        return;
    }

    Notulensi --;
    cout << "Undo berhasil. Notulensi \"" << last.text
         << "\" (" << last.time << ") dihapus.\n";
}

void peek()
{
    if (isEmpty())
    {
        cout << "Notulensi kosong.\n";
        return;
    }

    Notulensi top = st[topIdx];
    cout << "Notulensi teratas: [" << top.time << "] " << top.text << "\n";
}

void display()
{
    if (isEmpty())
    {
        cout << "Notulensi kosong.\n";
        return;
    }

    cout << "Notulensi:\n";
    for (int i = topIdx; i >= 0; --i)
    {
        cout << (topIdx - i + 1) << ". [" << st[i].time << "] "
             << st[i].text << "\n";
    }
}