import numpy as np

result_matrix = np.array([
    [553, 242, 482, 157, 508, 566],
    [2832, 529, 1736, 1921, 2469, 1651],
    [2833, 1273, 2233, 2177, 3031, 2995],
    [2479, 647, 1432, 1559, 2626, 1723],
    [2131, 627, 1697, 1294, 2043, 1898],
    [4082, 919, 2766, 2020, 3868, 3039]
])

given_matrix = np.array([
    [2, 1, 3, 9, 8, 9],
    [9, 1, 3, 2, 3, 2],
    [7, 0, 8, 0, 8, 9],
    [8, 0, 4, 8, 9, 1],
    [7, 4, 4, 1, 8, 8],
    [7, 6, 9, 5, 4, 7]
])

inverse_given_matrix = np.linalg.inv(given_matrix)
other_matrix = np.round(np.dot(result_matrix, inverse_given_matrix)).astype(int)
print("Orig_Matrix")
print(other_matrix)


#xor the orig matrix with "AIR" to get the flag

orig = [[0, 6,20, 2,29,20],
 [ 58,125,32,114,22,43],
 [113,60,13,51,122,102],
 [ 37,48,13,118,121,13],
 [ 51,60,60,47,39,60],
 [ 47,118,109,126,118,47]]

flag = ""
key = "AIR"
counter = 0
for i in range(6):
    for j in range(6):
        flag += chr(orig[i][j] ^ ord(key[counter%len(key)]))
        counter +=1
print(flag)
        


