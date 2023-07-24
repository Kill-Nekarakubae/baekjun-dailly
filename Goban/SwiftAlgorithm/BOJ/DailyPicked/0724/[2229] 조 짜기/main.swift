//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/24.
//

import Foundation

// dp?

let N = Int(readLine()!)!
let students:[Int] = [0] + readLine()!.split(separator: " ").map{ Int($0)! }
var dp: [Int] = Array(repeating:0, count: N+1 )
for i in 1...N {
    var maxNum = students[i]
    var minNum = students[i]
    for j in stride(from: i, through: 1, by: -1) {
        maxNum = max(maxNum, students[j])
        minNum = min(minNum, students[j])
        dp[i] = max(dp[i], maxNum - minNum + dp[j-1])
    }
}
    
print(dp[N])
