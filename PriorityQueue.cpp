//
// Created by abdo on 1/19/2023.
//
#include <iostream>
#include <vector>
#include <functional>

class PriorityQueue {
    std::vector<int> v;
    std::function<bool(int, int)> cmp;

public:
    PriorityQueue() {
        cmp = [](int a, int b) { return a > b; };
    }

    void push(int x) {
        v.push_back(x);
        int i = v.size() - 1;
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (cmp(v[i], v[parent])) {
                std::swap(v[i], v[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    int top() {
        if (v.empty()) {
            throw std::runtime_error("PriorityQueue is empty");
        }
        return v[0];
    }

    void pop() {
        if (v.empty()) {
            throw std::runtime_error("PriorityQueue is empty");
        }
        v[0] = v.back();
        v.pop_back();
        int i = 0;
        while (i < v.size()) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int minIndex = i;
            if (left < v.size() && cmp(v[minIndex], v[left])) {
                minIndex = left;
            }
            if (right < v.size() && cmp(v[minIndex], v[right])) {
                minIndex = right;
            }
            if (minIndex != i) {
                std::swap(v[i], v[minIndex]);
                i = minIndex;
            } else {
                break;
            }
        }
    }

    int size() {
        return v.size();
    }

    bool empty() {
        return v.empty();
    }
};
