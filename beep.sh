#!/bin/bash

# 导出 GPIO42
sudo echo 42 > /sys/class/gpio/export&&

# 设置 GPIO42 为输出
sudo echo "out" > /sys/class/gpio/gpio42/direction&&

# 将 GPIO42 输出为高电平（1）
sudo echo 1 > /sys/class/gpio/gpio42/value&&

# 等待一段时间（可选）
sleep 0.1

# 将 GPIO42 输出为低电平（0）
sudo echo 0 > /sys/class/gpio/gpio42/value&&

# 取消导出 GPIO42（可选）
sudo echo 42 > /sys/class/gpio/unexport&&
