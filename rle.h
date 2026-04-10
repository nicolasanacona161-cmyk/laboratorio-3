#ifndef RLE_H
#define RLE_H

#include <iostream>
using namespace std;

string rleCompress(const string& input);
string rleCompressPtr(const char* input);
string rleDecompress(const string& input);

#endif // RLE_H
