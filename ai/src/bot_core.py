#!/usr/bin/python3


##
## EPITECH PROJECT, 2023
## zappy
## File description:
## botclass
##

import socket

resource_requirements = {
    1: {'players': 1, 'linemate': 1, 'deraumere': 0, 'sibur': 0, 'mendiane': 0, 'phiras': 0, 'thystame': 0},
    2: {'players': 2, 'linemate': 1, 'deraumere': 1, 'sibur': 1, 'mendiane': 0, 'phiras': 0, 'thystame': 0},
    3: {'players': 2, 'linemate': 2, 'deraumere': 0, 'sibur': 1, 'mendiane': 0, 'phiras': 2, 'thystame': 0},
    4: {'players': 4, 'linemate': 1, 'deraumere': 1, 'sibur': 2, 'mendiane': 0, 'phiras': 1, 'thystame': 0},
    5: {'players': 4, 'linemate': 1, 'deraumere': 2, 'sibur': 1, 'mendiane': 3, 'phiras': 0, 'thystame': 0},
    6: {'players': 6, 'linemate': 1, 'deraumere': 2, 'sibur': 3, 'mendiane': 0, 'phiras': 1, 'thystame': 0},
    7: {'players': 6, 'linemate': 2, 'deraumere': 2, 'sibur': 2, 'mendiane': 2, 'phiras': 2, 'thystame': 1},
}

class BotCore:
    def __init__(self):
        self.connected_nbr = None
        self.vision = [[] * 4]
        self.inventory = {
            'food' : 3,
            'linemate': 0,
            'deraumere': 0,
            'sibur': 0,
            'mendiane': 0,
            'phiras': 0,
            'thystame': 0
        }
        self.id = None
        self.id_message = 0
        self.list_of_id_team = {}
        self.incantationLvl = 1
        self.orientation = 1
        self.level = 1
        self.isKing = True
        self.command_queue = []
        self.count = 20
        self.position = None
        self.dimensions = []
        self.client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.machine = None
        self.portnbr = None
        self.forking_times = 0
        self.team = None
        self.team_inventory = {
            'linemate': 0,
            'deraumere': 0,
            'sibur': 0,
            'mendiane': 0,
            'phiras': 0,
            'thystame': 0
        }
        self.to_connect = 0
        self.isIncatation = False
        self.IncantationReady = False

    def add_command(self, command):
        if len(self.command_queue) < 10:
            self.command_queue.append(command)
        # else:
        #     self.command_queue_waiting.append(command)

    def queue_changer(self):
        if self.command_queue_waiting:
            self.command_queue.append(self.command_queue_waiting[0])
            self.command_queue_waiting.pop(0)

