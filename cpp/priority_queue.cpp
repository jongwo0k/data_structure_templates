// Priority Queue - 우선순위 큐 Heap base
#include <queue>
#include <vector>
#include <string>
#include <functional>

// 사용자 지정 우선순위 구조체
struct PrioritySample{
    string name;
    int priority;
    int number;
};

struct Compare {
    bool operator()(const PrioritySample& a, const PrioritySample& b) const {
        // 작은 priority 우선
        if (a.priority != b.priority) {
            return a.priority > b.priority;
        }
        // priority가 같으면 작은 number 우선
        return a.number > b.number;
    }
};

// Max Heap (기본설정)
priority_queue<int> maxHeap;
maxHeap.push(1); // 1
maxHeap.push(3); // 3 1
maxHeap.push(2); // 3 2 1
maxHeap.push(4); // 4 3 2 1 (저장 순서x 우선순위에 의해 출력되는 순서 / 저장은 binary heap 트리 구조)

// if (!maxHeap.empty())
maxHeap.top();   // return 4 (최대값)
maxHeap.size();  // return 4
maxHeap.pop();   // remove 4 (3 2 1 순서)
maxHeap.empty(); // return 0 (X -> 0, O -> 1)


// Min Heap
priority_queue<int, vector<int>, greater<int>> minHeap;
minHeap.push(1);
minHeap.push(3);
minHeap.push(2);
minHeap.push(4);

// if (!minHeap.empty())
minHeap.top();   // return 1 (최소값)
minHeap.size();  // return 4
minHeap.pop();   // remove 1 (2 3 4)
minHeap.empty(); // return 0


// sample priority
priority_queue<PrioritySample, vector<PrioritySample>, Compare> cmpHeap;

cmpHeap.push({"Park", 1, 2}); // priority=1, number=2 (2순위)
cmpHeap.push({"Jong", 1, 1}); // priority=1, number=1 (1순위)
cmpHeap.push({"Wook", 2, 3}); // priority=2, number=3 (3순위)
cmpHeap.push({"Test", 3, 1}); // priority=3, number=1 (4순위)

// if (!cmpHeap.empty())
cmpHeap.top().name; // return "Jong"
cmpHeap.pop(); // remove top (이후 {"Park", 1, 2} -> {"Wook", 2, 3} -> {"Test", 3, 1} 순서)