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
var board: [[String]] = []
for i in 0..<n {
    let line = String(readLine()!)
    board[i].append(line)
}
var redBoard: [[String]] = []

