def xor_file(input_file1, input_file2, output_file, key):
    with open(input_file1, 'rb') as f1, open(input_file2, 'rb') as f2:
        data1 = bytearray(f1.read())
        data2 = bytearray(f2.read())

    data = data1 + data2

    for i in range(len(data)):
        data[i] ^= key

    with open(output_file, 'wb') as f:
        f.write(data)

input_file1 = 'chall_half1.bin'
input_file2 = 'chall_half2.bin'
output_file = 'chall_restored.m4a'
key = 0x69

xor_file(input_file1, input_file2, output_file, key)
print("File '{}' created successfully.".format(output_file))
