//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/24.
//

import Foundation

let n = Int(readLine()!)!
var dp: [UInt64] = Array(repeating: 0, count: 1000001)
dp[0] = 0
dp[1] = 1
if n >= 2 {
    for i in 2...n {
        dp[i] = (dp[i-1] + dp[i-2])%1000000007
    }
}
print(dp[n])
