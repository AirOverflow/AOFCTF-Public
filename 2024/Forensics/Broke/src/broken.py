def xor_file(input_file, output_file1, output_file2, key):
    with open(input_file, 'rb') as f:
        data = bytearray(f.read())

    half_len = len(data) // 2

    # XOR the first half of the file
    for i in range(half_len):
        data[i] ^= key

    with open(output_file1, 'wb') as f1:
        f1.write(data[:half_len])

    # XOR the second half of the file
    for i in range(half_len, len(data)):
        data[i] ^= key

    with open(output_file2, 'wb') as f2:
        f2.write(data[half_len:])

input_file = 'broken'
output_file1 = 'chall_half1.bin'
output_file2 = 'chall_half2.bin'
key = 0x69

xor_file(input_file, output_file1, output_file2, key)
print("Files '{}' and '{}' created successfully.".format(output_file1, output_file2))
