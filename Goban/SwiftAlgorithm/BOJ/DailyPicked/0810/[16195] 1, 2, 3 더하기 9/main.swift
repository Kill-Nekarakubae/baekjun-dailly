//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/10.
//

import Foundation

// 1, 2, 3 합으로 나타내는 방법?

let t = Int(readLine()!)!
var dp = Array(repeating: Array(repeating: 0, count: 1001), count: 1001)

dp[1][1] = 1
dp[2][1] = 1
dp[2][2] = 1
dp[3][1] = 1
for i in 3...1000 {
    for j in 2...i {
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % 1000000009
    }
}
for _ in 0..<t {
    let input = readLine()!.split(separator: " ").map{ Int($0)! }
    let n = input[0]
    let m = input[1]
    var sum = 0
    for j in 1...m {
        sum = (sum + dp[n][j]) % 1000000009
    }
    print(sum)
}
