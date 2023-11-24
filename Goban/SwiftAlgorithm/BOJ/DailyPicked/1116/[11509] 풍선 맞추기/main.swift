//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/11/16.
//

import Foundation

// 풍선을 최대한 맞추는데 필요한 갯수?.
// dictionary 로 해결도 가능할듯??

let N = Int(readLine()!)!
let H = readLine()!.split(separator: " ").map{ Int($0)! }
var arrows: [Int: Int] = [:]

var answer = 0
for balloon in H {
    if arrows[balloon, default: 0] != 0 {
        arrows[balloon, default: 0] -= 1
        if arrows[balloon, default: 0] == 0 {
            arrows[balloon] = nil
        }
    } else {
        answer += 1
    }
    if balloon - 1 > 0 {
        arrows[balloon - 1, default: 0] += 1
    }
}

print(answer)
