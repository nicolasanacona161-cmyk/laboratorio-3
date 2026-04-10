#include "lectura.h"
#include "escritura.h"
#include "rle.h"
#include "rotacionbits.h"
#include <bitset>
#include "xor.h"
#include "lz78.h"

int main(){
    cout<<"---------------Lectura--------------------"<<endl;
    char str[256];
    string prueba,r_prueba;
    lecturachar(leer_archiv("archivoprueba.txt"));
    escritura(&str[0]);
    prueba=lecturalinea(leer_archiv("archivoprueba.txt"));
    cout<<"---------------RLE--------------------"<<endl;
    r_prueba=rleCompress(prueba);
    cout <<r_prueba<<endl;

    cout<<"---------------Rotacion Bits---------"<<endl;
    unsigned char str2, result;
    unsigned char c = 'A'; // 65
    str2=0b01000001;
    result=rotateLeft(c,2);

    cout<< result<<endl;
    cout<< rotateRight(result,2)<<endl;

    cout << "Original: " << bitset<8>(str2) << endl;
    cout << "Rotado:   " << bitset<8>(result) << endl;

    cout<<"---------------XOR------------"<<endl;
    char text[] = "HOLA";

    cout << "Original: " << text <<endl;

    // Encriptar
    xorCipherPtr(text, 'K');
    cout << "Encriptado: " << text << endl;

    // Desencriptar (misma función)
    xorCipherPtr(text, 'K');
    cout << "Desencriptado: " << text << endl;
    cout<<"---------------LZ78------------"<<endl;

    char text2[] = "ABAABABAABBBBBBBBB";

    cout << "Texto original: " << text2 << endl;

    compressLZ78(text2);
    cout <<"---------------Excepciones------------";

    try{
        throw 10;
    }
    catch (char *excp)  {
        cout << "Excp " << excp;
    }
    catch (...)  {
        cout << "Excp por defecto\n";
    }
    return 0;
}
