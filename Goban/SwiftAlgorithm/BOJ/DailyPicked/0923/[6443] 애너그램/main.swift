//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/09/23.
//

import Foundation

// 시간초과
//
//let N = Int(readLine()!)!
//for _ in 0..<N {
//    let word = String(readLine()!).map{ String($0) }.sorted(by: >)
//
//    var result: Set<[String]> = []
//
//    var stack: [([String], [Bool])] = word.enumerated().map {
//        var visited = Array(repeating: false, count: word.count)
//        visited[$0.offset] = true
//        return ([$0.element], visited)
//    }
//
//    while stack.count > 0 {
//        let now = stack.removeLast()
//
//        let elements = now.0
//        var visited = now.1
//
//        if elements.count == word.count {
//            if !result.contains(elements) {
//                result.insert(elements)
//                print(elements.joined())
//            }
//            continue
//        }
//
//        for i in 0...word.count-1 {
//            if visited[i] { continue }
//            visited[i] = true
//            stack.append((elements + [word[i]], visited))
//            visited[i] = false
//        }
//    }
//}

let N = Int(readLine()!)!


for _ in 0..<N {
    let word = String(readLine()!).map{ String($0) }.sorted(by: <)
    var visited: [String: Int] = [:]
    var answer: [String] = []
    for i in word {
        visited[i, default: 0] += 1
    }
    func backTracking(cnt: Int) {
        if cnt == word.count {
            print(answer.joined())
        }
        for j in word {
            if visited[j, default: 0] > 0 {
                visited[j]! -= 1
                answer.append(j)
                backTracking(cnt: cnt + 1)
                visited[j]! += 1
                answer.removeLast()
            }
        }
    }
    backTracking(cnt: 0)
}
