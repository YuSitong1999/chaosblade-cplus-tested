# ChaosBlade C++ Tested 被测程序

作为被测程序，用于测试 [适用于C++程序的ChaosBlade](https://github.com/YuSitong1999/chaosblade-exec-cplus) 故障注入脚本 。

## 简介

## 运行程序

### 单独构建和运行

```shell
g++ -g -o main main.cpp

./main

cat hello.txt | tail

```

### 使用 CMake 构建和运行

在 CLion 中点击运行。

## 注入故障

### 函数立即返回指定值

参数：目标进程号，fork模式，空，空，所在行号，返回值，初始化参数（？）

[shell_break_and_return_attach_parent.sh](./shell_break_and_return_attach_parent.sh)

```shell
./shell_break_and_return_attach_parent.sh 114024 parent "" "" main.cpp:21 99 ""
./shell_break_and_return_attach_parent.sh 115665 parent "" "" printTimeAndHelloWorld 99 ""

# 理论上可以通过以下方式区分重载的函数，但实际效果可能不符合预期，返回以下错误
# Function "printTimeAndHelloWorld(std::string const&, int)" not defined.
# Make breakpoint pending on future shared library load? (y or [n])
#./shell_break_and_return_attach_parent.sh 115665 parent "" "" "printTimeAndHelloWorld(std::string const&, int)" 99 ""
# 经尝试未能解决问题： https://chat.openai.com/share/5c49b493-5cac-484e-b880-466e7db7f940
```

### 变量修改故障

参数：目标进程号，fork模式，空，空，所在行号，变量名，变量新值，初始化参数（？）

[shell_modify_variable_attach_parent.sh](./shell_modify_variable_attach_parent.sh)

```shell
# 实测即使是const值也可以被修改
./shell_modify_variable_attach_parent.sh 163257 parent "" "" main.cpp:18 count 9 ""

```

### 延迟故障

参数：目标进程号，fork模式，空，空，所在行号，延迟时间，初始化参数（？）

[shell_response_delay_attach_parent.sh](./shell_response_delay_attach_parent.sh)

```
./shell_response_delay_attach_parent.sh 173649 parent "" "" main.cpp:18 5 ""

```
