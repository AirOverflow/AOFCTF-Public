#!/usr/bin/local/python3

import hashlib
from Crypto.Cipher import AES

def dumb_pad(imp):
    while len(imp) % 16 != 0:
        imp += b"0"
    return imp

from pathlib import Path

flag_file = Path("flag.txt")

if flag_file.is_file():
    with open(flag_file, "rb") as file:
        flag = file.read().strip()
else:
    print("Flag file not found.")
    exit()

k = hashlib.sha256()
k.update(flag)
key = k.digest()

c = AES.new(key, AES.MODE_ECB)

def oracle(inp):
    return c.encrypt(dumb_pad(flag + inp.encode('utf-8'))).hex()

while True:
    imp = input("Enter your username (no whitespace): ")
    print("Your Cookie is: " + oracle(imp))
