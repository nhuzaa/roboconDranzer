import getpass
import sys
import telnetlib
import time

user = "pi"
password = "raspbeery"

bot = telnetlib.Telnet("192.168.0.104")
bot.read_until("login:")
bot.write(user + "\n")
bot.read_until("password:")
bot.write(password + "\n")

