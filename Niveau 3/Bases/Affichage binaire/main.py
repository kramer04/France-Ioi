def base2(b10):
    if b10 > 1:
        base2(b10 // 2)
    print(b10 % 2, end="")
def main():
    n = int(input())
    base2(n)
    print()
main()
