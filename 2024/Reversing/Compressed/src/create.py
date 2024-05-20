#!/usr/bin/env python3

import zlib
from base64 import b64encode

payload = "_ = lambda __ : __import__('zlib').decompress(__import__('base64').b64decode(__[::-1]));exec((_)(b'PAYLOAD'))"

with open("main.py", "r") as f:
	data = f.read()


data = zlib.compress(data.encode())

data = b64encode(data)[::-1].decode()
payload = payload.replace("PAYLOAD", data)

payload += "\n\n# x = ['JD0CEw==', 'JAMoWQ==', 'JwMCVA==', 'JwMCVA==', 'Ji0kVA==', 'JxMCVA==', 'JAM4EQ==', 'JAM8EA==', 'JD0oEA==', 'JD0KHg==', 'JwM8VA==', 'JAMoEQ==', 'JAMoEw==', 'JBMoVA==', 'Ji0OVA==', 'JD0sHg==', 'Ji0KVA==', 'Jj0OVA==', 'JD0kWg==', 'JD0KWQ==', 'JBMOVA==', 'JAMOVA==', 'Jz0kVA==', 'JD0CHg==', 'JwMoVA==', 'JD0wHg==', 'JD0gEw==', 'JwMgVA==', 'JihUVA==', 'Jy0gVA==', 'Ji0gVA==', 'JAMCVA==', 'JAMOVA==', 'JAM8VA==', 'Jj0sVA==', 'JD04EQ==', 'JD0CWA==', 'JD04Hg==', 'JD04Hg==', 'JD0sXQ==', 'JxM4VA==', 'JxMCVA==', 'JAMwVA==', 'Jz08VA==', 'JD0wXQ==', 'JAM4XQ==', 'JBMsVA==', 'JAMgXQ==', 'JAMgXQ==', 'JD0wHg==', 'JAMoWg==']"

with open("challenge.py", "w") as f:
	f.write(payload)