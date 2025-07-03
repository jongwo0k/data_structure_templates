// Map O(log n)
// Unordered Map O(1) ~ O(n)
// key-value base
#include <map>
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// map - Balanced Binary Search Tree (Red-Black Tree)
map<int, string> sampleMap;

// 삽입, 삭제
sampleMap[1] = "Aa";
sampleMap[3] = "Bb";
sampleMap[4] = "Cc";
sampleMap[2] = "Dd";

sampleMap.insert({5, "Aa"}); // 5: Aa 추가
sampleMap.insert({3, "Ee"}); // key 중복 불가(Bb 그대로)

sampleMap.erase(3);          // remove 3: "Bb"

sampleMap.empty();           // (X -> 0, O -> 1)
sampleMap.size();            // return 4

// 탐색
sampleMap.find(3);           // 존재하면 iterator 반환(value값 자체x 위치), 없으면 return sampleMap.end()
sampleMap.count(4);          // return 1 (존재 여부 X -> 0, O -> 1)

sampleMap[1];                // return Aa, key로 value("Aa")에 접근
sampleMap[6];                // 없는 key 접근 시 자동 생성, default value: ""(int면 0)
sampleMap.at(7);             // 없는 key일 경우 생성하지 않음, error

sampleMap.lower_bound(3);    // 범위 탐색 return key >= 3인 첫 위치
sampleMap.upper_bound(2);    // key > 2

// 출력할 경우 1: "Aa", 2: "Dd", 4: "Cc", 5: "Aa" 6: "" key 순서 정렬
for (auto& [k, v] : sampleMap) {
    cout << k << ": " << v << '\n';
}

sampleMap.clear();           // 전체 삭제

// 구조체를 사용
struct Person{
    string name;
    int age;
    // 정렬 기준 지정
    bool operator<(const Person& other) const {
        if(age != other.age) return age < other.age; // 나이 적은 순
        return name < other.name;                    // 나이가 같으면 이름 사전순
    }
};

map<Person, string> number;

// Cname -> Dname -> Aname -> Bname순 정렬
number[{"Aname", 29}] = "010-1234-5671";
number[{"Cname", 21}] = "010-1234-5672";
number[{"Bname", 29}] = "010-1234-5673";
number[{"Dname", 24}] = "010-1234-5674";


// unordered_map - Hash Table
unordered_map<int, string> sampleUM;

// 삽입, 삭제
sampleUM[1] = "Aa";
sampleUM[3] = "Bb";
sampleUM[4] = "Cc";
sampleUM[2] = "Dd";

sampleUM.insert({5, "Aa"}); // 5: Aa 추가
sampleUM.insert({3, "Ee"}); // key 중복 불가(Bb 그대로)

sampleUM.erase(3);          // remove 3: "Bb"

sampleUM.empty();           // (X -> 0, O -> 1)
sampleUM.size();            // return 4

// 탐색
sampleUM.find(3);           // 존재하면 iterator 반환(value값 자체x 위치), 없으면 return sampleUM.end()
sampleUM.count(4);          // return 1 (존재 여부 X -> 0, O -> 1)

sampleUM[1];                // return Aa, key로 value("Aa")에 접근
sampleUM[6];                // 없는 key 접근 시 자동 생성, default value: ""(int면 0)
sampleUM.at(7);             // 없는 key일 경우 생성하지 않음, error

// 출력할 경우 정렬 없이 임의적 (들어온 그대로 1: "Aa", 4: "Cc", 2: "Dd", 5: "Aa", 6: "" 순서도 아님)
for (auto& [k, v] : sampleUM) {
    cout << k << ": " << v << '\n';
}

sampleUM.clear();           // 전체 삭제

// -------------  빠른 검색  -------------
// 중복되지 않는 문자 찾기
vector<string> A = {"a", "c", "b", "d"};
vector<string> B = {"a", "b", "e"};

unordered_map<string, bool> alpha;

for (auto& b : B) {
    alpha[b] = true;
}
for (auto& a : A) {
    if (!alpha.count(a)) {
        cout << a << ' '; // 출력 : c d
    }
}

// value로 구조체 사용
struct Student{
    string name;
    int score;
};

unordered_map<int, Student> group;

// 정렬은 되지 않음
group[1] = {"Aname", 100};
group[2] = {"Cname", 80};
group[3] = {"Bname", 90};
group[1] = {"Dname", 100}; // 1: "dname", 100으로 덮어 씀

// 접근
group[1];
group[1].name;
group[1].score;
group[2];

// key로 구조체 사용
struct XY {
    int x;
    int y;

    // 동등 비교 연산자 (동일한 key인지 확인)
    bool operator==(const XY& other) const {
        return x == other.x && y == other.y;
    }
};

// hash 함수 정의 (객체를 hash값으로 변환, hash값을 저장할 bucket 결정)
namespace std {
    template <>
    struct hash<XY> {
        size_t operator()(const XY& p) const {
            return hash<int>()(p.x) ^ (hash<int>()(p.y) << 1); // XOR
        }
    };
}

unordered_map<XY, string> object;

object[{80, 9000}] = "bird";
object[{100, 200}] = "dog";
object[{200, -90}] = "fish";
object[{200, 100}] = "tree";

//--------------------------------------

// 빈도
vector<int> nums = {1, 3, 2, 1, 2, 1};
unordered_map<int, int> freq;

for (int n : nums) {
    freq[n]++;
}

int maxFreq = 0, maxNum = -1;
for (auto& [num, count] : freq) {
    if (count > maxFreq) {
        maxFreq = count;
        maxNum = num; // maxNum = 1, maxFreq = 3
    }
}