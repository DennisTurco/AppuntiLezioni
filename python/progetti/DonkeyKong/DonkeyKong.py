import g2d
import time
import random
from actor import Actor, Arena
import io, subprocess, sys

try:
    from plyer import notification
except:
    subprocess.call([sys.executable, "-m", "pip", "install", "plyer"])
    from plyer import notification

class GameManager(Arena):
    def __init__(self, gameGUI, size=(223, 255)):
        super().__init__(size)
        w, h = size
        self._gameGUI = gameGUI
        self.InitialSpawn()
        self.last_spawn_time = time.time()
        self.initial_time = time.time()
        
    def game_over(self):
        self._gameGUI.game_over()
    
    def game_won(self):
        self._gameGUI.game_won()
    
    def InitialSpawn(self):
        super().spawn(Wall((-5, 0), (1, 500))) # muro sx
        super().spawn(Wall((228, 0), (1, 500))) # muro dx
        super().spawn(OilBarrel())
        super().spawn(Jumpy(self))
        super().spawn(Princess())
        super().spawn(IdleBarrel((0, 70)))
        super().spawn(IdleBarrel((10, 70)))
        super().spawn(IdleBarrel((0, 60)))
        super().spawn(Donkey())
        super().spawn(Platform((88, 56), (16, 8)))
        super().spawn(Platform((104, 56), (16, 8)))
        super().spawn(Platform((120, 56), (16, 8)))
        super().spawn(Platform((0, 84), (16, 8)))
        super().spawn(Platform((16, 84), (16, 8)))
        super().spawn(Platform((32, 84), (16, 8)))
        super().spawn(Platform((48, 84), (16, 8)))
        super().spawn(Platform((64, 84), (16, 8)))
        super().spawn(Platform((80, 84), (16, 8)))
        super().spawn(Platform((96, 84), (16, 8)))
        super().spawn(Platform((112, 84), (16, 8)))
        super().spawn(Platform((128, 84), (16, 8)))
        super().spawn(Platform((144, 85), (16, 8)))
        super().spawn(Platform((160, 86), (16, 8)))
        super().spawn(Platform((176, 87), (16, 8)))
        super().spawn(Platform((192, 88), (16, 8)))
        super().spawn(Platform((16, 121), (16, 8)))
        super().spawn(Platform((32, 120), (16, 8)))
        super().spawn(Platform((48, 119), (16, 8)))
        super().spawn(Platform((64, 118), (16, 8)))
        super().spawn(Platform((80, 117), (16, 8)))
        super().spawn(Platform((96, 116), (16, 8)))
        super().spawn(Platform((112, 115), (16, 8)))
        super().spawn(Platform((128, 114), (16, 8)))
        super().spawn(Platform((144, 113), (16, 8)))
        super().spawn(Platform((160, 112), (16, 8)))
        super().spawn(Platform((176, 111), (16, 8)))
        super().spawn(Platform((192, 110), (16, 8)))
        super().spawn(Platform((208, 109), (16, 8)))
        super().spawn(Platform((0, 142), (16, 8)))
        super().spawn(Platform((16, 143), (16, 8)))
        super().spawn(Platform((32, 144), (16, 8)))
        super().spawn(Platform((48, 145), (16, 8)))
        super().spawn(Platform((64, 146), (16, 8)))
        super().spawn(Platform((80, 147), (16, 8)))
        super().spawn(Platform((96, 148), (16, 8)))
        super().spawn(Platform((112, 149), (16, 8)))
        super().spawn(Platform((128, 150), (16, 8)))
        super().spawn(Platform((144, 151), (16, 8)))
        super().spawn(Platform((160, 152), (16, 8)))
        super().spawn(Platform((176, 153), (16, 8)))
        super().spawn(Platform((192, 154), (16, 8)))
        super().spawn(Platform((16, 187), (16, 8)))
        super().spawn(Platform((32, 186), (16, 8)))
        super().spawn(Platform((48, 185), (16, 8)))
        super().spawn(Platform((64, 184), (16, 8)))
        super().spawn(Platform((80, 183), (16, 8)))
        super().spawn(Platform((96, 182), (16, 8)))
        super().spawn(Platform((112, 181), (16, 8)))
        super().spawn(Platform((128, 180), (16, 8)))
        super().spawn(Platform((144, 179), (16, 8)))
        super().spawn(Platform((160, 178), (16, 8)))
        super().spawn(Platform((176, 177), (16, 8)))
        super().spawn(Platform((192, 176), (16, 8)))
        super().spawn(Platform((208, 175), (16, 8)))
        super().spawn(Platform((0, 208), (16, 8)))
        super().spawn(Platform((16, 209), (16, 8)))
        super().spawn(Platform((32, 210), (16, 8)))
        super().spawn(Platform((48, 211), (16, 8)))
        super().spawn(Platform((64, 212), (16, 8)))
        super().spawn(Platform((80, 213), (16, 8)))
        super().spawn(Platform((96, 214), (16, 8)))
        super().spawn(Platform((112, 215), (16, 8)))
        super().spawn(Platform((128, 216), (16, 8)))
        super().spawn(Platform((144, 217), (16, 8)))
        super().spawn(Platform((160, 218), (16, 8)))
        super().spawn(Platform((176, 219), (16, 8)))
        super().spawn(Platform((192, 220), (16, 8)))
        super().spawn(Platform((0, 248), (16, 8)))
        super().spawn(Platform((16, 248), (16, 8)))
        super().spawn(Platform((32, 248), (16, 8)))
        super().spawn(Platform((48, 248), (16, 8)))
        super().spawn(Platform((64, 248), (16, 8)))
        super().spawn(Platform((80, 248), (16, 8)))
        super().spawn(Platform((96, 248), (16, 8)))
        super().spawn(Platform((112, 247), (16, 8)))
        super().spawn(Platform((128, 246), (16, 8)))
        super().spawn(Platform((144, 245), (16, 8)))
        super().spawn(Platform((160, 244), (16, 8)))
        super().spawn(Platform((176, 243), (16, 8)))
        super().spawn(Platform((192, 242), (16, 8)))
        super().spawn(Platform((208, 241), (16, 8)))
        super().spawn(Ladder((80, 211), (8, 40)))
        super().spawn(Ladder((184, 217), (8, 28)))
        super().spawn(Ladder((96, 180), (8, 36)))
        super().spawn(Ladder((32, 184), (8, 28)))
        super().spawn(Ladder((64, 144), (8, 42)))
        super().spawn(Ladder((112, 147), (8, 36)))
        super().spawn(Ladder((184, 151), (8, 28)))
        super().spawn(Ladder((168, 109), (8, 46)))
        super().spawn(Ladder((72, 115), (8, 34)))
        super().spawn(Ladder((32, 118), (8, 28)))
        super().spawn(Ladder((88, 82), (8, 36)))
        super().spawn(Ladder((184, 86), (8, 28)))
        super().spawn(Ladder((128, 54), (8, 32)))
        super().spawn(Ladder((128, 54), (8, 32)))
        super().spawn(Ladder((80, 22), (8, 64)))
        super().spawn(Ladder((64, 22), (8, 64)))

    def BarrelSpawner(self):
        # spawn del barrel
        global last_spawn_time  # Definisci last_spawn_time come variabile globale
        current_time = time.time()  # Ottieni il tempo corrente
        if current_time - self.last_spawn_time >= 3:  # Controlla se sono passati almeno 3 secondi dall'ultimo spawn
            super().spawn(Barrel())  # Effettua lo spawn di un nuovo Barrel
            self.last_spawn_time = current_time  # Aggiorna last_spawn_time al tempo attuale

