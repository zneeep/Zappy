#!/usr/bin/python3


import sys
from ai.src.bot import start_client

SERVER_IP = 'localhost'

def argument_checker():
    name = None
    port = None
    machine = 'localhost'

    for i in range(1, len(sys.argv)):
        arg = sys.argv[i]

        if arg == '-n':
            if i + 1 < len(sys.argv):
                name = sys.argv[i + 1]
            else:
                print("Error: Name argument is missing.")
                return None

        if arg == '-p':
            if i + 1 < len(sys.argv):
                port = sys.argv[i + 1]
            else:
                print("Error: Port number argument is missing.")
                return None

        if arg == '-h':
            if i + 1 < len(sys.argv):
                machine = sys.argv[i + 1]
            else:
                print("Error: Machine name argument is missing.")
                return None
    return machine, port, name

def main():
    machine, port, name = argument_checker()
    start_client(0, machine, port, name, False)

if __name__ == '__main__':
    main()