string1 = input()
string2 = input()

len_string1 = len(string1)
len_string2 = len(string2)

matrix = [[0] * 5001 for i in range(5001)]
for i in range(0, len_string1):
    for j in range(0, len_string2):
        if string1[i] == string2[j]:
            matrix[i + 1][j + 1] = matrix[i][j] + 1
        else:
            matrix[i + 1][j + 1] = max(matrix[i + 1][j], matrix[i][j + 1])
print(matrix[len_string1][len_string2])
