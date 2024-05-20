#!/usr/bin/env python3

from base64 import b64encode, b64decode
from random import randint
import zlib

key = 0x41
c_src = """
#include <Python.h>

const int key = {KEY};
char payload[] = {PAYLOAD};

void decrypt(char *buf, int size) {
    for (int i = 0; i < size; i++) {
        buf[i] ^= key;
    }
}

int main(int argc, char *argv[]) {
    decrypt(payload, sizeof(payload));
    Py_SetProgramName(argv[0]);
    Py_Initialize();
    PyRun_SimpleString(payload);
    Py_Finalize();
    return 0;
}
"""

zlib_src = "_ = lambda __ : __import__('zlib').decompress(__import__('base64').b64decode(__[::-1]));exec((_)(b'{PAYLOAD}'))"

py_src = """
#!/usr/bin/env python3
from base64 import b64encode

XOR_KEYS = {XOR_KEYS_LIST}
BASE_KEY = 0x69

def xor(__s: str, k: int) -> str:
    e = ""
    for i in __s:
        e += chr(ord(i) ^ k)
    return e

def encode(flag: str) -> list:
    enc = []
    for i in range(len(flag)):
        enc.append(str(ord(flag[i]) ^ XOR_KEYS[i]))
    for i in range(len(enc)):
        enc[i] = b64encode(enc[i].encode()).decode()
    for i in range(len(enc)):
        enc[i] = xor(enc[i], BASE_KEY)
    for i in range(len(enc)):
        enc[i] = b64encode(enc[i].encode()).decode()
    return enc

x = {FLAG_LIST}

print("Well, hello there.")

"""

def xor(s: str, k: int) -> str:
    e = ""
    for i in s:
        e += chr(ord(i) ^ k)
    return e
