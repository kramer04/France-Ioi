# https://www.france-ioi.org/algo/chapter.php?idChapter=674
# par binzry search
import sys
def binary_search(arr, test, x):
    low = 0
    high = len(arr) - 1
    mid = 0
    while low <= high:
        mid = (high + low) // 2
        # If x is greater, ignore left half
        if arr[mid] < x:
            low = mid + 1
        # If x is smaller, ignore right half
        elif arr[mid] > x:
            high = mid - 1
        # means x is present at mid
        else:
            return mid
    # If we reach here, then the element was not present
    return -1
def main():
    taille = int(input())
    tab = list(map(int, sys.stdin.readline().rstrip().split()))
    test = [True] * taille
    tab.sort()
    # print(tab)
    ok = 0
    for i in range(taille):
        if test[i]:
            x = -tab[i]
            test[i] = False
            result = binary_search(tab, test, x)
            if result != -1 and test[result]:
                ok += 1
                # print("Element is present at index", result)
                test[result] = False
            # else:
            #    print("Element is not present in array")
    print(ok)
main()
