//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/24.
//

import Foundation

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let (N, M) = (input[0], input[1])
var rail: [[Bool]] = Array(repeating: Array(repeating: false, count: 21), count: N+1)
for _ in 0..<M {
    let line = readLine()!.split(separator: " ").map{ Int($0)! }
    let order = line[0]
    switch order {
    case 1:
        rail[line[1]][line[2]] = true
    case 2:
        rail[line[1]][line[2]] = false
    case 3:
        for k in stride(from: 20, through: 1, by: -1) {
            if k == 20 {
                if rail[line[1]][k] {
                    rail[line[1]][k] = false
                }
                continue
            }
            if rail[line[1]][k] {
                rail[line[1]][k] = false
                rail[line[1]][k+1] = true
            }
        }
    case 4:
        for k in stride(from: 1, through: 20, by: 1) {
            if k == 1 {
                if rail[line[1]][k] {
                    rail[line[1]][k] = false
                }
                continue
            }
            if rail[line[1]][k] {
                rail[line[1]][k] = false
                rail[line[1]][k-1] = true
            }
        }
    default:
        break
    }
}


var railSet = Set<[Bool]>()
for i in 1...N {
    railSet.insert(rail[i])
}

print(railSet.count)
