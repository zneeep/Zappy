#!/usr/bin/python3

##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## bot_behavior
##

from ai.src.bot_functions import BotFunctions
import random

class BotBehavior(BotFunctions):

    def count_ressources(self, ressource, x , y):
        count = 0
        tile = str(self.vision[0][x][y]).split()
        for i in range(len(tile)):
            if (ressource in tile[i]):
                count += 1
        return count

    def search_ressource(self, ressource):
        self.send_command("Look\n")
        for i in range(0, len(self.vision[0])):
            for j in range(0, len(self.vision[0][i])):
                if ressource in self.vision[0][i][j]:
                    return i, (j - i)
        return self.dimensions[0] + 1, self.dimensions[1] + 1
    
    def reach_ressource(self, ressource):
        x, y = self.search_ressource(ressource)
        if (x == self.dimensions[0] + 1):
            random_number = random.randint(1, 2)
            if (random_number == 1):
                self.send_command("Right\n")
            if (random_number == 2):
                self.send_command("Forward\n")
            return
        while x != 0:
            self.send_command("Forward\n")
            x -= 1
        if y > 0:
            self.send_command("Right\n")
            while y != 0:
                self.send_command("Forward\n")
                y -= 1
        elif y < 0:
            self.send_command("Left\n")
            while y != 0:
                self.send_command("Forward\n")
                y += 1
        x, y = self.search_ressource(ressource)
        if x == 0 and y == 0:
            return True
        return False
    
    def get_ressource(self, ressource):
        x, y = self.search_ressource(ressource)
        if (x == self.dimensions[0] + 1):
            random_number = random.randint(1, 2)
            if (random_number == 1):
                self.send_command("Right\n")
            if (random_number == 2):
                self.send_command("Forward\n")
            return
        while x != 0:
            self.send_command("Forward\n")
            x -= 1
        if y > 0:
            self.send_command("Right\n")
            while y != 0:
                self.send_command("Forward\n")
                y -= 1
        elif y < 0:
            self.send_command("Left\n")
            while y != 0:
                self.send_command("Forward\n")
                y += 1
        message = "Take " + ressource + "\n"
        return self.send_command(message)

    def check_incantation(self):
        ## MAJ pour les différents niveaux
        if self.incantationLvl == 2 and (self.team_inventory["linemate"] >= 1 
        and self.team_inventory["deraumere"] >= 1 and self.team_inventory["sibur"] >= 1):
            return True
        elif self.incantationLvl == 3 and (self.team_inventory["linemate"] >= 2 
        and self.team_inventory["phiras"] >= 2 and self.team_inventory["sibur"] >= 1):
            return True
        elif self.incantationLvl == 4 and (self.team_inventory["linemate"] >= 1 
        and self.team_inventory["deraumere"] >= 1 and self.team_inventory["sibur"] >= 2 and self.team_inventory["phiras"] >= 1):
            return True
        elif self.incantationLvl == 5 and (self.team_inventory["linemate"] >= 1 
        and self.team_inventory["deraumere"] >= 2 and self.team_inventory["sibur"] >= 1 and self.team_inventory["mendiane"] >= 3):
            return True
        elif self.incantationLvl == 6 and (self.team_inventory["linemate"] >= 1 
        and self.team_inventory["deraumere"] >= 2 and self.team_inventory["sibur"] >= 3 and self.team_inventory["phiras"] >= 1):
            return True
        elif self.incantationLvl == 7 and (self.team_inventory["linemate"] >= 2 
        and self.team_inventory["deraumere"] >= 2 and self.team_inventory["sibur"] >= 2 and self.team_inventory["mendiane"] >= 2
        and self.team_inventory["phiras"] >= 2 and self.team_inventory["thystame"] >= 1):
            return True
        return False

    def lvl2_protocol(self):
        if isinstance(self.inventory, dict):
            if "linemate" in self.inventory:
                if (self.reach_ressource("linemate") == True):
                    self.send_command("Incantation\n")

    def lvl3_protocol(self):
        if isinstance(self.inventory, dict):
            if (self.id == 0 or self.id == 3) and ("linemate" in self.inventory) and (self.inventory["linemate"] < 1):
                if self.get_ressource("linemate") == True:
                    self.send_broadcast(2.1)
            if (self.id == 1 or self.id == 4) and ("deraumere" in self.inventory) and (self.inventory["deraumere"] < 1):
                if self.get_ressource("deraumere") == True:
                    self.send_broadcast(2.2)
            if (self.id == 2 or self.id == 5) and ("sibur" in self.inventory) and (self.inventory["sibur"] < 1):
                if self.get_ressource("sibur") == True:
                    self.send_broadcast(2.3)
            if self.check_incantation() == True and self.id == 0:
                if isinstance(self.inventory, dict) and "food" in self.inventory and self.inventory["food"] < 10:
                    print("KING IS HUNGRY BEFORE INCATATION")
                    while self.inventory["food"] < (self.dimensions[0] / 2 + self.dimensions[1] / 2):
                        self.get_ressource("food")
                        self.send_command("Inventory\n")
                self.isIncatation = True
                print("KING READY FOR INCANTATION GATHERING")
                self.send_broadcast(1)

    def lvl4_protocol(self):
        if isinstance(self.inventory, dict):
            if (self.id == 0 or self.id == 3) and ("linemate" in self.inventory) and (self.inventory["linemate"] < 2):
                if self.get_ressource("linemate") == True:
                    self.send_broadcast(2.1)
            if (self.id == 1 or self.id == 4) and ("phiras" in self.inventory) and (self.inventory["phiras"] < 2):
                if self.get_ressource("phiras") == True:
                    self.send_broadcast(2.5)
            if (self.id == 2 or self.id == 5) and ("sibur" in self.inventory) and (self.inventory["sibur"] < 1):
                if self.get_ressource("sibur") == True:
                    self.send_broadcast(2.3)
            if self.check_incantation() == True and self.id == 0:
                if isinstance(self.inventory, dict) and "food" in self.inventory and self.inventory["food"] < 10:
                    print("KING IS HUNGRY BEFORE INCATATION")
                    while self.inventory["food"] < (self.dimensions[0] / 2 + self.dimensions[1] / 2):
                        self.get_ressource("food")
                        self.send_command("Inventory\n")
                self.isIncatation = True
                print("KING READY FOR INCANTATION GATHERING")
                self.send_broadcast(1)

    def lvl5_protocol(self):
        if isinstance(self.inventory, dict):
            if (self.id == 0 or self.id == 3) and ("linemate" in self.inventory) and (self.inventory["linemate"] < 1):
                if self.get_ressource("linemate") == True:
                    self.send_broadcast(2.1)
            if (self.id == 1 or self.id == 4) and ("deraumere" in self.inventory) and (self.inventory["deraumere"] < 1):
                if self.get_ressource("deraumere") == True:
                    self.send_broadcast(2.2)
            if (self.id == 2 or self.id == 5) and ("sibur" in self.inventory) and (self.inventory["sibur"] < 2):
                if self.get_ressource("sibur") == True:
                    self.send_broadcast(2.3)
            if (self.id == 2 or self.id == 5) and ("phiras" in self.inventory) and (self.inventory["phiras"] < 1):
                if self.get_ressource("phiras") == True:
                    self.send_broadcast(2.5)
            if self.check_incantation() == True and self.id == 0:
                if isinstance(self.inventory, dict) and "food" in self.inventory and self.inventory["food"] < 10:
                    print("KING IS HUNGRY BEFORE INCATATION")
                    while self.inventory["food"] < (self.dimensions[0] / 2 + self.dimensions[1] / 2):
                        self.get_ressource("food")
                        self.send_command("Inventory\n")
                self.isIncatation = True
                print("KING READY FOR INCANTATION GATHERING")
                self.send_broadcast(1)
    def lvl6_protocol(self):
        if isinstance(self.inventory, dict):
            if (self.id == 0 or self.id == 3) and ("linemate" in self.inventory) and (self.inventory["linemate"] < 1):
                if self.get_ressource("linemate") == True:
                    self.send_broadcast(2.1)
            if (self.id == 1 or self.id == 4) and ("deraumere" in self.inventory) and (self.inventory["deraumere"] < 2):
                if self.get_ressource("deraumere") == True:
                    self.send_broadcast(2.2)
            if (self.id == 2 or self.id == 5) and ("sibur" in self.inventory) and (self.inventory["sibur"] < 1):
                if self.get_ressource("sibur") == True:
                    self.send_broadcast(2.3)
            if (self.id == 2 or self.id == 5) and ("mendiane" in self.inventory) and (self.inventory["mendiane"] < 3):
                if self.get_ressource("mendiane") == True:
                    self.send_broadcast(2.4)
            if self.check_incantation() == True and self.id == 0:
                if isinstance(self.inventory, dict) and "food" in self.inventory and self.inventory["food"] < 10:
                    print("KING IS HUNGRY BEFORE INCATATION")
                    while self.inventory["food"] < (self.dimensions[0] / 2 + self.dimensions[1] / 2):
                        self.get_ressource("food")
                        self.send_command("Inventory\n")
                self.isIncatation = True
                print("KING READY FOR INCANTATION GATHERING")
                self.send_broadcast(1)
    def lvl7_protocol(self):
        if isinstance(self.inventory, dict):
            if (self.id == 0 or self.id == 3) and ("linemate" in self.inventory) and (self.inventory["linemate"] < 1):
                if self.get_ressource("linemate") == True:
                    self.send_broadcast(2.1)
            if (self.id == 1 or self.id == 4) and ("deraumere" in self.inventory) and (self.inventory["deraumere"] < 2):
                if self.get_ressource("deraumere") == True:
                    self.send_broadcast(2.2)
            if (self.id == 2 or self.id == 5) and ("sibur" in self.inventory) and (self.inventory["sibur"] < 3):
                if self.get_ressource("sibur") == True:
                    self.send_broadcast(2.3)
            if (self.id == 2 or self.id == 5) and ("phiras" in self.inventory) and (self.inventory["phiras"] < 1):
                if self.get_ressource("phiras") == True:
                    self.send_broadcast(2.5)
            if self.check_incantation() == True and self.id == 0:
                if isinstance(self.inventory, dict) and "food" in self.inventory and self.inventory["food"] < 10:
                    print("KING IS HUNGRY BEFORE INCATATION")
                    while self.inventory["food"] < (self.dimensions[0] / 2 + self.dimensions[1] / 2):
                        self.get_ressource("food")
                        self.send_command("Inventory\n")
                self.isIncatation = True
                print("KING READY FOR INCANTATION GATHERING")
                self.send_broadcast(1)
    def lvl8_protocol(self):
        if isinstance(self.inventory, dict):
            if (self.id == 0 or self.id == 3) and ("linemate" in self.inventory) and (self.inventory["linemate"] < 2):
                if self.get_ressource("linemate") == True:
                    self.send_broadcast(2.1)
            if (self.id == 1 or self.id == 4) and ("deraumere" in self.inventory) and (self.inventory["deraumere"] < 2):
                if self.get_ressource("deraumere") == True:
                    self.send_broadcast(2.2)
            if (self.id == 2 or self.id == 5) and ("sibur" in self.inventory) and (self.inventory["sibur"] < 2):
                if self.get_ressource("sibur") == True:
                    self.send_broadcast(2.3)
            if (self.id == 1 or self.id == 4) and ("mendiane" in self.inventory) and (self.inventory["mendiane"] < 2):
                if self.get_ressource("mendiane") == True:
                    self.send_broadcast(2.4)
            if (self.id == 2 or self.id == 5) and ("phiras" in self.inventory) and (self.inventory["phiras"] < 2):
                if self.get_ressource("phiras") == True:
                    self.send_broadcast(2.5)
            if ("thystame" in self.inventory) and (self.inventory["thystame"] < 2):
                if self.get_ressource("thystame") == True:
                    self.send_broadcast(2.6)
            if self.check_incantation() == True and self.id == 0:
                if isinstance(self.inventory, dict) and "food" in self.inventory and self.inventory["food"] < 10:
                    print("KING IS HUNGRY BEFORE INCATATION")
                    while self.inventory["food"] < (self.dimensions[0] / 2 + self.dimensions[1] / 2):
                        self.get_ressource("food")
                        self.send_command("Inventory\n")
                self.isIncatation = True
                print("KING READY FOR INCANTATION GATHERING")
                self.send_broadcast(1)
