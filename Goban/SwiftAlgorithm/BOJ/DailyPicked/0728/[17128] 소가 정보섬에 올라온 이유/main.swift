//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/28.
//

import Foundation

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let N = input[0]
let Q = input[1]
var cows: [Int] = [0] + readLine()!.split(separator: " ").map{ Int($0)! }
let joke: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
var cowsSum: [Int] = []
var affectIdxs: [[Int]] = Array(repeating: [], count: N+1)
var originalSum = 0
for i in 1...N {
    var cowSum = 1
    for j in i...i+3 {
        cowSum *= cows[j > N ? j-N : j]
        affectIdxs[i].append(i)
    }
    cowsSum.append(cowSum)
    originalSum += cowSum
}

for jokeIdx in joke {
    var targetSum = 0
    var targetJoked = 0
    for affectIdx in affectIdxs[jokeIdx] {
        targetSum += cowsSum[affectIdx]
        targetJoked += cowsSum[affectIdx]*(-1)
        cowsSum[affectIdx] = targetJoked
    }
    originalSum -= targetSum
    originalSum += targetJoked
    
    print(originalSum)
}

// 4개씩 끊어서 cow들이 존재. 2차원 배열로 cow가 들어간 idx 합을 구하면 어떨까


print(cows)