class GameGUI:
    def __init__(self):
        self._game = GameManager(self)
        g2d.init_canvas(self._game.size())
        g2d.main_loop(self.tick) 

    def toast_message(self, title, message):
        notification.notify(
            title=title,
            message=message,
            app_icon=None,
            timeout=3,
        )

    def game_over(self):
        print("Game Over!")
        self.toast_message("Message", "Game Over!")
        self.restore_the_screen()

    def game_won(self):
        final_time = time.time()
        ris = round(final_time-self._game.initial_time, 2)
        print(f"You Won!/nTime: {ris} seconds")
        self.toast_message("Message", f"You Won! Time: {ris} seconds")
        self.restore_the_screen()

    def restore_the_screen(self):
        for a in self._game.actors():
            self._game.kill(a)
        time.sleep(1)
        self._game.InitialSpawn()
    
    def tick(self):
        
        self._game.BarrelSpawner()
        
        g2d.clear_canvas()
        
        g2d.draw_image_clip("C:/Users/Utente/Desktop/Ripetizioni/python/Marco/DonkeyKong/img/donkey-kong-bg.png", (0, 0), (0, 0), self._game.size())
        
        for a in self._game.actors():
            if a.sprite() != None:
                g2d.draw_image_clip("C:/Users/Utente/Desktop/Ripetizioni/python/Marco/DonkeyKong/img/donkey-kong.png", a.pos(), a.sprite(), a.size())
            else:
                pass
        
        self._game.tick(g2d.current_keys())

