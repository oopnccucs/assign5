
# Programming Assignment #5

**Due:2024/5/14 23:59:59**

NCCU OOP 112 spring

author: @organic_san at 2024/4/5

---

## Topic: 建立一個控制台的RPG遊戲(Part 1)
## Objective: 熟悉 OOP 概念與多檔案之間的操作

## Description

### 遊戲目標
使用控制台建立一個RPG的小遊戲，包含進入遊戲、移動、切換房間，以及戰鬥、收尾等流程。

在進入遊戲之後，遊戲會來到以35 * 20的格子單位所建構成的房間，也就是遊戲中的地圖。玩家可以使用WASD進行前後左右的操作，操作名為「PL」的玩家圖示進行在房間中前後左右的移動，並且會受到牆壁的阻擋。

透過來到房間的左右側進行房間的切換，其中本次作業只考慮左右之間的地圖切換，不考慮上下之間的房間切換。房間透過 `id` 彼此左右連接，最左邊為0號的房間，每往右側的房間，房間`id`會+1，往左側的房間時，房間id會-1。但是不能前往資料不存在的房間。

遊戲中會出現有自我移動方式的敵人，需要設計怪物的移動模式。在遭遇怪物之後，將會進入戰鬥模式，此時玩家可以做出從選單中選擇以下四種操作：攻擊、防禦、猛力一擊、以及回複，詳細的差異將於後續作業中說明。

如果被怪物擊倒，將進入遊戲結束狀態，而怪物可以設定成最終boss，擊倒有最終boss標記的敵人時，則將進入遊戲過關狀態。

完整版本的遊戲試玩可以執行這個程式：<br>
`./example/rpg-game-full-example`

### 本次作業目標

本次作業的目標是完成遊戲中的座標系統，讀取位於 `./src/gameobjects/room/roomdata.h` 的資料至遊戲中，並實作遊戲中的移動處理，目標是能讓名為「PL」的玩家標示能使用WASD來操作上下左右移動，其中W、A、S、D分別對應上、左、下、右的操作，以及處理牆壁、山岩、水會阻擋玩家前進，而門與草地不阻擋玩家前進的邏輯。

在本次作業中，主要以物件的使用與操作、std容器：map的使用，以及物件繼承為目標。

render的部分已包含在作業檔案中，不需處理輸出處理的排版部分。

### 需要完成的內容
- 完成position class
- 將Player class改寫成繼承自GameObject class
- 完成Player class與Room class
- 設計Controller class的run()函數，並在裡面完成邏輯處理


## 評分標準
| 評分標準 | 分數 |
| - | - |
| 上傳檔案 | 30分 |
| 可以編譯 | 20分 |
| 人物(PL)可以移動 | 20分 |
| 人物(PL)移動會受到牆壁阻礙 | 10分 |
| Player class繼承自GameObject class並進行相對應的改寫 | 20分 |


## Assignment Directory
`/usr/local/class/oop/assign/assign5`
or https://github.com/oopnccucs/assign5


## 作業繳交方式
在OOP主機中，assign5資料夾下，輸入：
```
/usr/local/class/oop/bin/submit 5
```
繳交本次作業。


## Sample Output
請參見 `./example/rpg-game-part1-example` 的執行結果，若順利的話會出現以下圖片：![pic](https://i.imgur.com/lhKgeVc.png)

其中`WW`代表草地，`██`代表牆壁，`DR`代表門，`PL`代表角色。

場地物件的名稱與種類記錄在 `./src/gameobjects/room/roomstate.h` 中。

玩家可以透過WASD進行「PL」的移動，而移動會受到牆壁的阻礙。


## Files in the Assignment Directory

- `./src/main.cpp`: <br>
  處理進入遊戲之後，將調整控制台模式並捕捉鍵盤輸入，定時呼叫 `game.lifeCycle(action)` 建立遊戲迴圈，而輸入的內容在經過處理之後成為遊戲的每幀進入點。<br>
  不需要調整這個檔案的內容。

- `./src/gamecore`: <br>
  用於處理遊戲外部操作接收的class。<br>
  不需要調整這個資料夾的內容。

- `./src/functions`:<br>
  包含 `AnsiPrint` 與 `position` ，其中 `AnsiPrint` 不需要調整內容，需要完成`position`中的功能。

- `./src/controller`:<br>
  用於處理遊戲內中反應的部分，其中 `run()` 函數會由 `gamecore` 呼叫，是遊戲主要循環的函數，會在每幀執行一次。<br>
  在這次的作業中需要完成玩家的操作部分，以及移動的判定部分。

  - `enviroment`:<br>
    儲存了遊戲中的環境變數。其中 `SPEED` 為每幀秒數(s)。

- `./src/gameobjects`:<br>
  主要處理遊戲物件的反應，其中包含 `player` 、 `room` 與 `gameobject` 。

  - `player`:<br>
    繼承了 `GameObject` class，需要完成操作相關的函數。

  - `room`:<br>
    包含遊戲的房間內容，以及相關的行為處理。`Room` class 是單一個房間的 class，請完成資料的輸入以及判斷的部分。

  - `gameobject`:<br>
    包含遊戲物件的基本定義。請完成這個class。

- `./src/gameprocess`:<br>
  目前記錄了關於遊戲進程狀態的 struct，在後續作業中會逐漸追加狀態種類。


## Implementation Notes

編譯:`$make`

執行: `$make run`

作業的檔案中並沒有完整的提供可能會用到的所有成員函數。如果在編寫的過程中認為追加函數將有利於作業的進行，可以自由追加，包含在作業中的函數也可以進行條整。<br>
例如在處理座標的時候，考慮到輸入格式是方向而不是座標位置，可以透過加入`Direction` struct，或許將有利於處理輸入與運作之間的轉換。