import os

BEEPER_GPIO = 42  # 替换为实际使用的 GPIO 编号

def setup_beeper():
    if not os.path.exists(f"/sys/class/gpio/gpio{BEEPER_GPIO}"):
        with open("/sys/class/gpio/export", "w") as f:
            f.write(str(BEEPER_GPIO))
    with open(f"/sys/class/gpio/gpio{BEEPER_GPIO}/direction", "w") as f:
        f.write("out")

def beep_on():
    with open(f"/sys/class/gpio/gpio{BEEPER_GPIO}/value", "w") as f:
        f.write("1")

def beep_off():
    with open(f"/sys/class/gpio/gpio{BEEPER_GPIO}/value", "w") as f:
        f.write("0")
