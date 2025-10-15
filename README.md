# Gobang 五子棋（EasyX 版）

自己的第一个项目。来自北京大学《计算概论A》大作业五子棋小游戏（Windows/Visual Studio/EasyX），包含：
- 主菜单、设置页、规则与关于
- 人机/人人对战
- 存档/读档（基于内存的简单保存）
- 禁手判定（长连、双三、双四）
- 简易 AI（启发式打分 + 极大极小 Alpha-Beta）

## 运行环境
- 操作系统：Windows（仅支持）
- 开发工具：Visual Studio（建议 2019/2022）
- 图形库：EasyX（graphics.h）
- 音频：Windows MCI（winmm.lib）

> 资源文件现已集中到 `assets/` 目录：
> - 图片：`assets/images/*.jpg`
> - 音乐：`assets/audio/*.mp3`（BGM 使用 `bgmusic.mp3`，MCI alias 为 `bgm`）

## 快速开始（Visual Studio）
1. 打开现有工程：`Project 1 五子棋.vcxproj`
2. 确保已安装 EasyX（或工程自带依赖），并在项目属性中链接 `winmm.lib`
3. 保证程序的工作目录能访问 `assets/`（VS 默认工作目录在项目根或 `x64/Debug`，目前代码使用相对路径 `assets/...`）
4. 生成并运行
## 运行核心测试（可选，CMake）
- 本项目提供了不依赖 UI 的核心逻辑测试（如 `Board::isWin`）。
- 本地运行：
	1) 安装 CMake 与编译器（VS/MSVC 或 MinGW）
	2) 在项目根目录执行：
		 - `cmake -S . -B build -DCMAKE_BUILD_TYPE=Release`
		 - `cmake --build build --config Release`
		 - `ctest --test-dir build -C Release --output-on-failure`

## CI
- 已配置 GitHub Actions（Windows）：在推送或 PR 时自动构建并运行核心测试。

若首次打开出现中文字体显示异常（乱码），可尝试：
- 将源文件保存为 UTF-8（带 BOM）
- 在 VS 中设置“源文件编码”为 UTF-8

## 目录结构（当前）
- `main.cpp`：所有逻辑集中于此（UI/事件循环/落子/判定/AI/存读档）
- `Project 1 五子棋.*`：Visual Studio 工程文件
- `x64/Debug/`：VS 构建产物（建议忽略）

## 操作说明（简要）
- 进入主菜单后，可选择新游戏（人机/人人）、读档、设置、退出
- 人机模式下可选执黑/执白；AI 使用启发式评分 + Alpha-Beta 搜索
- 设置页可开关 BGM，查看规则与关于信息
