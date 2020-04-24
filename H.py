def fib_mod(n, m):
    seq_pisano = find_pisano(m)
    return seq_pisano[n % len(seq_pisano)]


def find_pisano(m):
    pisano = [0, 1]
    n0 = 0
    n1 = 1

    for _ in range(m * 6):
        n0, n1 = n1, (n0 + n1) % m
        pisano.append(n1)

        if pisano[-1] == 1 and pisano[-2] == 0:
            break

    return pisano[:-2]


def gcd(a, b):
    while a != 0:
        a, b = b % a, a
    return b

def pow(x, n, I, mult):
    """
    Р’РѕР·РІСЂР°С‰Р°РµС‚ x РІ СЃС‚РµРїРµРЅРё n. РџСЂРµРґРїРѕР»Р°РіР°РµС‚, С‡С‚Рѕ I вЂ“ СЌС‚Рѕ РµРґРёРЅРёС‡РЅР°СЏ РјР°С‚СЂРёС†Р°, РєРѕС‚РѕСЂР°СЏ
    РїРµСЂРµРјРЅРѕР¶Р°РµС‚СЃСЏ СЃ mult, Р° n вЂ“ РїРѕР»РѕР¶РёС‚РµР»СЊРЅРѕРµ С†РµР»РѕРµ
    """
    if n == 0:
        return I
    elif n == 1:
        return x
    else:
        y = pow(x, n // 2, I, mult)
        y = mult(y, y)
        if n % 2:
            y = mult(x, y)
        return y


def identity_matrix(n):
    """Р’РѕР·РІСЂР°С‰Р°РµС‚ РµРґРёРЅРёС‡РЅСѓСЋ РјР°С‚СЂРёС†Сѓ n РЅР° n"""
    r = list(range(n))
    return [[1 if i == j else 0 for i in r] for j in r]


def matrix_multiply(A, B):
    BT = list(zip(*B))
    return [[sum(a * b
                 for a, b in zip(row_a, col_b))
            for col_b in BT]
            for row_a in A]


def fib(n):
    F = pow([[1, 1], [1, 0]], n, identity_matrix(2), matrix_multiply)
    return F[0][1]


handle = open("input.txt", "r")
outfile = open("output.txt", "w")
data = handle.read()
handle.close()

n, m = (int(x) for x in data.split())
f = gcd(n, m)
r = fib(f)


outfile.write(str(r))
outfile.close()

print(r)
