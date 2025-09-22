#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string judulLagu;
    string namaArtis;
    Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;

void tampilkanMenu();
void tambahLagu(string judul, string artis);
void putarLaguBerikutnya();
void tampilkanPlaylist();

int main()
{
    int pilihan;
    string judul, artis;
    bool running = true;

    tambahLagu("Die With A Smile", "Bruno Mars");
    tambahLagu("BIRDS OF A FEATHER", "Billie Eilish");
    tambahLagu("You'll Be in My Heart", "NIKI");

    while (running)
    {
        tampilkanMenu();
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan Judul Lagu: ";
            getline(cin, judul);
            cout << "Masukkan Nama Artis: ";
            getline(cin, artis);
            tambahLagu(judul, artis);
            break;
        case 2:
            putarLaguBerikutnya();
            break;
        case 3:
            tampilkanPlaylist();
            break;
        case 4:
            cout << "Terima kasih!" << endl;
            running = false;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
        cout << "\n";
    }
    return 0;
}

void tampilkanMenu()
{
    cout << "===== PLAYLIST MUSIK =====" << endl;
    if (head != nullptr)
    {
        cout << "Now Playing: " << head->judulLagu << " - " << head->namaArtis << endl;
    }
    else
    {
        cout << "Now Playing: (Playlist kosong)" << endl;
    }
    cout << "---------------------------------" << endl;
    cout << "1. Tambah Lagu di Akhir Playlist" << endl;
    cout << "2. Putar & Hapus Lagu Berikutnya" << endl;
    cout << "3. Tampilkan Seluruh Playlist" << endl;
    cout << "4. Keluar" << endl;
    cout << "---------------------------------" << endl;
}

void tambahLagu(string judul, string artis)
{
    Node *newNode = new Node();
    newNode->judulLagu = judul;
    newNode->namaArtis = artis;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    cout << "-> Lagu \"" << judul << "\" berhasil ditambahkan." << endl;
}

void putarLaguBerikutnya()
{
    if (head == nullptr)
    {
        cout << "-> Playlist sudah habis." << endl;
        return;
    }

    cout << "-> Memutar lagu: " << head->judulLagu << ". Lagu dihapus dari antrean." << endl;

    Node *temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr)
    {
        tail = nullptr;
    }
}

void tampilkanPlaylist()
{
    cout << "\n--- ISI PLAYLIST ---" << endl;
    if (head == nullptr)
    {
        cout << "(Playlist kosong)" << endl;
        return;
    }

    Node *temp = head;
    int nomor = 1;
    while (temp != nullptr)
    {
        cout << nomor << ". " << temp->judulLagu << " - " << temp->namaArtis << endl;
        temp = temp->next;
        nomor++;
    }
    cout << "--------------------" << endl;
}