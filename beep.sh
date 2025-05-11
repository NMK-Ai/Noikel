#!/system/bin/sh

GPIO=42

# 初始化 GPIO
if [ ! -e /sys/class/gpio/gpio$GPIO ]; then
  echo $GPIO > /sys/class/gpio/export
  sleep 0.1
fi

echo out > /sys/class/gpio/gpio$GPIO/direction

STATE_FILE="/data/params/d/IsEngaged"
LAST_STATE=""

while true; do
  if [ -f "$STATE_FILE" ]; then
    STATE=$(cat "$STATE_FILE")
    if [ "$STATE" != "$LAST_STATE" ]; then
      if [ "$STATE" = "1" ]; then
        echo 1 > /sys/class/gpio/gpio$GPIO/value
      else
        echo 0 > /sys/class/gpio/gpio$GPIO/value
      fi
      LAST_STATE="$STATE"
    fi
  fi
  sleep 0.1
done
