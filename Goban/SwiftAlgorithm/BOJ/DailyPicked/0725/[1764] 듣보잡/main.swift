//
//  File.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/25.
//

import Foundation

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let N = input[0]
let M = input[1]
var notListen: [String: Int] = [:]
var printList: [String] = []
for _ in 0..<N {
    let line = String(readLine()!)
    notListen[line] = 0
}
for _ in 0..<M {
    let line = String(readLine()!)
    if notListen[line] != nil {
        printList.append(line)
    }
}
print(printList.count)
printList.sorted(by: <).forEach { str in
    print(str)
}
