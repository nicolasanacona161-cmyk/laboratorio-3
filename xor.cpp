void xorCipherPtr(char* text, char key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] ^ key;
    }
}

void encriptarXOR(char* text, char key) {
    xorCipherPtr(text, key);
}

void desencriptarXOR(char* text, char key) {
    xorCipherPtr(text, key);
}
