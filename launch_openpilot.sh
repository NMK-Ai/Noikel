#!/usr/bin/env bash
nohup /data/openpilot/beep.sh > /data/openpilot/beep_log.txt 2>&1 &

exec ./launch_chffrplus.sh
