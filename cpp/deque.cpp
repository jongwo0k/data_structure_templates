// Deque - Double Ended Queue
#include <deque>

// pair<int, int>, string, ...
deque<int> sample;

sample.push_back(1);  // 1
sample.push_back(3);  // 1 3
sample.push_back(2);  // 1 3 2
sample.push_front(4); // 4 1 3 2
sample.push_front(5); // 5 4 1 3 2

// if (!sample.empty())
sample.front();       // return 5 (맨 앞)
sample.back();        // return 2 (맨 뒤)

sample.size();        // return 5

sample.pop_back();    // remove 2 (5 4 1 3)
sample.pop_front();   // remove 5 (4 1 3)

sample.empty();       // return 0 (X -> 0, O -> 1)