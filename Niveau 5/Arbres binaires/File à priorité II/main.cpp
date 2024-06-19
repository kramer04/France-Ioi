// priorite file 2
// code 2
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
int main() {
    int R;
    //std::cin >> R;
    scanf("%d", &R);
    // Utilisation d'un priority_queue avec un comparateur pour faire un min-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    for (int i = 0; i < R; ++i) {
        char query[2];
        //std::cin >> query;
        scanf("%s", query);
        if (query[0] == 'I') {
            int value;
            //std::cin >> value;
            scanf("%d", &value);
            minHeap.push(value);
        } else if (query[0] == 'E') {
            if (minHeap.empty()) {
                {
                  //std::cout << "-" << std::endl;
                  printf("-\n");
                }
            } else {
                //std::cout << minHeap.top() << std::endl;
                printf("%d\n", minHeap.top());
                minHeap.pop();
            }
        }
    }
    return 0;
}
