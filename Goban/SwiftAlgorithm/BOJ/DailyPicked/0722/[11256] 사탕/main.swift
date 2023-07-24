//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/22.
//

import Foundation

let T = Int(readLine()!)!

for _ in 0..<T {
    let input = readLine()!.split(separator: " ").map{ Int($0)! }
    let J = input[0]
    let N = input[1]
    var boxLens: [Int] = []
    for _ in 0..<N {
        let boxLen = readLine()!.split(separator: " ").map{ Int($0)! }.reduce(1, *)
        boxLens.append(boxLen)
    }
    var space = 0
    var answer = 0
    boxLens.sort(by: >)
    for boxLen in boxLens {
        space += boxLen
        answer += 1
        if space >= J {
            break
        }
    }
    print(answer)
}
