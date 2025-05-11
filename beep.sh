#!/system/bin/sh
echo 1 > /sys/class/gpio/gpio42/value
sleep 0.1
echo 0 > /sys/class/gpio/gpio42/value