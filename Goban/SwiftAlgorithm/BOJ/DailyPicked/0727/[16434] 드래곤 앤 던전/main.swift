//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/27.
//

import Foundation

let input = readLine()!.split(separator: " ").map{ Int($0)! }
let N = input[0]
let initialHeroAtk = input[1]
var rooms: [(info: Int, a: Int, h: Int)] = []
var start = 0
var end = 1
for _ in 0..<N {
    let line = readLine()!.split(separator: " ").map{ Int($0)! }
    rooms.append((info: line[0], a: line[1], h: line[2]))
    if line[0] == 1 {
        let atkCnt = ceil(Double(line[2])/Double(initialHeroAtk))
        end += Int(ceil(atkCnt*Double(line[1])))
    }
}
// 1 몬스터
// 2 힐링
var minHp = Int.max
while start <= end {
    let mid = (start + end) / 2
    var heroHP = mid
    var heroAtk = initialHeroAtk
    var fail = false
    var roomCnt = 1
    for room in rooms {
        roomCnt += 1
        if room.info == 1 {
            let monsterHP = room.h
            let monsterAtk = room.a
            let atkCnt = Int(ceil(Double(monsterHP) / Double(heroAtk)))
            heroHP -= monsterAtk*(atkCnt-1)
            
            if heroHP <= 0 {
                fail = true
                break
            }
        } else {
            heroHP += room.h
            heroAtk += room.a
            if heroHP > mid {
                heroHP = mid
            }
        }
        if fail {
            break
        }
    }
    if fail {
        start = mid + 1
    } else {
        minHp = min(minHp, mid)
        end = mid - 1
    }
}

print(minHp)
