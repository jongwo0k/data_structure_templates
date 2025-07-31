// FIFO - First In First Out
#include <queue>

using namespace std;

// pair<int, int>, string, ...
queue<int> sample;

sample.push(1); // 1
sample.push(3); // 1 3
sample.push(2); // 1 3 2

// if (!sample.empty())
sample.front(); // return 1 (맨 앞)
sample.back();  // return 2 (맨 뒤)

sample.size();  // return 3

sample.pop();   // remove 1 (3 2 front부터 없어짐)

sample.empty(); // return 0 (X -> 0, O -> 1)

// n,k 요세푸스
queue<int> josephus;

// 큐에 1~n 채우기
for (int i = 1; i <= n; i++) {
	josephus.push(i);
}

// k번째 제거
while (josephus.size() > 1) {
	for (int i = 0; i < k - 1; i++) {
		josephus.push(josephus.front()); // front -> back
		josephus.pop();
	}
	josephus.pop(); // k번째 제거
}
