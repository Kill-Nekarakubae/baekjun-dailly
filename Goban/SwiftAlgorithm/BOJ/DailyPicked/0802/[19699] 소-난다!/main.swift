//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/02.
//

import Foundation

// 소의 조합 -> 소수 판별

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let N = input[0]
let M = input[1]
let cows = readLine()!.split(separator: " ").map{ Int($0)! }
let maxCowsSum = cows.reduce(0, +)

var visited = Array(repeating: false, count: maxCowsSum+1)
visited[0] = true
visited[1] = true
// 1000까지 미리 소수 판별
for i in 2...maxCowsSum {
    if visited[i] == true {
        continue
    }

    for j in stride(from: i+i, through: maxCowsSum, by: i) {
        visited[j] = true
    }
}

func isPrime(num: Int) -> Bool {
    if visited[num] {
        return false
    }
    return true
}
var answer = Set<Int>()
var cowTable: [Int] = []
func findCow(idx: Int) {
    if cowTable.count == M {
        // 검증
        let cowSum = cowTable.reduce(0, +)
        if isPrime(num: cowSum) {
            answer.insert(cowSum)
        }
        return
    }
    if idx >= N {
        return
    }
    cowTable.append(cows[idx])
    findCow(idx: idx + 1)
    if !cowTable.isEmpty {
        cowTable.removeLast()
    }
    findCow(idx: idx + 1)
}
findCow(idx: 0)

var answerArray = Array(answer).sorted()
if !answerArray.isEmpty {
    print(answerArray.map{ String($0) }.joined(separator: " "))
} else {
    print("-1")
}
