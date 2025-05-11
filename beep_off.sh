#!/system/bin/sh
# 输出低电平，蜂鸣器停止
echo 0 > /sys/class/gpio/gpio42/value
