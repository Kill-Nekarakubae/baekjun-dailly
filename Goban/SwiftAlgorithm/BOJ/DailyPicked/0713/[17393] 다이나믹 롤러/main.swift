//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/13.
//

import Foundation

// 잉크 > 점도 해야지 칠할 수 있음
//let n = Int(String(readLine()!))!
//let inks = readLine()!.components(separatedBy: " ").map{Int($0)!}
//let viscositys = readLine()!.components(separatedBy: " ").map{Int($0)!}
//var inkStack: [(ink: Int, num: Int)] = []
//var tempStack: [(ink: Int, num: Int)] = []
//var answers: [Int] = Array(repeating: 0, count: n)
//for i in 0..<n {
//    if i+1 < n {
//        inkStack.append((ink: inks[i], num: i))
//        while !inkStack.isEmpty {
//            let inkInfo = inkStack.popLast()!
//            if inkInfo.ink >= viscositys[i+1] {
//                answers[inkInfo.num] += 1
//                tempStack.append((ink: inkInfo.ink, num: inkInfo.num))
//            }
//        }
//        inkStack = tempStack
//        tempStack.removeAll()
//    }
//}
//print(answers.map{ String($0) }.joined(separator: " "))


let fIO = FileIO()
let n = fIO.readInt()

var inks: [Int] = []
for _ in 0..<n {
    let ink = fIO.readInt()
    inks.append(ink)
}
var viscositys: [Int] = []
for _ in 0..<n {
    let vicosity = fIO.readInt()
    viscositys.append(vicosity)
}
var answer = ""
for i in 0..<n {
    var l = i+1, r = n-1
    let ink = inks[i]
    while l<=r {
        let mid = (r+l)/2
        if viscositys[mid] <= ink {
            l = mid+1
        } else {
            r = mid-1
        }
    }
    answer += r == i ? String(0) : String(r-i)
    answer += " "
}
print(answer)
