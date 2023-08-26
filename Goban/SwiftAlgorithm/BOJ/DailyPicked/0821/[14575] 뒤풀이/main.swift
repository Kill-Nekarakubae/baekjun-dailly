//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/21.
//

import Foundation

// 이분탐색으로, 서칭.

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let (N, T) = (input[0], input[1])


var peopleBear: [(L: Int, R: Int)] = []
for _ in 0..<N {
    let line = readLine()!.split(separator: " ").map{ Int($0)! }
    peopleBear.append((L: line[0], R: line[1]))
}

var start = 1
var end = T
var answer = Int.max

while start <= end {
    let mid = (start + end) / 2
    var bearSum = 0
    var bearRange = 0
    var isFaild = false
    for people in peopleBear {
        let L = people.L
        let R = people.R
        var affordableRange: Int
        if L > mid {
            isFaild = true
            break
        }
        if R < mid {
            affordableRange = R - L
        } else {
            affordableRange = mid - L
        }
        if affordableRange < 0 {
            affordableRange = 0
        }
        bearSum += L
        bearRange += affordableRange
    }
    if isFaild {
        start = mid + 1
        continue
    }
    if bearSum + bearRange >= T {
        if bearSum <= T {
            answer = min(answer, mid)
        }
        end = mid - 1
    } else {
        start = mid + 1
    }
}

if answer == Int.max {
    print("-1")
} else {
    print(answer)
}
