//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/16.
//

import Foundation

let T = Int(readLine()!)!
var dp = Array(repeating: Array(repeating: 0, count: 30), count: 30)
for i in 1..<30 {
    for j in 0...i {
        if j == 0 || i == j {
            dp[i][j] = 1
            continue
        }
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
    }
    dp.forEach { line in
        print(line)
    }
}

for _ in 0..<T {
    let arr = readLine()!.split(separator: " ").map{ Int(String($0))! }
    print(dp[arr[1]][arr[0]])
}
