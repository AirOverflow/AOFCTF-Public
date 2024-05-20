#!/usr/bin/env python3

with open("challenge.py", "r") as f:
    data = f.read()

# XOR the entire payload with 0x41:
key = 0x41
final = ""

for i in data:
    final += chr(ord(i) ^ key)

with open("final.xor", "w") as f:
    for i in final:
        f.write(hex(ord(i)) + ",")
