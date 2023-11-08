//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/11/02.
//

import Foundation

// N 명의 스태프가 M 개의 풍선을 만들어야함.
// 각각의 스태프는 풍선 만드는 시간이 다름.

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let (N, M) = (input[0], input[1] )
let timeTable = readLine()!.split(separator: " ").map { Int($0)! }

func checkIsPossible(time: Int) -> Bool {
    var cnt = 0
    for i in timeTable {
        cnt += time / i
    }
    if cnt >= M {
        return true
    }
    return false
}

var start = 1
var end = timeTable.min()!*M
var answer = end
while start <= end {
    let mid = (start + end) / 2
    if checkIsPossible(time: mid) {
        answer = min(answer, mid)
        end = mid - 1
    } else {
        start = mid + 1
    }
}
print(answer)
