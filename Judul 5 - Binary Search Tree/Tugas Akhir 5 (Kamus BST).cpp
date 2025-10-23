#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string word;
    string meaning;
    Node *left;
    Node *right;
    Node(string w, string m) : word(w), meaning(m), left(nullptr), right(nullptr) {}
};

Node *insertWord(Node *root, string word, string meaning)
{
    if (!root)
        return new Node(word, meaning);
    if (word < root->word)
        root->left = insertWord(root->left, word, meaning);
    else if (word > root->word)
        root->right = insertWord(root->right, word, meaning);
    else
        cout << "Kata sudah ada!\n";
    return root;
}

bool searchWord(Node *root, string word)
{
    if (!root)
    {
        cout << "Kata tidak ditemukan.\n";
        return false;
    }
    if ( )
    {
        cout << "Arti: " << root->meaning << "\n";
        return true;
    }
    if (word < root->word)
        return searchWord(root->left, word);
    return searchWord(root->right, word);
}

Node *findMin(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

Node *deleteWord(Node *root, string word)
{
    if (!root)
        return nullptr;
    if (word < root->word)
        root->left = deleteWord(root->left, word);
    else if (word > root->word)
        root->right = deleteWord(root->right, word);
    else
    {
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }
        else if (!root->left)
        {
            Node *t = root->right;
            delete root;
            return t;
        }
        else if (!root->right)
        {
            Node *t = root->left;
            delete root;
            return t;
        }
        else
        {
            Node *succ = findMin(root->right);
            root->word = succ->word;
            root->meaning = succ->meaning;
            root->right = deleteWord(root->right, succ->word);
        }
    }
    return root;
}

void showAll(Node *root)
{
    if (!root)
        return;
    showAll(root->left);
    cout << root->word << " = " << root->meaning << "\n";
    showAll(root->right);
}

int countWords(Node *root)
{
    if (!root)
        return 0;
    return 1 + countWords(root->left) + countWords(root->right);
}

int main()
{
    Node *root = nullptr;
    int pilih;
    string word, meaning;
    
    do
    {
        cout << "\n=== KAMUS DIGITAL ===\n";
        cout << "1. Tambah Kata\n";
        cout << "2. Cari Kata\n";
        cout << "3. Hapus Kata\n";
        cout << "4. Tampilkan Semua\n";
        cout << "5. Jumlah Kata\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();
        
        if (pilih == 1)
        {
            cout << "Kata: ";
            getline(cin, word);
            cout << "Arti: ";
            getline(cin, meaning);
            root = insertWord(root, word, meaning);
        }
        else if (pilih == 2)
        {
            cout << "Cari: ";
            getline(cin, word);
            searchWord(root, word);
        }
        else if (pilih == 3)
        {
            cout << "Hapus: ";
            getline(cin, word);
            root = deleteWord(root, word);
        }
        else if (pilih == 4)
        {
            showAll(root);
        }
        else if (pilih == 5)
        {
            cout << "Total: " << countWords(root) << " kata\n";
        }
        
    } while (pilih != 6);
    
    return 0;
}