//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/09/14.
//

import Foundation

// 무조건 선물을 받는곳: E 를 통해 이동하다가 반복구간에 빠지는곳?
// 반복 EEE or WWW 반복이 끊어지면 +1

let N = Int(readLine()!)!
let board = String(readLine()!).map{ String($0) }
var W = false
var answer = 0
var idx = 0
while idx < board.count {
    if board[idx] == "W" {
        while idx < board.count && board[idx] == "W" {
            idx += 1
        }
        answer += 1
        continue
    }
    idx += 1
}
print(answer)
