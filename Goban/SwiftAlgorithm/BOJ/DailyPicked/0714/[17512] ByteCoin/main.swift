//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/14.
//

import Foundation
// 수익률을 극대화 -> 저점에서 구매, 고점에서 판매
// 저점: 계속 저점일때까지
// 고점: 계속 고점일때까지

let input = readLine()!.components(separatedBy: " ").map{ Int($0)! }
let n = input[0]
let w = input[1]
var coinPrices: [Int] = []
for _ in 0..<n {
    let price = Int(readLine()!)!
    coinPrices.append(price)
}

var budget: Double = Double(w)
var needBuy = true
var currentCoin = 0
for i in 0..<n-1 {
    let todayPrice = coinPrices[i]
    let tomorrowPrice = coinPrices[i+1]
    if needBuy {
        if todayPrice < tomorrowPrice {
            currentCoin = Int(budget) / todayPrice
            budget -= Double(Int(currentCoin) * todayPrice)
            needBuy = false
        }
    } else {
        if todayPrice > tomorrowPrice {
            budget += Double(currentCoin*todayPrice)
            currentCoin = 0
            needBuy = true
        }
    }
}
budget += Double(currentCoin*coinPrices[n-1])


print(String(format: "%.0f", budget))

//let input = readLine()!.components(separatedBy: " ").map{ Int($0)! }
//let n = input[0]
//let w = input[1]
//var coinPrices: [Int] = []
//for _ in 0..<n {
//    let price = Int(readLine()!)!
//    coinPrices.append(price)
//}
//
//var budget = w
// 실패 ㅜㅜ 마지막 구간에서 계속 저점인 경우 손해를 보게됨.
//var coinPossesion: (price: Int, num: Int) = (51, 0)
//var prevPrice = 51
//for price in coinPrices {
//    // 저점이 시작 되는 경우
//    if coinPossesion.price > price { // 사는거
//        if prevPrice < price {
//            budget += coinPossesion.price*coinPossesion.num
//            let buyCoinNum = budget / prevPrice
//            budget -= prevPrice*buyCoinNum
//            coinPossesion = (price: price, num: buyCoinNum)
//        }
//    }
//    // 고점 시작
//    else {
//        // 고점 -> 저점으로 바뀌는 경우
//        if prevPrice > price {
//            // 이전 고점 가격에 판매
//            budget += prevPrice*coinPossesion.num
//            // 현재 저점으로 돌입한 코인 다시 구매
//            let buyCoinNum = budget / price
//            budget -= buyCoinNum*price
//            coinPossesion = (price: price, num: buyCoinNum)
//        }
//    }
//    prevPrice = price
//
//}
//
//if coinPossesion.num != 0 {
//    if prevPrice > coinPossesion.price {
//        budget += coinPossesion.num * prevPrice
//    } else {
//        budget += coinPossesion.num * coinPossesion.price
//    }
//}
