//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/07/21.
//

import Foundation

let T = Int(readLine()!)!
for _ in 0..<T {
    var animalSounds: [String] = []
    let record = readLine()!.split(separator: " ").map{ String($0) }
    while true {
        let input = readLine()!
        if input == "what does the fox say?" {
            break
        }
        let animalSound = input.split(separator: " ").map{ String($0) }
        let bark = animalSound[2]
        animalSounds.append(bark)
    }
    
    for sound in record {
        if !animalSounds.contains(sound) {
            print(sound, terminator: " ")
        }
    }
    
}
