// Set O(log n)
// Unordered Set O(1) ~ O(n)
#include <set>
#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// set - Balanced Binary Search Tree (Red-Black Tree)
set<int> sampleSet;

// 삽입, 삭제
sampleSet.insert(1); // 1 insert()로만 삽입
sampleSet.insert(3); // 1 3
sampleSet.insert(2); // 1 2 3 자동 정렬
sampleSet.insert(1); // 1 2 3 중복 불가
sampleSet.insert(4); // 1 2 3 4

sampleSet.erase(2);  // 1 3 4

sampleSet.empty();           // (X -> 0, O -> 1)
sampleSet.size();            // return 3

// 탐색
sampleSet.find(3);           // 존재하면 iterator 반환(값 자체x 위치), 없으면 return sampleSet.end()
sampleSet.count(4);          // return 1 (존재 여부 X -> 0, O -> 1)

sampleSet.lower_bound(3);    // 범위 탐색 >= 3인 첫 위치
sampleSet.upper_bound(2);    // > 2

// 출력할 경우 1 3 4 순서 정렬
for (auto& s : sampleSet) {
    cout << s << '\n';
}

sampleSet.clear();           // 전체 삭제

// 중복 제거
vector<int> arr = {1, 2, 3, 1, 3, 4, 1, 2, 3, 4, 5};

set<int> unique(arr.begin(), arr.end()); // 중복 제거 - {1, 2, 3, 4, 5}

// 구조체 사용
struct Person {
    string name;
    int age;
    bool operator<(const Person& other) const {
        // 나이가 적은 순, 같으면 이름 사전순
        if (age != other.age) return age < other.age;
        return name < other.name;
    }
};

set<Person> people;

// Aname(19) -> Aname(29) -> Bname -> Cname순 정렬
people.insert({"Aname", 29});
people.insert({"Aname", 29}); // 중복 불가능
people.insert({"Aname", 19}); // age가 달라서 가능
people.insert({"Cname", 39});
people.insert({"Bname", 39});


// unordered_set - Hash Table
unordered_set<int> sampleUS;

// 삽입, 삭제
sampleUS.insert(1);
sampleUS.insert(3);
sampleUS.insert(2);
sampleUS.insert(1); // 중복 불가
sampleUS.insert(4); // 정렬 안함

sampleUS.erase(2);  // remove 2

sampleUS.empty();   // (X -> 0, O -> 1)
sampleUS.size();    // return 3

// 탐색
sampleUS.find(3);   // 존재 시 iterator 반환, 없으면 sampleUS.end()
sampleUS.count(4);  // return 1 (존재 여부 X -> 0, O -> 1)

// 출력할 경우 정렬 없이 임의적 (들어온 순서도 아님)
for (auto& s : sampleUS) {
    cout << s << '\n';
}

// 지나온 경로 확인
unordered_set<int> visited;
int node = 5;

if (!visited.count(node)) {
    visited.insert(node);
}

// 구조체 사용
struct Person {
    string name;
    int age;

    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

// 해시 함수 정의
namespace std {
    template <>
    struct hash<Person> {
        size_t operator()(const Person& p) const {
            return hash<string>()(p.name) ^ (hash<int>()(p.age) << 1);
        }
    };
}

unordered_set<Person> people;

// 정렬, 중복 X
people.insert({"Aname", 29});
people.insert({"Aname", 29}); // 무시됨
people.insert({"Aname", 19});
people.insert({"Bname", 39});
people.insert({"Cname", 39});