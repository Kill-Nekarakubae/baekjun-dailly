//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/21.
//

let line = Array(readLine()!)
var answer: [String] = []

for i in 0..<line.count {
    var word = ""
    for j in i..<line.count {
        word += String(line[j])
    }
    answer.append(word)
}
answer = answer.sorted()

for a in answer {
    print(a)
}
