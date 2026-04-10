#ifndef LZ78_H
#define LZ78_H

void compressLZ78(const char* input);
char* compressLZ78Texto(const char* input);
char* decompressLZ78Texto(const int* prefixes, const char* chars, int n);
void separarLZ78(const char* comprimido, int* prefixes, char* chars, int n);
int contarBloquesLZ78(const char* comprimido);

#endif // LZ78_H
