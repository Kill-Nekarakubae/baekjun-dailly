# 😆 코테뽀시기

## 2023/07/21

|                       번호                       |                        문제 이름                        | 체크 |
|:----------------------------------------------:|:---------------------------------------------------:|:--:|
|  [9536](https://www.acmicpc.net/problem/9536)  | [여우는 어떻게 울지?](https://www.acmicpc.net/problem/9536) | ✅  |
|  [3187](https://www.acmicpc.net/problem/3187)  |    [양치기 꿍](https://www.acmicpc.net/problem/3187)    | ✅  |
|  [1695](https://www.acmicpc.net/problem/1695)  |  [팰린드롬 만들기](https://www.acmicpc.net/problem/1695)   | 🐢 |
| [15684](https://www.acmicpc.net/problem/15684) |   [사다리 조작](https://www.acmicpc.net/problem/15684)   | 🐢 |
| [17831](https://www.acmicpc.net/problem/17831) |  [대기업 승범이네](https://www.acmicpc.net/problem/17831)  | 🐢 |

### 오늘의 교훈
- Split을 잘 숙지하자
```c++
#include <iostream>
#include <sstream>
#include <vector>
vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }

    return answer;
}
```
- erase(remove) 를 숙지하자
```c++

#include <algorithm>
v.erase(remove(v.begin(), v.end(), findValue), v.end());
```


## 2023/07/12

|                       번호                       |                        문제 이름                        | 체크 |
|:----------------------------------------------:|:---------------------------------------------------:|:--:|
| [13410](https://www.acmicpc.net/problem/13410) |  [거꾸로 구구단](https://www.acmicpc.net/problem/13410)   | ✅  | 
| [10026](https://www.acmicpc.net/problem/10026) |    [적록색약](https://www.acmicpc.net/problem/10026)    | ✅  |
| [20922](https://www.acmicpc.net/problem/20922) |  [겹치는 건 싫어](https://www.acmicpc.net/problem/20922)  | 🐢 |
|  [9944](https://www.acmicpc.net/problem/9944)  | [NxM 보드 완주하기](https://www.acmicpc.net/problem/9944) | 🐢 |
|  [5446](https://www.acmicpc.net/problem/5446)  |    [용량 부족](https://www.acmicpc.net/problem/5446)    | 🐢 |

### 오늘의 교훈

- BFS - visited는 que에 넣기 전에 해야 중복을 막을 수 있다!!!