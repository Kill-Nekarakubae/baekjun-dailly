//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/26.
//

import Foundation

var dwarf: [Int] = []
var total = 0
for _ in 0..<9 {
    let input = Int(readLine()!)!
    total += input
    dwarf.append(input)
}

func findCheating() -> (Int,Int) {
    for i in 0..<8 {
        let cTotal = total - dwarf[i]
        for j in i+1..<9 {
            if cTotal - dwarf[j] == 100 {
                return (i,j)
            }
        }
    }
    return (0,0)
}
let (i, j) = findCheating()
dwarf.remove(at: j)
dwarf.remove(at: i)
dwarf.sort()
dwarf.forEach { height in
    print(height)
}
