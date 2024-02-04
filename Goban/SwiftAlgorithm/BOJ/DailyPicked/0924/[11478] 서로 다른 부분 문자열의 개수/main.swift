//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/09/24.
//

import Foundation

var result = Set<String>()
let word = String(readLine()!).map{String($0)}

for i in 0..<word.count {
    var str = ""
    for j in i..<word.count {
        str += word[j]
        result.insert(str)
    }
}
print(result.count)
