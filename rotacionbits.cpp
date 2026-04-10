#include <iostream>

using namespace std;

unsigned char rotateLeft(unsigned char value, int shift) {
    return (value << shift) | (value >> (8 - shift));
}

unsigned char rotateRight(unsigned char value, int shift) {
    return (value >> shift) | (value << (8 - shift));
}

void encriptarRotacion(char* texto, int desplazamiento) {
    for (int i = 0; texto[i] != '\0'; i++) {
        texto[i] = rotateLeft(static_cast<unsigned char>(texto[i]), desplazamiento);
    }
}

void desencriptarRotacion(char* texto, int desplazamiento) {
    for (int i = 0; texto[i] != '\0'; i++) {
        texto[i] = rotateRight(static_cast<unsigned char>(texto[i]), desplazamiento);
    }
}
