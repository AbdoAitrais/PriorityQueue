#include <iostream>
#include "PriorityQueue.cpp"

int main(){
    PriorityQueue pq;
    pq.push(5);
    pq.push(3);
    pq.push(7);
    pq.push(1);

    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
