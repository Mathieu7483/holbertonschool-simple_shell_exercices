#!/bin/bash

PID_MAX=$(cat /proc/sys/kernel/pid_max)

echo "La valeur maximale d'un PID est : $PID_MAX"
