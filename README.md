# Console Gobang (五子棋)

第一个项目，来自北京大学《计算概论》课程大作业。
这是一个轻量级的控制台版五子棋游戏，不依赖任何庞大的 IDE 或图形库，开箱即用。

## 游戏特色

*   **纯 C++ 实现**：核心逻辑与界面分离，代码清晰。
*   **跨平台兼容**：基于标准输入输出，可在 Windows、Linux、macOS 的终端中运行。
*   **智能 AI**：内置 Minimax 算法 AI，支持人机对战。
*   **多种模式**：
    1.  人人对战
    2.  人机对战（玩家执黑）
    3.  人机对战（玩家执白）

## 目录结构

```
.
├── main.cpp                # 游戏入口与控制台界面
├── run_console.bat         # Windows 一键编译运行脚本
├── src/
│   ├── game_service.cpp    # 核心游戏逻辑 (胜负判断, AI算法)
│   └── board.cpp           # 棋盘数据结构
└── include/
    ├── game_service.h      # 逻辑接口声明
    └── board.h             # 棋盘类声明
```

## 如何运行

### Windows 用户

1.  确保你已安装 `g++` 编译器 (MinGW 或其他)。
2.  双击运行 **`run_console.bat`**。
3.  或者在终端中输入：
    ```powershell
    .\run_console.bat
    ```

### 其他系统 (Linux/macOS)

在终端中运行以下命令编译并启动：

```bash
g++ main.cpp src/game_service.cpp src/board.cpp -I include -o gobang
./gobang
```

## 玩法说明

1.  启动游戏后，输入数字选择模式。
2.  轮到你落子时，输入 **行号** 和 **列号**，中间用空格隔开。
    *   例如输入：`7 7` 表示在棋盘正中间落子。
3.  **X** 代表黑棋，**O** 代表白棋。
4.  黑棋先行，黑棋有禁手规则（长连、三三、四四禁手）。

祝你游戏愉快！
