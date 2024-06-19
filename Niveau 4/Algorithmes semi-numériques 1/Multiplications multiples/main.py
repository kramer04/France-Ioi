import sys
def main():
    N = int(sys.stdin.readline())
    m = 1
    for i in range(N):
        m = m * int(sys.stdin.readline()) % 10000
    # m = m % 10000
    # print("{:04d}".format(m))
    sys.stdout.write("{:04d}".format(m))
main()
