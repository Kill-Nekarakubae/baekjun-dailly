//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/24.
//

import Foundation
//
//// BFS, visited 에 들었던 최소비용을 저장하면서 이동.
//var queue: [(position: (x: Int, y: Int), money: Int)] = []
//
//extension Collection {
//    func customPopFirst() -> (popedCollection: [Self.Element], popedElement: Self.Element) {
//        var reversedCollection = self.reversed()
//        let popedElement = reversedCollection.removeLast()
//        return (reversedCollection.reversed(), popedElement)
//    }
//}
//
//let n = Int(readLine()!)!
//var board: [[Int]] = [[]]
//var visited: [[Int]] = Array(repeating: Array(repeating: Int.max, count: n+1), count: n+1)
//for _ in 0..<n {
//    let line = [0] + readLine()!.split(separator: " ").map{ Int($0)! }
//    board.append(line)
//}
//
//queue.append((position: (x: 1, y: 1), money: 0))
//
//while !queue.isEmpty {
//    let popedElement = queue.customPopFirst()
//    queue = popedElement.popedCollection
//    let e = popedElement.popedElement
//    let position = e.position
//    let (x, y) = (position.x, position.y)
//    let money = e.money
//    let currentNum = board[y][x]
//
//    if y == n && 1..<n ~= x {
//        var moveCost = 0
//        let nextNum = board[y][x+1]
//        if currentNum <= nextNum {
//            moveCost = nextNum - currentNum + 1
//        }
//        if visited[y][x+1] > money + moveCost {
//            visited[y][x+1] = money + moveCost
//            queue.append((position: (x: x+1, y: y), money: money + moveCost))
//        }
//    } else if 1..<n ~= y && x == n {
//        var moveCost = 0
//        let nextNum = board[y+1][x]
//        if currentNum <= nextNum {
//            moveCost = nextNum - currentNum + 1
//        }
//        if visited[y+1][x] > money + moveCost {
//            visited[y+1][x] = money + moveCost
//            queue.append((position: (x: x, y: y+1), money: money + moveCost))
//        }
//    } else if 1 <= y && x < n {
//        var moveCost = 0
//        var nextNum = board[y][x+1]
//        if currentNum <= nextNum {
//            moveCost = nextNum - currentNum + 1
//        }
//        if visited[y][x+1] > money + moveCost {
//            visited[y][x+1] = money + moveCost
//            queue.append((position: (x: x+1, y: y), money: money + moveCost))
//        }
//        moveCost = 0
//        nextNum = board[y+1][x]
//        if currentNum <= nextNum {
//            moveCost = nextNum - currentNum + 1
//        }
//        if visited[y+1][x] > money + moveCost {
//            visited[y+1][x] = money + moveCost
//            queue.append((position: (x: x, y: y+1), money: money + moveCost))
//        }
//    } else {
//        visited[y][x] = money
//    }
//}
//
//print(visited[n][n])

// dijkstra
let n = Int(readLine()!)!
var board: [[Int]] = [[]]
var cost: [[Int]] = Array(repeating: Array(repeating: 0, count: n+1), count: n+1)
for _ in 0..<n {
    let line = [0] + readLine()!.split(separator: " ").map{ Int($0)! }
    board.append(line)
}

for i in 1...n {
    for j in 1...n {
        if i-1 < 1 && j-1 < 1 {
            continue
        }
        var costUp = Int.max
        var costLeft = Int.max
        if i-1 >= 1 {
            costUp = cost[i-1][j]
            if board[i][j] >= board[i-1][j] {
                costUp += board[i][j] - board[i-1][j] + 1
            }
        }
        if j-1 >= 1 {
            costLeft = cost[i][j-1]
            if board[i][j] >= board[i][j-1] {
                costLeft += board[i][j] - board[i][j-1] + 1
            }
        }
        cost[i][j] = min(costUp, costLeft)
    }
}

print(cost[n][n])
