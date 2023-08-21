//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/17.
//

import Foundation

let numbers = readLine()!.map{ String($0) }

var head = "X"
var zeroCnt = 0
var oneCnt = 0
for number in numbers {
    if head != number {
        switch number {
        case "0":
            oneCnt += 1
            head = "0"
        case "1":
            zeroCnt += 1
            head = "1"
        default:
            break
        }
    }
}

print(min(zeroCnt, oneCnt))
