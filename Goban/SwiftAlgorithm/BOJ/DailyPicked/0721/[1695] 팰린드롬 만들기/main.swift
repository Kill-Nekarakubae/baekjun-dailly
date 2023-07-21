//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/21.
//

import Foundation

let N = Int(readLine()!)!
let numArray = readLine()!.split(separator: " ").map{ Int($0)! }
let reversedNumArray = Array(numArray.reversed())
var dp = Array(repeating: Array(repeating: 0, count: N+1), count: N+1)
for i in 1...N {
    for j in 1...N {
        if numArray[i-1] == reversedNumArray[j-1] {
            dp[i][j] = dp[i-1][j-1] + 1
        } else {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j])
        }
    }
}
print(N-dp[N][N])
