import keyboard
import os
import time

# Posizione iniziale del carattere
x, y = 10, 5
carattere = '*'

def print_char(x, y):
    print(f"\033[{y};{x}H{carattere}", end='', flush=True)

# Pulisce e riposiziona
os.system('cls')
print_char(x, y)

while not keyboard.is_pressed('esc'):
    if keyboard.is_pressed('up'):
        y = max(1, y-1)
    elif keyboard.is_pressed('down'):
        y += 1
    elif keyboard.is_pressed('left'):
        x = max(1, x-1)
    elif keyboard.is_pressed('right'):
        x += 1
    
    # Pulisce e riposiziona
    os.system('cls')
    print_char(x, y)
    
    time.sleep(0.05)  # evita di usare troppa CPU
