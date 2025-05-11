#!/system/bin/sh

# 导出 GPIO42（如果尚未导出）
if [ ! -e /sys/class/gpio/gpio42 ]; then
  echo 42 > /sys/class/gpio/export
  sleep 0.1
fi

# 设置为输出
echo out > /sys/class/gpio/gpio42/direction
# 输出高电平，蜂鸣器响
echo 1 > /sys/class/gpio/gpio42/value