#TODO: remove full collision with the platform
class Jumpy(Actor):
    def __init__(self, game):
        self._game = game
        self._x, self._y = 0, 240
        self._w, self._h = 11, 15
        self._speed, self._jump = 4, -5
        self._dx, self._dy = self._speed, 0
        self._climbing = False
        
    def move(self, arena):
        keys = arena.current_keys()
        princess = barrel = platform = ladder = None
        
        base_x, base_y = self._x, self._y + self._h  # Coordinate della base del personaggio
        
        for other in arena.collisions():
            if isinstance(other, Barrel):
                barrel = other
            elif isinstance(other, Princess):
                princess = other
            elif isinstance(other, Ladder):
                ladder = other
            elif isinstance(other, Platform):
                platform = other         
        
        if platform:
            self.pos()
        
        if barrel:
            self._game.game_over()
        
        if princess:
            self._game.game_won()
        
        if platform and ladder and ("ArrowUp" in keys or "ArrowDown" in keys):
            self._climbing = True
        
        if "ArrowLeft" in keys or "ArrowRight" in keys:
            self._climbing = False

        if self._climbing:
            if not ladder:
                self._climbing = False
            elif "ArrowUp" in keys and abs(ladder.pos()[0] - self.pos()[0]) <= 4:  # Tolleranza di 4 pixel
                self._y -= self._speed
            elif "ArrowDown" in keys and abs(ladder.pos()[0] - self.pos()[0]) <= 4:  # Tolleranza di 4 pixel
                self._y += self._speed
        else:

            if platform and base_y >= platform.pos()[1] and base_x >= platform.pos()[0] and base_x <= platform.pos()[0] + platform.size()[0]:
                
                #TODO: fixhere
                # Logica per la collisione con la piattaforma
                self._y = platform.pos()[1] - self._h  # Imposta il personaggio sopra la piattaforma
                
                if self._dy >= 0:
                    self._dy = 0  # Impedisce il movimento verticale se il personaggio è sulla piattaforma
                    if "Spacebar" in keys:
                        self._dy = self._jump  # jump 

            arena_w, arena_h = arena.size()
            
            # Controllo se il personaggio è contro il bordo
            if (self._x + self._w >= arena_w) and ("ArrowRight" in keys):
                self._x = arena_w - self._w  # Impedisce al personaggio di superare il bordo destro
            elif (self._x <= 0) and ("ArrowLeft" in keys):
                self._x = 0  # Impedisce al personaggio di superare il bordo sinistro
            else:
                if "ArrowLeft" in keys:
                    self._x = (self._x - self._dx) % arena_w
                elif "ArrowRight" in keys:
                    self._x = (self._x + self._dx) % arena_w
                
            self._y = self._y + self._dy
            self._dy += 1  # gravity

    def pos(self):
        return self._x, self._y

    def size(self):
        return self._w, self._h

    def sprite(self):
        if self._climbing:
            return 126, 23
        else:
            return 183, 3

class Princess(Actor):
    def __init__(self):
        self._x, self._y = 100, 35
        self._w, self._h = 14, 21
        
    def move(self, arena):
        pass   

    def pos(self):
        return self._x, self._y

    def size(self):
        return self._w, self._h

    def sprite(self):
        return 184, 126

class Donkey(Actor):
    def __init__(self):
        self._x, self._y = 20, 55
        self._w, self._h = 39, 31
        self._swap_sprite1 = True
        self._swap_sprite2 = False
        self._swap_sprite3 = False
        self._last_sprite_change = time.time()  # Registra il tempo dell'ultimo cambio di sprite
        
    def move(self, arena):
        current_time = time.time()
        
        # Verifica se è passato 1 secondo dall'ultimo cambio di sprite
        if current_time - self._last_sprite_change >= 1:
            # Cambia lo sprite
            if self._swap_sprite1:
                self._swap_sprite1 = False
                self._swap_sprite2 = True
                self._swap_sprite3 = False
            elif self._swap_sprite2:
                self._swap_sprite1 = False
                self._swap_sprite2 = False
                self._swap_sprite3 = True
            elif self._swap_sprite3:
                self._swap_sprite1 = True
                self._swap_sprite2 = False
                self._swap_sprite3 = False
            
            # Aggiorna il tempo dell'ultimo cambio di sprite
            self._last_sprite_change = current_time  

    def pos(self):
        return self._x, self._y

    def size(self):
        return self._w, self._h

    def sprite(self):
        if self._swap_sprite1:
            self._w = 42
            return 9, 152
        elif self._swap_sprite2:
            self._w = 39
            return 158, 152
        elif self._swap_sprite3:
            self._w = 42
            return 254, 152

