from Crypto.Util.number import bytes_to_long, getPrime


q = getPrime(512)
p = getPrime(512)

n = p*q

e = 0x10001

flag = b"AOFCTF{test_flag}"

m = bytes_to_long(flag)

c = pow(m, e, n)

print(f"n = {n}")
print(f"e = {e}")
print(f"c = {c}")

d = pow(e, -1, (p-1)*(q-1))
d = bin(d)[2:]
d = d[768:]
d = int(d, 2)
print(f"d = {d}")