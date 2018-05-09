import string

coder = dict(zip(string.ascii_lowercase,reversed(string.ascii_lowercase)))
alphabet = set(string.ascii_lowercase)

def answer(s):
    decoded = ""
    for c in s:
        if c in alphabet:
            decoded += coder[c]
        else:
            decoded += c
    return decoded

print(answer("Yvzs! I xzm'g yvorvev Lzmxv olhg srh qly zg gsv xlolmb!!"))
