#!/usr/bin/python3

from ai.src.bot_behavior import BotBehavior
import multiprocessing
import re


def count_pattern_occurrences(string, pattern):
    regex = re.compile(pattern)
    matches = regex.findall(string)
    return len(matches)

class Bot(BotBehavior):

    def Fork(self, answer):
        if (answer != "ko"):
            self.forking_times += 1
            return True
        else:
            return False
    
    def exec_command(self, command, answer):
        if ("Broadcast" in command):
            return self.Broadcast(answer)
        if ("Take" in command):
            return self.Take_object(answer, command)
        if (command == 'Forward\n'):
            return self.Forward(answer)
        if (command == 'Right\n'):
            return self.Right(answer)
        if (command == 'Left\n'):
            return self.Left(answer)
        if (command == 'Look\n'):
            return self.Look(answer)
        if (command == 'Inventory\n'):
            return self.Inventory(answer)
        if (command == 'Set object\n'):
            return self.Set_object(answer)
        if (command == 'Connect_nbr\n'):
            return self.Connect_nbr(answer)
        if (command == 'Incantation\n'):
            return self.Incantation(answer)
        if (command == 'Fork\n'):
            return self.Fork(answer)
        if (command == 'Connect_nbr\n'):
            return self.Connect_nbr(answer)
        if ("Set" in command):
            return self.Set_object(answer)

    def decrypte_message(self, message):
        if message == "dead":
            print("PLAYER {} DIED".format(self.id))
            self.client_socket.close()
            exit()
        elif "Current level" in message:
            self.Incantation(message)
        elif "INCANTATION" in message:
            print("PLAYER {} RECEIVED MESSAGE FOR INCANTATION".format(self.id))
            pattern = r"(\d+)\W+(\d+)\W+(\d+)\W+(.+)"
            matches = re.findall(pattern, message)
            if int(matches[0][1]) == 0:
                self.k = int(matches[0][0])
            else:
                self.k = 'Not king'
            self.list_of_id_team[int(matches[0][1])] = int(matches[0][2])
            message = matches[0][3].strip().split(" ")[1]
            self.IncantationReady = True
        elif "ARRGG" in message:
            pattern = r"(\d+)\W+(\d+)\W+(\d+)\W+(.+)"
            matches = re.findall(pattern, message)
            if int(matches[0][1]) == 0:
                self.k = int(matches[0][0])
            else:
                self.k = 'Not king'
            self.list_of_id_team[int(matches[0][1])] = int(matches[0][2])
            message = matches[0][3].strip().split(" ")[1]
            self.team_inventory[message] += 1
        elif "ougabouga" in message:
            pattern = r"(\d+)\W+(\d+)\W+(\d+)\W+(.+)"
            matches = re.findall(pattern, message)
            if int(matches[0][1]) == 0:
                self.k = int(matches[0][0])
            else:
                self.k = 'Not king'
            self.isIncatation = True

    def check_answer(self, answers):
        for i in range(len(answers)):
            if "message" not in answers[i] and len(answers[i]) > 0:
                return answers[i]
            elif "message" in answers[i] and len(answers[i]) > 1 or "dead" in answers[i]:
                self.decrypte_message(answers[i])
        return None

    def recv_until_newline(self):
        message = ''
        while '\n' not in message:
            chunk = self.client_socket.recv(1024).decode()
            if not chunk:
                break
            message += chunk
        answers = message.split('\n')
        return answers

    def handle_incantation(self, answer, command):
        if command == "Incantation\n":
            if answer[0] == "ko":
                self.exec_command(command, answer)
                return
            else:
                answer = self.recv_until_newline()
                while (self.check_answer(answer) == None):
                    answer = self.recv_until_newline()
        return answer

    def send_command(self, command):
        self.client_socket.send(command.encode('utf-8'))
        self.add_command(command)
        answer = self.recv_until_newline()
        while self.check_answer(answer) == None:
            answer = self.recv_until_newline()
        answer = self.check_answer(answer)
        if (answer == "Elevation underway"):
            command = "Incantation\n"
        answer = self.handle_incantation(answer, command)
        return self.exec_command(command, answer)

    def initialize_machine(self, machine, portnbr, team):
        self.machine = machine
        self.portnbr = portnbr
        self.team = team

    def set_variables(self, message, nb, isFork):
        lines = message.split('\n')
        self.id = nb
        if (lines[0] == 'ko') or (lines[0] == '0' and isFork == False):
            exit()
        self.connected_nbr = int(lines[0])
        self.forking_times = self.connected_nbr
        numbers = [int(num) for num in lines[1].split()]
        self.dimensions.append(numbers[0])
        self.dimensions.append(numbers[1])
    
    def connect_to_server(self):
        self.client_socket.connect((self.machine, int(self.portnbr)))
        message = self.client_socket.recv(1024).decode()
        message = self.team + '\n'
        self.client_socket.send(message.encode())
        message = self.client_socket.recv(1024).decode('utf-8')
        return message

    def king_role(self):
        if self.forking_times < 6:
            self.send_command("Fork\n")
        self.send_command("Connect_nbr\n")
        if self.to_connect > 0:
            process = multiprocessing.Process(target=start_client, args=(self.connected_nbr, self.machine, self.portnbr, self.team, True))
            process.start()
            self.to_connect -= 1
            self.connected_nbr += 1

    def level_up(self):
        if (self.id == 0 and self.connected_nbr < 6 and self.incantationLvl == 2):
            return
        if self.incantationLvl == 1:
            self.lvl2_protocol()
        elif self.incantationLvl == 2:
            self.lvl3_protocol()
        elif self.incantationLvl == 3:
            self.lvl4_protocol()
        elif self.incantationLvl == 4:
            self.lvl5_protocol()
        elif self.incantationLvl == 5:
            self.lvl6_protocol()
        elif self.incantationLvl == 6:
            self.lvl7_protocol()
        elif self.incantationLvl == 7:
            self.lvl8_protocol()

    def drop_ressources(self):
        for key, value in self.inventory.items():
            i = value
            command = "Set " + key + "\n"
            if (key != "food"):
                while i != 0:
                    if self.send_command(command) == True:
                        i -= 1
                        self.inventory[key] -= 1
                        print("Player {} Dropped {}".format(self.id, key))

    def check_for_incantation(self):
        self.send_command("Look\n")
        if (self.count_ressources("player", 0, 0) == 6 and self.count_ressources("linemate", 0, 0) >= 1 and self.count_ressources("sibur", 0, 0) >= 1 and self.count_ressources("deraumere", 0, 0) >= 1):
            print("KING SEES {} SO TEAM READY FOR INCANTATION".format(self.vision[0]))
            self.IncantationReady = True
            self.send_broadcast(2.7)
            return True
        return False

    def incantation_time(self):
        if self.id == 0:
            self.drop_ressources()
            self.send_broadcast(1)
            if self.check_for_incantation() == True:
                self.send_command("Incantation\n")
        elif isinstance(self.inventory, dict) and "food" in self.inventory and self.inventory["food"] < 10:
            while self.inventory["food"] < 10:
                self.get_ressource("food")
                self.send_command("Inventory\n")
        else:
            if self.k != 0:
                if (self.inventory["food"] < 5):
                    while(self.inventory["food"] < 8):
                        self.get_ressource("food")
                        self.send_command("Inventory\n")
                self.send_command("Look\n")
                if self.k != "Not king" and self.k != 0:
                    self.group(self.k)
                    message = self.recv_until_newline()
                    print("MESSAGE FOR {} AFTER GROUPING {}".format(self.id, message[0]))
                    self.decrypte_message(message[0])
            elif self.k == 0:
                if self.IncantationReady == False:
                    self.drop_ressources()
                    if self.inventory["food"] < 5:
                        self.send_command("Take food\n")
                    message = self.recv_until_newline()
                    self.decrypte_message(message[0])
                if self.IncantationReady == True:
                    message = self.recv_until_newline()
                    if (message[0] != ''):
                        print("PLAYER {} WAITED FOR AND RECEIVED {}".format(self.id, message[0]))
                        self.decrypte_message(message[0])

    def play_game(self):
        if self.isIncatation == False:
            self.send_command("Inventory\n")
            if isinstance(self.inventory, dict) and "food" in self.inventory and self.inventory["food"] < 4:
                while self.inventory["food"] < 7:
                    self.get_ressource("food")
                    self.send_command("Inventory\n")
            elif (self.id == 0 and self.connected_nbr < 6):
                self.king_role()
                return
            else:
                self.level_up()
        elif self.isIncatation == True:
            self.incantation_time()

def start_client(nb, machine, portnbr, team, isFork):
    player = Bot()
    print("Starting client : ID = {}, TEAM = {}, FORK = {}".format(nb, team, isFork))

    player.initialize_machine(machine, portnbr, team)
    message = player.connect_to_server()
    player.set_variables(message, nb, isFork)

    if player.connected_nbr >= 2 and isFork == False:
        process = multiprocessing.Process(target=start_client, args=(player.id + 1, machine, portnbr, team, False))
        process.start()

    print("CURRENT PLAYER ID = ", player.id)

    if (player.id == 0):
        player.isKing = True

    while True:
        player.play_game()
