#include <iostream>
#include <string>

#include "lz78.h"
#include "rle.h"
#include "rotacionbits.h"
#include "xor.h"

using namespace std;

void copiarTexto(char* destino, const char* origen) {
    int i = 0;

    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }

    destino[i] = '\0';
}

bool sonIguales(const char* texto1, const char* texto2) {
    int i = 0;

    while (texto1[i] != '\0' || texto2[i] != '\0') {
        if (texto1[i] != texto2[i]) {
            return false;
        }
        i++;
    }

    return true;
}

int main() {
    try {
        cout << "----- RLE -----" << endl;
        string textoRLE = "AAAABBBCCDAA";
        string comprimidoRLE = rleCompress(textoRLE);
        string descomprimidoRLE = rleDecompress(comprimidoRLE);

        cout << "Texto original: " << textoRLE << endl;
        cout << "Texto comprimido: " << comprimidoRLE << endl;
        cout << "Texto descomprimido: " << descomprimidoRLE << endl;

        if (textoRLE != descomprimidoRLE) {
            throw "Error en RLE";
        }

        cout << "\n----- LZ78 -----" << endl;
        char textoLZ78[] = "ABAABABAABBBBBBBBB";
        char* comprimidoLZ78 = compressLZ78Texto(textoLZ78);
        int cantidad = contarBloquesLZ78(comprimidoLZ78);
        int* prefijos = new int[cantidad];
        char* caracteres = new char[cantidad];
        char* descomprimidoLZ78 = 0;

        separarLZ78(comprimidoLZ78, prefijos, caracteres, cantidad);
        descomprimidoLZ78 = decompressLZ78Texto(prefijos, caracteres, cantidad);

        cout << "Texto original: " << textoLZ78 << endl;
        cout << "Texto comprimido: " << comprimidoLZ78 << endl;
        cout << "Texto descomprimido: " << descomprimidoLZ78 << endl;

        if (!sonIguales(textoLZ78, descomprimidoLZ78)) {
            delete[] comprimidoLZ78;
            delete[] prefijos;
            delete[] caracteres;
            delete[] descomprimidoLZ78;
            throw "Error en LZ78";
        }

        cout << "\n----- Rotacion de bits -----" << endl;
        char datosRotacion[200];
        copiarTexto(datosRotacion, comprimidoLZ78);
        cout << "Datos comprimidos: " << comprimidoLZ78 << endl;
        encriptarRotacion(datosRotacion, 2);
        desencriptarRotacion(datosRotacion, 2);
        cout << "Datos recuperados: " << datosRotacion << endl;

        if (!sonIguales(comprimidoLZ78, datosRotacion)) {
            delete[] comprimidoLZ78;
            delete[] prefijos;
            delete[] caracteres;
            delete[] descomprimidoLZ78;
            throw "Error en rotacion";
        }

        cout << "\n----- XOR -----" << endl;
        char datosXOR[200];
        copiarTexto(datosXOR, comprimidoLZ78);
        cout << "Datos comprimidos: " << comprimidoLZ78 << endl;
        encriptarXOR(datosXOR, 'K');
        desencriptarXOR(datosXOR, 'K');
        cout << "Datos recuperados: " << datosXOR << endl;

        if (!sonIguales(comprimidoLZ78, datosXOR)) {
            delete[] comprimidoLZ78;
            delete[] prefijos;
            delete[] caracteres;
            delete[] descomprimidoLZ78;
            throw "Error en XOR";
        }

        delete[] comprimidoLZ78;
        delete[] prefijos;
        delete[] caracteres;
        delete[] descomprimidoLZ78;

        cout << "\nTodas las pruebas salieron bien." << endl;
    }
    catch (const char* error) {
        cout << error << endl;
    }
    catch (...) {
        cout << "Ocurrio un error inesperado." << endl;
    }

    return 0;
}
