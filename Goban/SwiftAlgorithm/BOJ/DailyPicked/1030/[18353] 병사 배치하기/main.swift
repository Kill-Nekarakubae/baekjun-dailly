//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/10/30.
//

import Foundation

// 가장 긴 감소하는 부분수열

let N = Int(readLine()!)!
let list = readLine()!.split(separator: " ").map{Int(String($0))!}

var dp = Array(repeating:1,count:N)

for i in 1..<N {
    for j in 0..<i {
        if list[i] < list[j] {
            dp[i] = max(dp[i], dp[j]+1)
        }
    }
}
print(N-dp.max()!)
