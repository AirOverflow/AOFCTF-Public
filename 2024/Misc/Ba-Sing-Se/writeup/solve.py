#!/usr/bin/env python3

src = "print(momos_secret)"
payload = ""
for i in src:
	payload += f'chr({ord(i)})+'
payload = payload[:-1]
print(payload)