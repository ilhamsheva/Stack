#include <iostream>

using namespace std;

int maximum = 6;
int top = 0;
string Buku[6];

// jika stack penuh
bool isFull() {
    if (top == maximum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// jika stack kosong
bool isEmpty() {
    if (top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// fungsi untuk menambahkan data
void pushStack(string data) {
    if (top >= maximum)
    {
        cout << "Stack sudah penuh" << endl;
    }
    else{
        Buku[top] = data;
        top++;
    }
}

// fungsi untuk menampilkan data
void displayStack() {
    cout << "Data yang ada : " <<  endl;
    for (int i = maximum - 1; i >= 0; i--)
    {
        if (Buku[i] != "") // jika data tidak kosong
        {
            cout << "Data : " << Buku[i] << endl;
        }
    }
    cout << "\n";
}

// fungsi untuk mengeluarkan data
void popStack() {
    if (top >= maximum)
    {
        cout << "Stack sudah penuh" << endl;
    }
    else{
        Buku[top - 1] = ""; // mengeluarkan data
    }   
}

// fungsi untuk melihat data
void peekStack(int posisi){
    if (top >= maximum)
    {
        cout << "Stack sudah penuh" << endl;
    }
    else{
        int index = top; // index sama dengan top
        for (int i = 0; i < posisi; i++)
        {
            index--;
        }
        cout << "Data ke-" << posisi << " : " << Buku[index] << endl; // menampilkan index
    }
}

// fungsi untuk menghitung
int countStack(){
    cout << "Jumlah Data : " << top << endl;
    return top;
}

// fungsi untuk mengubah
void changeStack(int posisi, string data){
    if (top >= maximum)
    {
        cout << "Stack sudah penuh" << endl;
    }
    else{
        int index = top; // index sama dengan top
        for (int i = 0; i < posisi; i++)
        {
            index--;
        }
        Buku[index] = data;
    }
}

void destroyStack(){
    for (int i = 0; i < top; i++) 
    {
        Buku[i] = ""; // mengeluarkan semua data
    }
    top = 0; // top dikembalikan seperti semula
}
int main(){
    pushStack("Daffa");
    pushStack("Ilham");
    pushStack("Idham");
    displayStack();

    changeStack(2, "Sahla");
    displayStack();

    destroyStack();
    displayStack();

    cout << "Apakah Data penuh?" << isFull() << endl;
    cout << "Apakah Data Kosong?" << isEmpty() << endl;


    
    return 0;
}