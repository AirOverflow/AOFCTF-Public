#!/usr/bin/env python3
from base64 import b64encode

XOR_KEYS = [0x80, 0x83, 0x3, 0x6, 0x7, 0x9, 0x8a, 0x8b, 0xe, 0x9a, 0x1e, 0xa2, 0xa5, 0x2d, 0x2f, 0x31, 0x34, 0x3d, 0xbd, 0xc0, 0x42, 0x43, 0x45, 0xc7, 0x48, 0xc8, 0x4b, 0x50, 0x57, 0x5d, 0x62, 0x68, 0x70, 0x7d, 0x4, 0xef, 0xf0, 0xd3, 0xf8, 0x1e, 0x7b, 0x3c, 0x45, 0x47, 0x9c, 0x91, 0x71, 0x82, 0x91, 0xcc, 0xb2]
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

x = ['JD0CEw==', 'JAMoWQ==', 'JwMCVA==', 'JwMCVA==', 'Ji0kVA==', 'JxMCVA==', 'JAM4EQ==', 'JAM8EA==', 'JD0oEA==', 'JD0KHg==', 'JwM8VA==', 'JAMoEQ==', 'JAMoEw==', 'JBMoVA==', 'Ji0OVA==', 'JD0sHg==', 'Ji0KVA==', 'Jj0OVA==', 'JD0kWg==', 'JD0KWQ==', 'JBMOVA==', 'JAMOVA==', 'Jz0kVA==', 'JD0CHg==', 'JwMoVA==', 'JD0wHg==', 'JD0gEw==', 'JwMgVA==', 'JihUVA==', 'Jy0gVA==', 'Ji0gVA==', 'JAMCVA==', 'JAMOVA==', 'JAM8VA==', 'Jj0sVA==', 'JD04EQ==', 'JD0CWA==', 'JD04Hg==', 'JD04Hg==', 'JD0sXQ==', 'JxM4VA==', 'JxMCVA==', 'JAMwVA==', 'Jz08VA==', 'JD0wXQ==', 'JAM4XQ==', 'JBMsVA==', 'JAMgXQ==', 'JAMgXQ==', 'JD0wHg==', 'JAMoWg==']

print("Well, hello there.")
