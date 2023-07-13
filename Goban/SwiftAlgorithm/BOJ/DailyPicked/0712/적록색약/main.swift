//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/12.
//

import Foundation
// 적록색약: 빨간색 - 초록색 동일 (R, G)
// 적록색약인 사람, 적록색약 아닌사람 따로 BFS
// 적록색약 board를 만들어 R을 G 로 변경

var n = Int(readLine()!)!
var normalVisited: [[Bool]] = Array(repeating: Array(repeating: false, count: n), count: n)
var redVisited: [[Bool]] = Array(repeating: Array(repeating: false, count: n), count: n)
var normalBoard: [[String]] = []
let dy = [-1, 1, 0, 0]
let dx = [0, 0, -1, 1]

for _ in 0..<n {
    let line = String(readLine()!).map{ String($0) }
    normalBoard.append(line)
}
var redBoard: [[String]] = []
for i in 0..<n {
    var line: [String] = []
    for j in 0..<n {
        var color = normalBoard[i][j]
        if color == "R" {
            color = "G"
        }
        line.append(color)
    }
    redBoard.append(line)
}

var stack: [(x: Int, y: Int)] = []
func BFS(color: String, red: Bool) {
    while !stack.isEmpty {
        let (x, y) = stack.popLast()!
        for i in 0...3 {
            let mx = x + dx[i]
            let my = y + dy[i]
            if 0..<n ~= mx && 0..<n ~= my && ( red ? !redVisited[my][mx] : !normalVisited[my][mx]) && (red ? color == redBoard[my][mx] : color == normalBoard[my][mx] ) {
                stack.append((x: mx, y: my))
                if red {
                    redVisited[my][mx] = true
                } else {
                    normalVisited[my][mx] = true
                }
            }
        }
    }
}

var normalCount = 0
var redCount = 0
for i in 0..<n {
    for j in 0..<n {
        if normalVisited[i][j] == false {
            stack.append((x: j, y: i))
            normalVisited[i][j] = true
            BFS(color: normalBoard[i][j], red: false)
            normalCount += 1
        }
        if redVisited[i][j] == false {
            stack.append((x: j, y: i))
            redVisited[i][j] = true
            BFS(color: redBoard[i][j], red: true)
            redCount += 1
        }
    }
}

print(normalCount, redCount)
