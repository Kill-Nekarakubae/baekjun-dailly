//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/03.
//
let n = Int(readLine()!)!
let m = Int(readLine()!)!

var dp = [Int](repeating: 0, count: 41)
dp[0] = 1
dp[1] = 1
dp[2] = 2
for i in 3...40 {
    dp[i] = dp[i-1] + dp[i-2]
}

var vip: [Int] = []
for _ in 0..<m {
    vip.append(Int(readLine()!)!)
    
}

var result = 1
var pre = 0
for target in vip {
    result *= dp[target - pre - 1]
    pre = target
}
result *= dp[n - pre]

print(result)
