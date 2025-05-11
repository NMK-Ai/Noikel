#!/usr/bin/env python3
import os
import time
import subprocess
import cereal.messaging as messaging

def gpio_setup():
  if not os.path.exists("/sys/class/gpio/gpio42"):
    subprocess.run(["su", "-c", "echo 42 > /sys/class/gpio/export"], shell=True)
    time.sleep(0.1)
  subprocess.run(["su", "-c", "echo out > /sys/class/gpio/gpio42/direction"], shell=True)

def set_gpio(value):
  subprocess.run(["su", "-c", f"echo {value} > /sys/class/gpio/gpio42/value"], shell=True)

def main():
  gpio_setup()
  sm = messaging.SubMaster(['carControl'])

  prev_enabled = False
  while True:
    sm.update()
    enabled = sm['carControl'].enabled

    if enabled != prev_enabled:
      print(f"enabled: {enabled}")
      set_gpio(1 if enabled else 0)
      prev_enabled = enabled

    time.sleep(0.1)

if __name__ == "__main__":
  main()
