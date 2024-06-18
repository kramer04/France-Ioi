def base10(b2, nbd, i):
    if i == len(b2):
        return nbd
    nbd = base10(b2, nbd * 2 + int(b2[i]), i + 1)
    return nbd
def main():
    n = input()
    result = base10(n, 0, 0)
    print(result, end="")
    print()
main()
