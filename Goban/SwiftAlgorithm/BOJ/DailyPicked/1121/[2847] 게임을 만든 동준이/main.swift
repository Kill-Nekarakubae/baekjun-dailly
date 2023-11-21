//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/11/21.
//

import Foundation

let N = Int(readLine()!)!
var levels: [Int] = []
for _ in 0..<N {
    let num = Int(readLine()!)!
    levels.append(num)
}
var sum = 0
for i in (0..<levels.count-1).reversed() {
    if levels[i+1] <= levels[i] {
        sum += (levels[i]-levels[i+1]+1)
        levels[i] = levels[i+1]-1
    }
}
print(sum)
