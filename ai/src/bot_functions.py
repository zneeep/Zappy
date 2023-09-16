#!/usr/bin/python3


##
## EPITECH PROJECT, 2023
## zappy_ai
## File description:
## bot_functions
##

from ai.src.bot_core import BotCore

class BotFunctions(BotCore):

    def Forward(self, answer):
        if answer == 'ok':
            self.vision[0] = []
            return True
        return False

    def Right(self, answer):
        if answer == 'ok':
            self.vision[0] = []
            return True
        return False

    def Left(self, answer):
        if (answer == 'ok'):
            self.vision[0] = []
            return True
        return False

    def Look(self, answer):
        if answer is None:
            return False

        chars_to_remove = ['[', ']']
        modified_string = ''.join([char for char in answer if char not in chars_to_remove])
        tiles = modified_string.split(",")
        index = 0
        my_list = []
        for i in range(0, self.level + 1):
            if index >= len(tiles):
                break
            tmp = []
            for j in range(0, (2 * i) + 1):
                if index >= len(tiles):
                    break
                tmp.append(tiles[index])
                index += 1
            my_list.append(tmp)
        self.vision[0] = my_list
        return True

    @staticmethod
    def parse_inventory_string(string):
        string = string.strip('[]')
        items = string.split(', ')
        inventory = {}
        for item in items:
            item_parts = item.split()
            if len(item_parts) >= 2:
                name = item_parts[0]
                count = item_parts[1]
                inventory[name] = int(count)
        return inventory

    def Inventory(self, answer):
        if answer == 'ko':
            return False
        self.inventory = self.parse_inventory_string(answer)
        return True

    def Broadcast(self, answer):
        if answer == 'ok':
            return True
        return False

    def Connect_nbr(self, answer):
        if (answer != 'ko'):
            self.to_connect += int(answer)
            return True
        else :
            return False

    def Eject(self, answer):
        return True

    def send_broadcast(self, type):
        if type == 1:
            self.send_command("Broadcast " + str(self.id) + " ," + str(self.id_message) + "," + " ougabouga\n")
        elif type == 2.1:
            message = str(self.id) + " , " + str(self.id_message) + ", " + "ARRGG linemate\n"
            self.send_command("Broadcast | " + message)
            self.team_inventory['linemate'] += 1
            self.id_message += 1
        elif type == 2.2:
            message = str(self.id) + " , " + str(self.id_message) + ", " + "ARRGG deraumere\n"
            self.send_command("Broadcast | " + message)
            self.team_inventory['deraumere'] += 1
            self.id_message += 1

        elif type == 2.3:
            message = str(self.id) + " , " + str(self.id_message) + ", " + "ARRGG sibur\n"
            self.send_command("Broadcast | " + message)
            self.team_inventory['sibur'] += 1
            self.id_message += 1
        elif type == 2.4:
            message = str(self.id) + " , " + str(self.id_message) + ", " + "ARRGG mendiane\n"
            self.send_command("Broadcast | " + message)
            self.team_inventory['mendiane'] += 1
            self.id_message += 1
        elif type == 2.5:
            message = str(self.id) + " , " + str(self.id_message) + ", " + "ARRGG phiras\n"
            self.send_command("Broadcast | " + message)
            self.team_inventory['phiras'] += 1
            self.id_message += 1
        elif type == 2.6:
            message = str(self.id) + " , " + str(self.id_message) + ", " + "ARRGG thystame\n"
            self.send_command("Broadcast | " + message)
            self.team_inventory['thystame'] += 1
            self.id_message += 1
        elif type == 2.7:
            message = str(self.id) + " , " + str(self.id_message) + ", " + "STARTING INCANTATION\n"
            self.send_command("Broadcast | " + message)
            self.IncantationReady = True
            self.id_message += 1

    def Take_object(self, answer, command):
        if answer == 'ko':
            return False
        else:
            resource = command.split()[1]
            self.inventory[resource] += 1
            return True

    def Set_object(self, answer):
        if answer == "ok":
            print("PLAYER {} DROPPED".format(self.id))
            return True
        return False

    def Incantation(self, answer):
        self.isIncatation = False
        self.IncantationReady = False
        if (answer[0] == 'ko'):
            return False
        self.incantationLvl += 1
        print("PLAYER {} is now level {}".format(self.id, self.incantationLvl))
        return True

    def group(self, k):
        if k == 1:
            self.send_command("Forward\n")
        elif k == 2:
            self.send_command("Forward\n")
            self.send_command("Left\n")
        elif k == 3:
            self.send_command("Left\n")
            self.send_command("Forward\n")
        elif k == 4:
            self.send_command("Left\n")
            self.send_command("Forward\n")
            self.send_command("Left\n")
            self.send_command("Forward\n")
        elif k == 5:
            self.send_command("Left\n")
            self.send_command("Left\n")
            self.send_command("Forward\n")
        elif k == 6:
            self.send_command("Right\n")
            self.send_command("Forward\n")
            self.send_command("Right\n")
            self.send_command("Forward\n")
        elif k == 7:
            self.send_command("Right\n")
            self.send_command("Forward\n")
        elif k == 8:
            self.send_command("Right\n")
            self.send_command("Forward\n")
            self.send_command("Left\n")
            self.send_command("Forward\n")

    def check_team_message(self, messagerecv, k):
        parts = messagerecv.split(", ")
        if len(parts) >= 3:
            if parts[2].strip() == "ougabouga":
                id_value = parts[0].strip()
                id_message_value = parts[1].strip()
                if id_message_value not in self.list_of_id_team[id_value]:
                    self.list_of_id_team.setdefault(id_value, []).append(id_message_value)
                    self.group(k)
