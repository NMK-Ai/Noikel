#!/system/bin/sh
sudo echo 1 > /sys/class/gpio/gpio42/value
sudo sleep 0.1
sudo echo 0 > /sys/class/gpio/gpio42/value