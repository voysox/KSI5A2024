#include <iostream>
#include <string>

// Fungsi untuk melakukan enkripsi menggunakan Vigenère cipher
std::string encrypt(const std::string& plaintext, const std::string& key) {
    std::string ciphertext = plaintext;
    int keyLength = key.length();

    for (size_t i = 0; i < plaintext.length(); ++i) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = (plaintext[i] - base + (toupper(key[i % keyLength]) - 'A')) % 26 + base;
        }
    }

    return ciphertext;
}

// Fungsi untuk melakukan dekripsi menggunakan Vigenère cipher
std::string decrypt(const std::string& ciphertext, const std::string& key) {
    std::string plaintext = ciphertext;
    int keyLength = key.length();

    for (size_t i = 0; i < ciphertext.length(); ++i) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            plaintext[i] = (ciphertext[i] - base - (toupper(key[i % keyLength]) - 'A') + 26) % 26 + base;
        }
    }

    return plaintext;
}

int main() {
    std::string plaintext = "SISTEMINFORMASI";  // Plaintext
    std::string key = "MASIF";                  // Key

    // Enkripsi
    std::string ciphertext = encrypt(plaintext, key);
    std::cout << "Hasil Enkripsi: " << ciphertext << std::endl;

    // Dekripsi
    std::string decryptedText = decrypt(ciphertext, key);
    std::cout << "Hasil Dekripsi: " << decryptedText << std::endl;

    return 0;
}
