//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/11/17.
//

import Foundation

// 친구 네트워크: union 으로 네트워크 합치기 + 친구 수 갱신

//let T = Int(readLine()!)!
//for _ in 0..<T {
//    let F = Int(readLine()!)!
//    var parent: [String: String] = [:]
//    var level: [String: Int] = [:]
//
//    func root(name: String) -> String {
//        if parent[name]! == name { return name }
//        let parent = root(name: parent[name]! )
//        return parent
//    }
//
//    func union(x: String, y: String) {
//        let rootUnion = root(name: x)
//        let otherUnion = root(name: y)
//        if rootUnion == otherUnion { return }
//        level[rootUnion]! += level[otherUnion]!
//        parent[otherUnion] = parent[rootUnion]
//        print(level[rootUnion]!)
//    }
//
//    for _ in 0..<F {
//        let friends = readLine()!.split(separator: " ").map{ String($0) }
//        let aFriend = friends[0]
//        let bFriend = friends[1]
//        if parent[aFriend] == nil {
//            parent[aFriend] = aFriend
//            level[aFriend] = 1
//        }
//        if parent[bFriend] == nil {
//            parent[bFriend] = bFriend
//            level[bFriend] = 1
//        }
//        union(x: aFriend, y: bFriend)
//    }
//}
// 시간초과


func solution() {
    let n = Int(readLine()!)!
    var parent: [String: String] = [:]
    var level: [String: Int] = [:]
    var relations: [String] = []
    
    for _ in 0..<n {
        relations.append(readLine()!)
    }
    
    for relation in relations {
        let names = relation.split(separator: " ").map { String($0) }
        parent[names[0]] = names[0]
        parent[names[1]] = names[1]
        level[names[0]] = 1
        level[names[1]] = 1
    }
    
    for relation in relations {
        let names = relation.split(separator: " ").map { String($0) }
        union(names[0], names[1])
        print(level[find(names[0])]!)
    }
    
    func find(_ name: String) -> String {
        if parent[name]! == name {
            return name
        }
        parent[name] = find(parent[name]!)
        return parent[name]!
    }
    
    func union(_ n1: String, _ n2: String) {
        let n1 = find(n1)
        let n2 = find(n2)
        
        if n1 == n2 {
            return
        }
        parent[n1] = n2
        let maxLevel = level[n1]! + level[n2]!
        level[n1]! = maxLevel
        level[n2]! = maxLevel
    }
}

let t = Int(readLine()!)!
for _ in 0..<t { solution() }
