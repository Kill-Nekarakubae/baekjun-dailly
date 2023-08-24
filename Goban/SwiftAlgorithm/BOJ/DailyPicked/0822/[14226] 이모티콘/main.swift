//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/22.
//

import Foundation

// 관계성
// 화면 이모티콘 저장(s) -> 붙여넣기(p)
// 화면 이모티콘 중 하나 삭제(d).

//dp[2] = 2 (s -> p)
//dp[3] = 3 (s -> p -> p)
//dp[4] = 4 (s -> p -> p -> p), (s -> p -> s -> p)
//dp[5] =  (s -> p -> p -> p -> p), (s -> p -> s -> p -> p -> d)
// 점화식: 클립보드에서 가장 많이 저장된 이모티콘의 개수가 필요.
// dp[i] = dp[i-1] + 지금까지 거쳐오면서 존재하는 (p, + 부족한 만큼의 d) 의 최소.
// 현재 찾고자 하는 i

//dp[i][j]: i = 클립보드안의 이모티콘 개수, j = j까지의 최솟값
//-> dp[0~S] 에서의 최솟값
//
let S = Int(readLine()!)!
var dp = Array(repeating: Array(repeating: Int.max, count: S+1), count: S+1)
dp[1] =

for i in 1..<S {
    let startLine = dp[i-1][i]
    for
}
