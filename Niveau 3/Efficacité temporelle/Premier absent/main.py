import sys
def main():
    N, P = map(int, sys.stdin.readline().split())
    absent = [False] * (250 * 1000 + 1)
    j = 0
    for i in range(P):
        present = int(sys.stdin.readline())
        present -= 1
        if present < P:
            absent[present] = True
        while j < N and absent[j]:
            j += 1
        if j == N:
            sys.stdout.write(str(-1) + "\n")
        else:
            sys.stdout.write(str(j+1) + "\n")
main()
