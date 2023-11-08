//
//  Permutation.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/11/05.
//

import Foundation

func permutation<T: Comparable>(_ array: [T], _ n: Int) -> [[T]] {
    var result: [[T]] = []
    var stack: [([T], [Bool])] = array.enumerated().map {
        var visited = Array(repeating: false, count: array.count)
        visited[$0.offset] = true
        return ([$0.element], visited)
    }
    
    while !stack.isEmpty {
        let now = stack.removeLast()
        let elements = now.0
        var visited = now.1
        
        if elements.count == n {
            result.append(elements)
            continue
        }
        
        for i in 0..<array.count {
            if visited[i] {
                continue
            }
            visited[i] = true
            stack.append((elements + [array[i]], visited))
            visited[i] = false
        }
    }
    return result
}
