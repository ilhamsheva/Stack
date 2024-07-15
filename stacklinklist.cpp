#include <iostream>

using namespace std;

struct Mahasiswa
{
    string nama, nim, jurusan;
    Mahasiswa *next;
    Mahasiswa *prev;
};

Mahasiswa *head, *tail, *cur, *newNode, *afterNode, *del, *posisi;
int maksimal = 6;

// fungsi untuk menghitung data
int countList()
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        int banyak = 0;
        cur = head;
        while (cur != NULL)
        {
            cur = cur->next;
            banyak++;
        }
        return banyak;
    }
}

// fungsi untuk menambahkan data
void pushStack(string data[3])
{
    if (countList() == maksimal)
    {
        cout << "Stack sudah penuh" << endl;
    }
    else
    {
        if (countList() == 0) // jika data belum ada maka buat data terlebih dahulu
        {
            head = new Mahasiswa(); // head diisi dengan node baru
            head->nama = data[0];
            head->nim = data[1];
            head->jurusan = data[2];
            head->prev = NULL;
            head->next = NULL;
            tail = head; // tail diisi dengan head
        }
        else
        {                              // jika data sudah ada, maka tambahkan data
            newNode = new Mahasiswa(); // newNode diisi dengan node baru
            newNode->nama = data[0];
            newNode->nim = data[1];
            newNode->jurusan = data[2];
            newNode->prev = tail; // newNode sebelumnya diisi dengan tail
            newNode->next = NULL; // newNode selanjutnya tidak diisi
            tail->next = newNode; // tail selanjutnya diisi dengan newNode
            tail = newNode;       // tail diisi dengan newNode
        }
    }
}

// fungsi untuk menampilkan data
void displayStack()
{
    cout << "DATA YANG DIINPUT" << endl;
    cur = tail;
    while (cur != NULL)
    {
        cout << "Nama       : " << cur->nama << endl;
        cout << "NIM        : " << cur->nim << endl;
        cout << "Jurusan    : " << cur->jurusan << "\n" << endl;
        cur = cur->prev;
    }
}

// fungsi untuk cek apakah data kosong atau tidak
bool isEmpty()
{
    if (countList() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// fungsi untuk cek apakah data penuh atau tidak
bool isFull()
{
    if (countList() == maksimal)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// fungsi untuk menghapus data
void popStack()
{
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
}

// fungsi untuk mengintip data
void peekStack(int posisi)
{
    if (countList() == 0)
    {
        cout << "Stack Kosong" << endl;
    }
    else
    {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi - 1){
            cur = cur->prev;
            nomor++;
        }
    }
    cout << "Data Posisi Ke-" << posisi << " : " << endl;
    cout << "Nama       : " << cur->nama << endl;
    cout << "NIM        : " << cur->nim << endl;
    cout << "Jurusan    : " << cur->jurusan << endl;
    cout << "\n";
}

// fungsi untuk mengubah isi data
void changeStack(int posisi, string data[3])
{
    if (countList() == 0)
    {
        cout << "Stack Kosong" << endl;
    }
    else
    {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi - 1)
        {
            cur = cur->prev;
            nomor++;
        }
        cur->nama = data[0];
        cur->nim = data[1];
        cur->jurusan = data[2];
    }
}

// fungsi untuk menghapus semua data
void destroyStack(){
    cur = head;
    while (cur != NULL)
    {
        del = cur;
        cur = cur->next;
        delete del;
    }
    head = NULL;
    tail = NULL;
}

// fungsi utama
int main()
{
    string data1[3] = {"Daffa", "22001", "Teknik Informatika"};
    string data2[3] = {"Ilham", "22002", "Teknik Informatika"};
    pushStack(data1);
    pushStack(data2);
    displayStack();

    cout << "Jumlah Data : " << countList() << endl;

    string data3[3] = {"Idham Kholid", "20230801008", "Teknik Informatika"};
    changeStack(1, data3);
    displayStack();

    destroyStack();
    cout << "Apakah Data penuh?" << isFull() << endl;
    cout << "Apakah Data Kosong?" << isEmpty() << endl;



    return 0;
}