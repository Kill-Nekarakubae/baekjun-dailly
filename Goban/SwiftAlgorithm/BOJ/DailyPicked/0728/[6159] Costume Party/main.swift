//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/28.
//

import Foundation

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let N = input[0]
let S = input[1]
var cowsLen: [Int] = []

for _ in 0..<N {
    let len = Int(readLine()!)!
    cowsLen.append(len)
}

cowsLen.sort()
var answer = 0
for i in 0..<N-1 {
    for j in i+1..<N {
        let lenSum = cowsLen[i] + cowsLen[j]
        if lenSum <= S {
            answer += 1
        }
        if lenSum > S {
            break
        }
    }
}

print(answer)
