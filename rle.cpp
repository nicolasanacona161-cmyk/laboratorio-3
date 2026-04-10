#include <iostream>
using namespace std;

string rleCompress(const string& input) {
    string result = "";
    int count = 1;
    for (size_t i = 0; i < input.length(); i++) {
        if (i + 1 < input.length() && input[i] == input[i + 1]) {
            count++;
        } else {
            result += input[i];
            result += to_string(count);
            count = 1;
        }
    }
    return result;
}

string rleCompressPtr(const char* input) {
    string result = "";
    int count = 1;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            result += input[i];
            result += to_string(count);
            count = 1;
        }
    }
    return result;
}

string rleDecompress(const string& input) {
    string result = "";

    for (size_t i = 0; i < input.length(); i++) {
        char simbolo = input[i];
        int cantidad = 0;

        if (simbolo >= '0' && simbolo <= '9') {
            continue;
        }

        i++;
        while (i < input.length() && input[i] >= '0' && input[i] <= '9') {
            cantidad = cantidad * 10 + (input[i] - '0');
            i++;
        }

        if (cantidad == 0) {
            cantidad = 1;
        }

        for (int j = 0; j < cantidad; j++) {
            result += simbolo;
        }

        i--;
    }

    return result;
}
