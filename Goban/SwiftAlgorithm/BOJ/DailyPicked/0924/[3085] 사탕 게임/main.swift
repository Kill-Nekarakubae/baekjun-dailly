//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/09/24.
//

import Foundation
let N = Int(readLine()!)!
var board: [[String]] = []
var result = 1

for _ in 0..<N {
    let line = String(readLine()!).map{String($0)}
    board.append(line)
}

func rowCount() {
    for i in 0..<N {
        var count = 1
        for j in 0..<N-1 {
            if board[i][j] == board[i][j+1] {
                count += 1
            } else {
                result = max(result, count)
                count = 1
            }
        }
        result = max(result, count)
    }
}

func colCount() {
    for i in 0..<N {
        var count = 1
        for j in 0..<N-1 {
            if board[j][i] == board[j+1][i] {
                count += 1
            } else {
                result = max(result, count)
                count = 1
            }
        }
        result = max(result, count)
    }
}

for i in 0..<N {
    for j in 0..<N-1 {
        board[i].swapAt(j,j+1)
        rowCount()
        colCount()
        board[i].swapAt(j,j+1)
        
        var temp = board[j][i]
        board[j][i] = board[j+1][i]
        board[j+1][i] = temp
        
        rowCount()
        colCount()
        
        temp = board[j][i]
        board[j][i] = board[j+1][i]
        board[j+1][i] = temp
    }
}

print(result)
