#!/usr/bin/env python3

flag = "AOFCTF{g1t_1s_r3ally_us3ful_y0u_sh0uld_l34rn_1t}"
KEY = 0x69

out = "unsigned char flag[] = { ";

for i in range(len(flag)):
	elem = ord(flag[i]) ^ KEY
	out += hex(elem) + ", "
out += " 0x0 }; ";

print(out)