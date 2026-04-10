#include <iostream>
using namespace std;

struct Entry {
    int prefix;
    char c;
};

// Buscar si (prefijo, carácter) ya existe
int findEntry(Entry* dict, int size, int prefix, char c) {
    for (int i = 1; i < size; i++) {
        if (dict[i].prefix == prefix && dict[i].c == c) {
            return i;
        }
    }
    return -1;
}

void compressLZ78(const char* input) {
    Entry* dict = new Entry[1000]; // tamaño fijo simple
    int dictSize = 1; // índice 0 vacío

    int currentPrefix = 0;

    cout << "Salida (indice, caracter):\n";

    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];

        int index = findEntry(dict, dictSize, currentPrefix, c);

        if (index != -1) {
            currentPrefix = index;
        } else {
            cout << "(" << currentPrefix << " , " << c << ")\n";

            dict[dictSize].prefix = currentPrefix;
            dict[dictSize].c = c;
            dictSize++;

            currentPrefix = 0;
        }
    }

    delete[] dict;
}

char* compressLZ78Texto(const char* input) {
    Entry* dict = new Entry[1000];
    int dictSize = 1;
    int currentPrefix = 0;

    char* comprimido = new char[20000];
    int pos = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        int index = findEntry(dict, dictSize, currentPrefix, c);

        if (index != -1) {
            currentPrefix = index;
        } else {
            if (currentPrefix >= 100) comprimido[pos++] = '0' + (currentPrefix / 100) % 10;
            if (currentPrefix >= 10) comprimido[pos++] = '0' + (currentPrefix / 10) % 10;
            comprimido[pos++] = '0' + (currentPrefix % 10);
            comprimido[pos++] = ',';
            comprimido[pos++] = c;
            comprimido[pos++] = ';';

            dict[dictSize].prefix = currentPrefix;
            dict[dictSize].c = c;
            dictSize++;
            currentPrefix = 0;
        }
    }

    comprimido[pos] = '\0';
    delete[] dict;
    return comprimido;
}

char* secuenciaPrefijoLZ78(Entry* dict, int prefix) {
    char temporal[1000];
    int longitud = 0;

    while (prefix != 0 && longitud < 1000) {
        temporal[longitud++] = dict[prefix].c;
        prefix = dict[prefix].prefix;
    }

    char* resultado = new char[longitud + 1];
    int j = 0;

    for (int i = longitud - 1; i >= 0; i--) {
        resultado[j++] = temporal[i];
    }

    resultado[j] = '\0';
    return resultado;
}

char* decompressLZ78Texto(const int* prefixes, const char* chars, int n) {
    Entry* dict = new Entry[1000];
    int dictSize = 1;
    char* textoDescomprimido = new char[10000];
    int pos = 0;

    for (int i = 0; i < n; i++) {
        int p = prefixes[i];
        char c = chars[i];
        char* sec = secuenciaPrefijoLZ78(dict, p);

        for (int j = 0; sec[j] != '\0'; j++) {
            textoDescomprimido[pos++] = sec[j];
        }

        textoDescomprimido[pos++] = c;
        dict[dictSize].prefix = p;
        dict[dictSize].c = c;
        dictSize++;

        delete[] sec;
    }

    textoDescomprimido[pos] = '\0';
    delete[] dict;
    return textoDescomprimido;
}

int contarBloquesLZ78(const char* comprimido) {
    int cantidad = 0;

    for (int i = 0; comprimido[i] != '\0'; i++) {
        if (comprimido[i] == ';') {
            cantidad++;
        }
    }

    return cantidad;
}

void separarLZ78(const char* comprimido, int* prefixes, char* chars, int n) {
    int i = 0;
    int bloque = 0;

    while (comprimido[i] != '\0' && bloque < n) {
        int numero = 0;

        while (comprimido[i] != ',' && comprimido[i] != '\0') {
            numero = numero * 10 + (comprimido[i] - '0');
            i++;
        }

        if (comprimido[i] == ',') {
            i++;
        }

        prefixes[bloque] = numero;
        chars[bloque] = comprimido[i];
        bloque++;

        while (comprimido[i] != ';' && comprimido[i] != '\0') {
            i++;
        }

        if (comprimido[i] == ';') {
            i++;
        }
    }
}
