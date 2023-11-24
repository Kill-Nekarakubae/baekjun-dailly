//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/11/17.
//

import Foundation

// 부분 수열으로 나올 수 없는 가장 작은 자연수.
// 1. 부분 수열로 나올 수 있는 값을 전부 구한다.
// 2. 1 부터 전체 합까지 나올 수 있는 수 인지 계속 점검

let N = readLine()!
let S = readLine()!.split(separator: " ").map{ Int($0)! }
let maxSum = S.reduce(0, +)
var paritialSums = Set<Int>()
var paritialSumArray: [([Int], Int)] = S.enumerated().map { (idx, element) in
    return ([element], idx)
}

while !paritialSumArray.isEmpty {
    let now = paritialSumArray.removeLast()
    let element = now.0
    let idx = now.1
    paritialSums.insert(element.reduce(0, +))
    guard idx+1 < S.count else { continue }
    for i in idx+1..<S.count {
        paritialSumArray.append((element + [S[i]], i))
    }
}

for i in 1...maxSum+1 {
    if !paritialSums.contains(i) {
        print(i)
        break
    }
}
