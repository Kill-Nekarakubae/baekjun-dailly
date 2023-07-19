//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/19.
//

import Foundation

func GCD(_ min: Int, _ max: Int) -> Int {
  let rem = min % max
  
  if rem == 0 { // 나머지가 0인 수. 즉, 약수를 의미한다.
    return max
  } else {
    return GCD(max, rem)
  }
}

let N = Int(readLine()!)!
let A = readLine()!.split(separator: " ").map{ Int($0)! }
let X = Int(readLine()!)!
var answer: [Double] = []

for a in A {
    let lhs: Int
    let rhs: Int
    if a > X {
        lhs = a
        rhs = X
    } else {
        lhs = X
        rhs = a
    }
    let gcd = GCD(lhs, rhs)
    if gcd == 1 {
        answer.append(Double(a))
    }
}

print(answer.reduce(Double(0), +)/Double(answer.count))
