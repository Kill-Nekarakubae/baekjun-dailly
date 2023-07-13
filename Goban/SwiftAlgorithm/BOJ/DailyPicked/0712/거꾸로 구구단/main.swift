//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/12.
//

import Foundation

let input = readLine()!.components(separatedBy: " ").map { Int(String($0))! }
let n = input[0]
let k = input[1]
var gugudan: [Int] = []
var h = 1
for d in 1...k {
    gugudan.append(d*n)
}
let gugudanString = gugudan.map { String(String($0).reversed()) }
gugudan = gugudanString.map{ Int($0)! }
gugudan.sort(by: <)
print(gugudan.last!)
