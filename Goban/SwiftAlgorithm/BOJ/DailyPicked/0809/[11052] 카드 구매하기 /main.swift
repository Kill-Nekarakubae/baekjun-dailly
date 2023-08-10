//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/09.
//

import Foundation

// 카드를 구매
// 생각나는 풀이: dp.
// -> dp[i] = i개 를 살떄 필요한 최대 돈.
// dp[i] = 개수, 돈.
// k 는 개수, m = 돈
// for 문으로 dp[i+k] = max(dp[i] + m)

let N = Int(readLine()!)!
var cards = [0] + readLine()!.split(separator: " ").map{ Int($0)! }
var dp: [Int] = Array(repeating: 0, count: N+1)
for i in 0...N {
    for j in 1...N {
        if i+j > N {
            break
        }
        dp[i+j] = max(dp[i+j], dp[i] + cards[j])
    }
}
print(dp[N])
