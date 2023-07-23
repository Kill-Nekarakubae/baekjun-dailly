//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/20.
//

import Foundation

// 곡을 연주하기 전 볼륨조절 가능: v[i]
// 그럼 for 문으로 볼륨을 지나가면서 확인?

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let N = input[0]
let S = input[1]
let M = input[2]
let volumes = [0] + readLine()!.split(separator: " ").map{ Int($0)! }

var dp: [[Bool]] = Array(repeating: Array(repeating: false, count: M+1), count: N+1)
dp[0][S] = true

for i in 1...N {
    var canPlay = false
    for j in 0...M {
        if dp[i-1][j] {
            // 볼륨 +
            let plus = j + volumes[i]
            if j + volumes[i] <= M {
                dp[i][plus] = true
                canPlay = true
            }
            let minus = j - volumes[i]
            if minus >= 0 {
                dp[i][minus] = true
                canPlay = true
            }
        }
    }
    if !canPlay {
        break
    }
}

var answer = -1
for i in (0...M).reversed() {
    if dp[N][i] {
        answer = i
        break
    }
}
print(answer == -1 ? -1 : answer)
