#include <iostream>
#include <string>
#include <cctype> // Untuk fungsi toupper()

std::string encrypt(const std::string& plaintext, const std::string& key) {
    std::string ciphertext = "";
    std::string upperKey = key;

    // Ubah key menjadi huruf besar
    for (size_t i = 0; i < upperKey.length(); ++i) {
        upperKey[i] = toupper(upperKey[i]);
    }

    size_t keyIndex = 0; // Indeks untuk key
    for (size_t i = 0; i < plaintext.length(); ++i) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            // Enkripsi huruf menggunakan kunci yang diulang
            ciphertext += (plaintext[i] - base + (upperKey[keyIndex % upperKey.length()] - 'A')) % 26 + base;
            keyIndex++; // Naikkan keyIndex hanya untuk karakter alfabet
        } else {
            // Jika karakter non-alfabet, tambahkan langsung ke ciphertext tanpa enkripsi
            ciphertext += plaintext[i];
        }
    }

    return ciphertext;
}

int main() {
    std::string plaintext, key;

    // Input plaintext dan kunci
    std::cout << "Masukkan Plaintext: ";
    std::getline(std::cin, plaintext);

    std::cout << "Masukkan Kunci: ";
    std::getline(std::cin, key);

    // Enkripsi
    std::string ciphertext = encrypt(plaintext, key);

    // Output hasil enkripsi
    std::cout << "Hasil Enkripsi: " << ciphertext << std::endl;

    return 0;
}
