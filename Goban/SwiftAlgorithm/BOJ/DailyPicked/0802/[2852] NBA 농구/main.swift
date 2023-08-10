//
//  main.swift
//  SwiftAlgorithm
//
//  Created by Lee Myeonghwan on 2023/08/02.
//

import Foundation

// 득점 시간 기록

enum GameState {
    case firstTeam
    case secondTeam
    case equal
}

var gameInfo: [(team: Int, time: Int)] = []
func convertToSecond(time: String) -> Int {
    let timeArray = time.map{ String($0) }
    let minuteToSecond = Int(timeArray[0] + timeArray[1])! * 60
    let second = Int(timeArray[3] + timeArray[4])!
    return minuteToSecond + second
}

func convertToTime(second: Int) -> String {
    let minuteStr = String(second / 60)
    let secondStr = String(second % 60)
    return "\(minuteStr.count < 2 ? "0" : "")\(minuteStr):\(secondStr.count < 2 ? "0" : "")\(secondStr)"
}

let N = Int(readLine()!)!
for _ in 0..<N {
    let input = readLine()!.split(separator: " ").map{ String($0) }
    gameInfo.append((team: Int(input[0])!, time: convertToSecond(time: input[1])))
}

var team1Score = 0
var team2Score = 0
var team1Time = 0
var team2Time = 0
var gameState: GameState = .equal
var prevTime = 0
for game in gameInfo {
    switch gameState {
    case .firstTeam:
        team1Time += game.time - prevTime
    case .secondTeam:
        team2Time += game.time - prevTime
    default:
        break
    }
    if game.team == 1 {
        team1Score += 1
    } else {
        team2Score += 1
    }
    if team1Score > team2Score {
        gameState = .firstTeam
    } else if team2Score > team1Score {
        gameState = .secondTeam
    } else {
        gameState = .equal
    }
    prevTime = game.time
}

switch gameState {
case .firstTeam:
    team1Time += convertToSecond(time: "48:00") - prevTime
case .secondTeam:
    team2Time += convertToSecond(time: "48:00") - prevTime
default:
    break
}

print(convertToTime(second: team1Time))
print(convertToTime(second: team2Time))
