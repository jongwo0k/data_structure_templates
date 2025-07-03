// LIFO - Last In First Out
#include <stack>

using namespace std;

// pair<int, int>, string, ...
stack<int> sample;

sample.push(1); // 1
sample.push(3); // 1 3
sample.push(2); // 1 3 2

// if (!sample.empty())
sample.top();   // return 2

sample.size();  // return 3

sample.pop();   // remove 2 (1 3)

sample.empty(); // return 0 (X -> 0, O -> 1)