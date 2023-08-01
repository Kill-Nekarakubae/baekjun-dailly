//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/31.
//

import Foundation

// 공유기 사이의 거리를 최대로 -> 5 개의 좌표중에 어느 공유기에 놓아야하는가?
// -> 공유기 사이

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let N = input[0]
let C = input[1]
var house: [Int] = []
for _ in 0..<N {
    let line = Int(readLine()!)!
    house.append(line)
}

house.sort()

var minGap = 1
var maxGap = house.last! - house.first!
var result = 0

while minGap<=maxGap {
    let midGap = (minGap + maxGap) / 2
    var value = house[0]
    var count = 1
    for i in 1..<house.count {
        if house[i] >= value + midGap {
            value = house[i]
            count += 1
        }
    }
    if count >= C {
        minGap = midGap + 1
        result = midGap
    } else {
        maxGap = midGap - 1
    }
}

print(maxGap)
