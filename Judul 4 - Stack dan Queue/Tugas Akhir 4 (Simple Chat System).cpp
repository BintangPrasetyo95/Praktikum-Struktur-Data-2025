#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const int MAX = 100;
struct Message
{
    string text;
    string time;
};

Message st[MAX];
int topIdx = -1;

bool isEmpty();
bool isFull();
void sendMessage(const string &msg);
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
        cout << "\n=== SIMPLE CHAT (Stack with Time) ===\n";
        cout << "1. Send Message\n";
        cout << "2. Undo (hapus pesan terakhir)\n";
        cout << "3. Peek (lihat pesan terakhir)\n";
        cout << "4. Tampilkan chat history\n";
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
            cout << "Ketik pesan: ";
            getline(cin, temp);
            sendMessage(temp);
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

void sendMessage(const string &msg)
{
    if (isFull())
    {
        cout << "Chat penuh, tidak bisa mengirim pesan.\n";
        return;
    }

    Message newMsg;
    newMsg.text = msg;
    newMsg.time = getCurrentTime();

    st[++topIdx] = newMsg;

    cout << "[" << newMsg.time << "] You: " << newMsg.text << "\n";
}

void undo()
{
    if (isEmpty())
    {
        cout << "Tidak ada pesan untuk di-undo.\n";
        return;
    }

    Message last = st[topIdx--];
    cout << "Undo berhasil. Pesan \"" << last.text
         << "\" (" << last.time << ") dihapus.\n";
}

void peek()
{
    if (isEmpty())
    {
        cout << "Chat kosong.\n";
        return;
    }

    Message top = st[topIdx];
    cout << "Pesan teratas: [" << top.time << "] " << top.text << "\n";
}

void display()
{
    if (isEmpty())
    {
        cout << "Chat kosong.\n";
        return;
    }

    cout << "History chat (teratas -> terbawah):\n";
    for (int i = topIdx; i >= 0; --i)
    {
        cout << (topIdx - i + 1) << ". [" << st[i].time << "] "
             << st[i].text << "\n";
    }
}