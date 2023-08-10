//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/09.
//

import Foundation

// 가장 많은 돈을 버는 경우: 남은 강의중 가장 돈을 많이 주는 강의에 수업할때.
// 문제가 되는 경우: 남은 일수가 겹치고 해당 두 강의가 앞선 강의들보다 많은 돈을 줄때.
// 일단 생각나는 방법 -> 우선순위를 미리 다 정해보자. 만약 날짜가 겹치는 강연이라면, 해당 날짜의 -1 강연과 비교하여 우선순위를 정한다.

// day = 10000일 동안 하루에 하는 강연의 돈
// dayIdx = 현재까지 저장된 하루의 index
// 1. 돈, 날짜 순으로 정렬,
// 2. 우선순위를 부여해보자. for 문으로 앞에서부터 번호를 매긴다. 1 2 3.. 그리고 겹치는 번호가 나오면
// -> 1. dayIdx ~ 해당 강연의 day 까지 빈곳에다 저장한다.
// -> 2. 자리가 없다면 dayIdx -> 1 까지 탐색하며

let n = Int(readLine()!)!
var lecture: [(pay: Int, day: Int)] = []
for _ in 0..<n {
    let line = readLine()!.split(separator: " ").map{ Int($0)! }
    lecture.append((pay: line[0], day: line[1]))
}

lecture.sort { lhs, rhs in
    return lhs.pay > rhs.pay
}

var schedules = Array(repeating: 0, count: 100001)
for i in 0..<n {
    for j in stride(from: lecture[i].day, through: 1, by: -1) {
        if schedules[j] == 0 {
            schedules[j] = lecture[i].pay
            break
        }
    }
}
print(schedules.reduce(0, +))
