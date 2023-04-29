K = [
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
]

H = [
    0x6a09e667, 0xbb67ae85, 0x3c6ef372, 0xa54ff53a,
    0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19
]

def _right_rotate(n, d):
    return (n >> d) | (n << (32 - d))

def sha_algorithm(byte_array):
    byte_array = bytearray(byte_array)
    byte_array_len = len(byte_array) * 8
    byte_array.append(0x80)
    while len(byte_array) % 64 != 56:
        byte_array.append(0x00)
    byte_array += byte_array_len.to_bytes(8, byteorder="big")

    a, b, c, d, e, f, g, h = H

    for i in range(0, len(byte_array), 64):
        chunk = byte_array[i:i+64]

        w = [0] * 64
        for j in range(16):
            w[j] = int.from_bytes(chunk[j*4:j*4+4], byteorder="big")
        for j in range(16, 64):
            s0 = _right_rotate(w[j-15], 7) ^ _right_rotate(w[j-15], 18) ^ (w[j-15] >> 3)
            s1 = _right_rotate(w[j-2], 17) ^ _right_rotate(w[j-2], 19) ^ (w[j-2] >> 10)
            w[j] = (w[j-16] + s0 + w[j-7] + s1) % 2**32

        a_, b_, c_, d_, e_, f_, g_, h_ = a, b, c, d, e, f, g, h

        for j in range(64):
            S1 = _right_rotate(e_, 6) ^ _right_rotate(e_, 11) ^ _right_rotate(e_, 25)
            ch = (e_ & f_) ^ (~e_ & g_)
            temp1 = h_ + S1 + ch + K[j] + w[j]
            S0 = _right_rotate(a_, 2) ^ _right_rotate(a_, 13) ^ _right_rotate(a_, 22)
            maj = (a_ & b_) ^ (a_ & c_) ^ (b_ & c_)
            temp2 = S0 + maj

            h_ = g_
            g_ = f_
            f_ = e_
            e_ = (d_ + temp1) % 2**32
            d_ = c_
            c_ = b_
            b_ = a_
            a_ = (temp1 + temp2) % 2**32

        a = (a + a_) % 2**32
        b = (b + b_) % 2**32
        c = (c + c_) % 2**32
        d = (d + d_) % 2**32
        e = (e + e_) % 2**32
        f = (f + f_) % 2**32
        g = (g + g_) % 2**32
        h = (h + h_) % 2**32

    hashval = (a << 224) | (b << 192) | (c << 160) | (d << 128) | (e << 96) | (f << 64) | (g << 32) | h
    return "{:064x}".format(hashval)

with open("book_of_mark.txt", "rb") as f:
    byte_array = f.read()

hash = sha_algorithm(byte_array)
print(f"Hash: {hash}")
