//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/31.
//

import Foundation

// 단어를 세 개의 단어로 나눈다.

let input = Array(readLine()!)
var list = [String]()
for i in 0..<input.count-2{
    for k in i+1..<input.count-1{
        for m in k+1..<input.count{
            list.append("\(String(input[0..<k].reversed()))\(String(input[k..<m].reversed()))\(String(input[m...input.count-1].reversed()))")
        }
    }
}

print(list.sorted(by: <)[0])
