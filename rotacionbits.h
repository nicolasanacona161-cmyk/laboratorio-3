#ifndef ROTACIONBITS_H
#define ROTACIONBITS_H

unsigned char rotateLeft(unsigned char value, int shift);
unsigned char rotateRight(unsigned char value, int shift);
void encriptarRotacion(char* texto, int desplazamiento);
void desencriptarRotacion(char* texto, int desplazamiento);

#endif // ROTACIONBITS_H
