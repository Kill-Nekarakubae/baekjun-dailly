//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/25.
//

import Foundation
let nk = readLine()!.split(separator: " ").map{Int(String($0))!}
let n = nk[0]
let k = nk[1]
var dp = Array(repeating: 10001, count: 10001)
var coin = [Int]()
dp[0] = 0
for i in 0..<n{
    coin.append(Int(String(readLine()!))!)
    for j in coin[i]...k {
        dp[j] = min(dp[j], dp[j - coin[i]] + 1)
    }
    dp.forEach { int in
        print(int)
    }
    
    print("----")
}
if dp[k] == 10001{
    print(-1)
}else{
    print(dp[k])
}
// 동전을
