import keyboard
import os
import time


# pulisce e riposiziona il carattere
def print_char(x, y):
    os.system("cls")
    print(f"\033[{y};{x}H{carattere}", end="", flush=True)


x, y = 10, 5
carattere = "*"

print_char(x, y)

while not keyboard.is_pressed("esc"):
    if keyboard.is_pressed("up"):
        y = max(1, y - 1)
    elif keyboard.is_pressed("down"):
        y += 1
    elif keyboard.is_pressed("left"):
        x = max(1, x - 1)
    elif keyboard.is_pressed("right"):
        x += 1

    print_char(x, y)

    # serve una leggera pausa altrimenti il carattere si muove come flash sullo schermo
    time.sleep(0.1)
