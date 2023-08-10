//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/03.
//

import Foundation

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let (C, N) = (input[0], input[1])
var cities: [(price: Int, people: Int)] = []

// dp n 명을 모으는데 필요한 최소 비용

