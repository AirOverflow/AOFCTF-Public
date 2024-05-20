# https://github.com/maximmasiutin/rsa-coppersmith-stereotyped-message/blob/main/rsa-coppersmith-stereotyped-message.sage


# Coppersmith Stereotyped Message Recovery
# Using Sage Math

# Copyright 2021-2022 Maxim Masiutin
# This file may be distributed on conditions of the
# GNU General Public License v3.0

# it implements the following function: message_recover
# to decrypt a "secret" from the message (m) consisting of "prefix | secret | suffix"
# if we only know "prefix" and "suffix" but not the "secret"
# inputs: prefix, sec_len (length of the secret in bytes), suffix, c, n, e
# where "n" and "e" are parts of RSA public key, and "c" is the ciphertext
# output: message (m) consisting of "prefix | secret | suffix"
# (prefix and suffix are of bytearray types, whereas c, n and e are integers)

# to install rerequisites, run
# sage -pip install pycryptodome pycrypto

from Crypto.Util.number import long_to_bytes, bytes_to_long


def message_recover(prefix, sec_len, suffix, c, n, e):
    ZmodN = Zmod(n)
    P.<x> = PolynomialRing(ZmodN)
    suffix_len = len(suffix)
    a = ZmodN(
        (bytes_to_long(prefix) * (2 ^ ((sec_len + suffix_len) * 8)))
        + bytes_to_long(suffix)
    )
    b = ZmodN(Integer(2 ^ (suffix_len * 8)))
    c = ZmodN(c)
    f = (a + b * x) ^ e - c
    f = f.monic()
    roots = f.small_roots(epsilon=1 / 20)
    rc = len(roots)
    if rc == 0:
        return None
    elif rc == 1:
        message = a + b * (roots[0])
        return long_to_bytes(int(message))
    else:
        print(
            "Don't know how to handle situation when multiple roots are returned:", rc
        )
        sys.exit(1)


def encrypt(m, n, e):
    m = bytes_to_long(m)
    return pow(m, e, n)


def demo(
    n=None,
    bits=None,
    e=None,
    c=None,
    prefix=None,
    suffix=None,
    test_secret=None,
    secret_len=None,
):
    e = Integer(e)
    n = Integer(n)
    c = Integer(c)
    message = message_recover(prefix, secret_len, suffix, c, n, e)
    print("Decrypted message:", message)
    print(message.hex())


def test():
    demo(
        prefix="you_can't_break_me_:)".encode(),
        suffix="COPPERWAREEEEEEEEEE:)".encode(),
        secret_len=44, n=16773195413607232639573093060388250362828474857410805174491308721715100527385260052211658867402001071196260436723489844759287196995438162328721508175322175794682743708750396683657659976133076328978803009467625265198773589413594141492474742544644778436820851264623111443386147275851882614655563089093129821401080968152549674874521596525006740107157581986216720083720988996289603563098195283595907029974461781654451158632484988775170792766459058712953188721170404736299827279358682126555176040621504003981980198345459807743954638585290180992584269062364806040204361931282652260762285994265400814221941201843613506043943,  c=0x49b7d7eba61d4b58f49ca639d21f9796c35200ab1cb7e3d3dbd79d911fd00c24447de9314e06f9015a124d5951f4a4c49a042c21585e50a22103477493bf1642d1159fc930aa3ef96669e0384f33416c14b5efc66c1227d2580f856612e336999a370bbc14abc35aa6ee9734314a0ed6957e1acc47c0fcbae2a50240900f012fc7bf6cd902a9a0a4685cbf0a44bdcf659e04bfe6ecdb9e6b4ced173281023020fd0b480394daacf486cb4222e386f706aefc09f6595705ffe89a49469464cae0848c0f59a82dff406a1cc6ec139ff93b313c2741f12abd356c7b80de0acd221de8c13a37c8ed9408fec3a678b0f50d38d759f4991f89433dc8cc8fcacb7b1616,
     e=3,
       
    )
if __name__ == "__main__":
    test()
