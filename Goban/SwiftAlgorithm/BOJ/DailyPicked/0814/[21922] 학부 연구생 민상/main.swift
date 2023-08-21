//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/14.
//

import Foundation

// 에어컨: 4방향
// 물건1: 좌, 우 방향이 온다면 반대방향으로 이동
// 물건2: 상, 하 방향이 온다면 반대방향으로 이동
// 물건3: 상 -> 좌, 좌 -> 상, 우 -> 하, 하 -> 우
// 물건4: 우 -> 상, 상 -> 우, 좌 -> 하, 하 -> 좌

enum Direction: Int {
    case stop = 0
    case up
    case down
    case left
    case right
}

enum Stuff: Int {
    case zero = 0
    case one
    case two
    case three
    case four
    case nine = 9
}

func convertDirectionByStuff(from: Direction, stuff: Stuff) -> Direction {
    switch stuff {
    case .one:
        if case .left = from {
            return .right
        }
        if case .right = from {
            return .left
        }
    case .two:
        if case .down = from {
            return .up
        }
        if case .up = from {
            return .down
        }
    case .three:
        switch from {
        case .up:
            return .right
        case .down:
            return .left
        case .left:
            return .down
        case .right:
            return .up
        default:
            return from
        }
    case .four:
        switch from {
        case .up:
            return .left
        case .down:
            return .right
        case .left:
            return .up
        case .right:
            return .down
        default:
            return from
        }
    default:
        return from
    }
    return from
}

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let (N, M) = (input[0], input[1])
var board: [[Int]] = []
for _ in 0..<N {
    let line = readLine()!.split(separator: " ").map{ Int($0)! }
    board.append(line)
}

var answer = 0
var windStack = DoubleStackQueue<(direction: Direction, position: (x: Int, y:Int))>()
var visited = Array(repeating: Array(repeating: Array(repeating: false, count: 5), count: M), count: N)
let dx = [0, 0, 0, -1, 1]
let dy = [0, -1, 1, 0, 0]
var alreadyVisited = Array(repeating: Array(repeating: false, count: M), count: N)

func DFS(x: Int, y:Int) {
    for i in 1..<5 {
        windStack.enqueue((direction: Direction(rawValue: i)!, position: (x: x, y: y)))
    }
    if !alreadyVisited[y][x] {
        answer += 1
    }
    alreadyVisited[y][x] = true
    visited[y][x][0] = true
    while !windStack.isEmpty {
        let wind = windStack.dequeue()!
        let mx = wind.position.x + dx[wind.direction.rawValue]
        let my = wind.position.y + dy[wind.direction.rawValue]
        if 0..<N ~= my && 0..<M ~= mx && !visited[my][mx][wind.direction.rawValue] {
            if !alreadyVisited[my][mx] {
                answer += 1
            }
            alreadyVisited[my][mx] = true
            visited[my][mx][wind.direction.rawValue] = true
            let stuff = Stuff(rawValue: board[my][mx])!
            let convertedDirection = convertDirectionByStuff(from: wind.direction, stuff: stuff)
            var needTobreak = false
            switch stuff {
            case .one:
                if wind.direction == .left || wind.direction == .right {
                    needTobreak = true
                }
            case .two:
                if wind.direction == .up || wind.direction == .down {
                    needTobreak = true
                }
            default:
                break
            }
            if needTobreak {
                continue
            }
            windStack.enqueue((direction: convertedDirection, position: (x: mx, y: my)))
        }
    }
}

for i in 0..<N {
    for j in 0..<M {
        if board[i][j] == 9 {
            DFS(x: j, y: i)
        }
    }
}

print(answer)
