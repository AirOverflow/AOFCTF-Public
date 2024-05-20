#!/usr/local/bin/python

import hashlib
from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad

try:
    with open("flag.txt", "rb") as file:
        flag = file.read().strip()
except FileNotFoundError:
    print("Flag file not found.")
    exit()

# salt = b"\x69"
salt = b""
key = hashlib.sha256(flag + salt).digest()
cipher = AES.new(key, AES.MODE_CBC, iv=get_random_bytes(16))

def oracle(inp):
    padded_data = pad(flag + inp.encode('utf-8'), AES.block_size)
    encrypted_data = cipher.encrypt(padded_data)
    return encrypted_data.hex()

while True:
    username = input("Enter your username (no whitespace): ")
    print("Your Cookie is: " + oracle(username))
