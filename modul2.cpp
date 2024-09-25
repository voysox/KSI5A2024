#include <iostream>
#include <string>
using namespace std;

void enkripsi() {
    string plainteks, cipherteks;
    int i, k;
    char c;

    cout << "Ketikkan pesan: ";
    cin.ignore();  // Mengabaikan input sebelumnya
    getline(cin, plainteks);  // Mengambil seluruh input sebagai plainteks

    cout << "Masukkan jumlah pergeseran (0-25): ";
    cin >> k;

    for (i = 0; i < plainteks.length(); i++) {
        c = plainteks[i];
        if (isalpha(c)) {  // Mengecek apakah karakter adalah huruf
            c = toupper(c);  // Mengubah huruf menjadi huruf besar
            c = c - 65;  // Mengonversi huruf menjadi indeks 0-25
            c = (c + k) % 26;  // Melakukan enkripsi Caesar
            c = c + 65;  // Mengembalikan ke karakter huruf
        }
        cipherteks += c;  // Menambahkan karakter terenkripsi ke cipherteks
    }

    cout << "Cipherteks: " << cipherteks << endl;  // Menampilkan cipherteks
}

void dekripsi() {
    string plainteks, cipherteks;
    int i, k;
    char c;

    cout << "Ketikkan cipherteks: ";
    cin.ignore();  // Mengabaikan input sebelumnya
    getline(cin, cipherteks);  // Mengambil seluruh input sebagai cipherteks

    cout << "Masukkan jumlah pergeseran (0-25): ";
    cin >> k;

    for (i = 0; i < cipherteks.length(); i++) {
        c = cipherteks[i];
        if (isalpha(c)) {  // Mengecek apakah karakter adalah huruf
            c = toupper(c);  // Mengubah huruf menjadi huruf besar
            c = c - 65;  // Mengonversi huruf menjadi indeks 0-25
            c = (c - k + 26) % 26;  // Melakukan dekripsi Caesar
            c = c + 65;  // Mengembalikan ke karakter huruf
        }
        plainteks += c;  // Menambahkan karakter terdekripsi ke plainteks
    }

    cout << "Plainteks: " << plainteks << endl;  // Menampilkan plainteks
}

int main() {
    int pil;
    bool stop = false;

    while (!stop) {
        cout << "Menu" << endl;
        cout << "1. Enkripsi" << endl;
        cout << "2. Dekripsi" << endl;
        cout << "3. Exit" << endl;
        cout << "Pilih menu: ";
        cin >> pil;

        switch (pil) {
            case 1:
                enkripsi();
                break;
            case 2:
                dekripsi();
                break;
            case 3:
                stop = true;
                break;
        }
    }

    return 0;
}
