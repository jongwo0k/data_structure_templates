// FIFO - First In First Out
#include <queue>

// pair<int, int>, string, ...
queue<int> sample;

sample.push(1); // 1
sample.push(3); // 1 3
sample.push(2); // 1 3 2

// if (!sample.empty())
sample.front(); // return 1 (맨 앞)
sample.back();  // return 2 (맨 뒤)

sample.size();  // return 3

sample.pop();   // remove 1 (3 2)

sample.empty(); // return 0 (X -> 0, O -> 1)