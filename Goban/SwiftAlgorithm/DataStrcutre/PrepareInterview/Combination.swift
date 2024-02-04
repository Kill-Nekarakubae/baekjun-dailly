//
//  Combination.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/11/05.
//

import Foundation

func combination<T: Comparable>(_ array: [T], _ n: Int) -> [[T]] {
    var result: [[T]] = []
    var stack: [([T], Int)] = array.enumerated().map {
        return ([$0.element], $0.offset)
    }
    while !stack.isEmpty {
        let now = stack.removeLast()
        let elements = now.0
        let index = now.1
        
        if elements.count == n {
            result.append(elements)
            continue
        }
        
        guard index+1 < array.count else { continue }
        
        for i in index+1..<array.count {
            stack.append((elements + [array[i]], i))
        }
    }
    return result
}

let elements = [1, 5, 3, 2, 1]
print(combination(elements, 3))
