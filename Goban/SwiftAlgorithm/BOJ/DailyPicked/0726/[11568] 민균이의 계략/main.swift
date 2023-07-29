//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/26.
//

import Foundation

// 순증가 수열
let N = Int(readLine()!)!
var cards: [Int] = readLine()!.split(separator: " ").map{ Int($0)! }
var dp = Array(repeating: 1, count: N)

for i in 0..<N {
    for j in 0..<i {
        if cards[j] < cards[i] {
            if dp[i] < dp[j] + 1 {
                dp[i] = dp[j] + 1
            }
        }
    }
}
print(dp.max()!)
