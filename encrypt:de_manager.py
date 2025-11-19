import math

def columnar_encrypt(message, key):
    order = [i for _, i in sorted((ch, i) for i, ch in enumerate(key))]

    cols = len(key)
    rows = math.ceil(len(message) / cols)

    message = message.ljust(rows * cols, 'X')

    grid = [''] * rows

    index = 0
    for r in range(rows):
        for c in range(cols):
            grid[r] += message[index]
            index += 1

    ciphertext = ''
    for c in order:
        for r in range(rows):
            ciphertext += grid[r][c]
    return ciphertext


def columnar_decrypt(cipher, key):
    order = [i for _, i in sorted((ch, i) for i, ch in enumerate(key))]
    cols = len(key)
    rows = len(cipher) // cols

    inv = [0]*cols
    for i, col in enumerate(order):
        inv[col] = i

    columns = [''] * cols

    index = 0
    for i in range(cols):
        columns[i] = cipher[index:index+rows]
        index += rows

    plaintext_rows = [''] * rows
    for r in range(rows):
        for c in range(cols):
            plaintext_rows[r] += columns[inv[c]][r]

    return ''.join(plaintext_rows)


def encrypt(key_1, key_2, message):
    cipher1 = columnar_encrypt(message, key_1)
    cipher2 = columnar_encrypt(cipher1, key_2)
    return cipher2


def decrypt(key_1, key_2, message):
    plain1 = columnar_decrypt(message, key_2)
    plain2 = columnar_decrypt(plain1, key_1)
    return plain2
