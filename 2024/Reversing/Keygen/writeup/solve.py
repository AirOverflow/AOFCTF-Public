#!/usr/bin/env python3

from pwn import *

_s1 = { 26: 16, 8: 24, 14: 23, 17: 7, 5: 22, 30: 19, 21: 31, 27: 2, 29: 25, 32: 34, 20: 18, 3: 33, 10: 13, 35: 6, 9: 12, 11: 0, 4: 28, 15: 1 }
_s2 = { 13: 1, 6: 0, 27: 12, 21: 26, 23: 9, 32: 25, 24: 28, 2: 17, 5: 33, 35: 18, 15: 22, 10: 11, 20: 8, 4: 19, 16: 31, 14: 3, 30: 34, 7: 29 }

def decode(_s):
    key = [_s[i] for i in range(len(_s))]
    for k,v in _s1.items():
        key[v], key[k] = key[k], key[v]

    for k,v in _s2.items():
        key[v], key[k] = key[k], key[v]

    return "".join([str(i) for i in key])

lic = "2db18f01-f1b2-4396-b663-90f99f9fcd02"
key = decode(lic)
print(key)

io = remote(sys.argv[1], sys.argv[2]
    ) if args.REMOTE else process("./keygen")
io.sendlineafter(b"key: ", key.encode())
io.interactive()
