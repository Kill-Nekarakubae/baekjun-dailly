//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/27.
//

import Foundation

let N = Int(readLine()!)!
var stationLength = readLine()!.split(separator: " ").map{ Int($0)! }
let gasPrice = readLine()!.split(separator: " ").map{ Int($0)! }
var spendMoney = 0
var lowPrice = gasPrice[0]

for i in 0..<N-1 {
    let needTogo = stationLength[i]
    let needBuy = needTogo*lowPrice
    spendMoney += needBuy
    lowPrice = min(lowPrice, gasPrice[i+1])
}

print(spendMoney)
