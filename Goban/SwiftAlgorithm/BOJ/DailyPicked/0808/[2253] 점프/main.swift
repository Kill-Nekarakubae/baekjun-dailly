//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/08.
//

import Foundation

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let (N, M) = (input[0], input[1])
var dp = Array(repeating: Array(repeating: Int.max, count: Int(pow(Double(2*N), 0.5))+2), count: N+1)
var smallStones = Set<Int>()
for _ in 0..<M {
    let smallStone = Int(readLine()!)!
    smallStones.insert(smallStone)
}
dp[1][0] = 0
for i in 2...N {
    if smallStones.contains(i) {
        continue
    }

    let xRange = Int(pow(Double(2*i), 0.5))
    for x in 1...xRange {
        if min(dp[i-x][x-1], dp[i-x][x], dp[i-x][x+1]) == Int.max {
            continue
        }
        dp[i][x] = min(dp[i-x][x-1], dp[i-x][x], dp[i-x][x+1]) + 1
    }
}
var answer = dp[N].min()!
if answer == Int.max {
    print("-1")
} else {
    print(answer)
}
    
