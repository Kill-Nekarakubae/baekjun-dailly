//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/17.
//

import Foundation

// B -> O -> J 인데,, 점화식을 어떻게 세울까.
// dp[0][2] = J -> B 로 뛰었을때 드는 최소비용
// dp[2][3] = O -> J 로 뛰었을때 드는 최소비용
// dp[i][j] = dp[i-1][0~j]

func convertToInt(str: String) -> Int {
    if str == "B" {
        return 0
    }
    if str == "O" {
        return 1
    }
    if str == "J" {
        return 2
    }
    return -1
}
func convertedPreviousInt(num: Int) -> Int {
    if num == 0 {
        return 2
    } else {
        return num - 1
    }
}

let N = Int(readLine()!)!
let board =  readLine()!.map{ convertToInt(str: String($0))}
var dp = Array(repeating: Array(repeating: Int.max, count: N), count: 3)
dp[0][0] = 0
for (idx, num) in board.enumerated() {
    let previousNum = convertedPreviousInt(num: num)
    for i in 0..<idx {
        if dp[previousNum][i] == Int.max {
            continue
        }
        dp[num][idx] = min(dp[num][idx], dp[previousNum][i] + (idx-i)*(idx-i))
    }
}

let answer = dp[board.last!][N-1]
if answer == Int.max {
    print("-1")
} else {
    print(answer)
}