class Wall(Actor):
    def __init__(self, pos, size):
        self._pos = pos
        self._size = size

    def move(self, arena):
        return

    def pos(self):
        return self._pos

    def size(self):
        return self._size

    def sprite(self):
        return None

class OilBarrel(Actor):
    def __init__(self):
        self._pos = 18, 223
        self._size = 15, 25
        self._swap_sprite = False
        self._last_sprite_change = time.time()  # Registra il tempo dell'ultimo cambio di sprite

    def move(self, arena):
        current_time = time.time()
        
        # Verifica se è passato 1 secondo dall'ultimo cambio di sprite
        if current_time - self._last_sprite_change >= 0.5:
            # Cambia lo sprite
            if self._swap_sprite:
                self._swap_sprite = False
            else:
                self._swap_sprite = True
            
            # Aggiorna il tempo dell'ultimo cambio di sprite
            self._last_sprite_change = current_time

    def pos(self):
        return self._pos

    def size(self):
        return self._size

    def sprite(self):
        if self._swap_sprite:
            return 125, 256
        else:
            return 144, 256

class Platform(Wall): pass

class Ladder(Wall): pass

class Barrel(Actor):
    def __init__(self):
        self._x, self._y = 50, 75
        self._w, self._h = 12, 9
        self._speed = 1.5
        self._dx, self._dy = self._speed, 3
        self._climbing = False
        self._direction = 1  # 1 dx, -1 sx

    def move(self, arena):
        keys = arena.current_keys()
        
        final_wall = collided_wall = platform = ladder = None
        for other in arena.collisions():
            if isinstance(other, Ladder):
                ladder = other
            elif isinstance(other, Platform):
                platform = other
            elif isinstance(other, Wall):
                collided_wall = other
            elif isinstance(other, OilBarrel):
                final_wall = other
        
        if not platform and not ladder:
            self._dy += 1  # gravity
            
        
        # Probabilità del 10% di iniziare a scalare la scala
        if ladder:
            rand = random.random() < 0.1
            
        if (ladder) and (abs(ladder.pos()[1]-self.pos()[1]) <= 10):
            descending = True
        else:
            descending = False
        
        if not self._climbing and ladder and rand and descending:
            self._climbing = True
        
        if self._climbing and ladder:
            barrel_x_center = self._x + self._w / 2
            ladder_x_center = ladder.pos()[0] + ladder.size()[0] / 2
            
            # Controlla se il Barrel è al centro della scala
            if abs(barrel_x_center - ladder_x_center) < 5:
                self._y += self._speed
            else:
                self._climbing = False
        
        if collided_wall:
            self._direction *= -1 # swap direction
        elif final_wall:
            arena.kill(self)  # Rimuove il Barrel dall'arena
        elif platform and not ladder:
            other_x, other_y = platform.pos()
            if self._dy >= 0:
                self._y = other_y - self._h
                self._dy = 0
            
            if self._climbing:
                self._climbing = False
                self._direction *= -1
        
        
        arena_w, arena_h = arena.size()
        
        # Se il Barrel sta salendo, limita il movimento orizzontale solo quando è sulla scala
        if self._climbing and ladder:
            pass
        else:
            self._x = (self._x + self._dx * self._direction) % arena_w
        
        self._y = self._y + self._dy
        
    def pos(self):
        return self._x, self._y

    def size(self):
        return self._w, self._h

    def sprite(self):
        if self._climbing:
            self._w = 16
            return 96, 259
        else:
            self._w = 12
            return 66, 258

class IdleBarrel(Actor):
    def __init__(self, pos):
        self._pos = pos
        self._w, self._h = 9, 14
        
    def move(self, arena):
        pass   

    def pos(self):
        return self._pos

    def size(self):
        return self._w, self._h

    def sprite(self):
        return 113, 264

if __name__ == "__main__":
    game = GameGUI()