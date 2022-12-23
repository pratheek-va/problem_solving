import discord
import os
from mail import Mail

intents = discord.Intents.default()

client = discord.Client(intents=intents)

@client.event
async def on_ready():
  print("We have logged in as Gmail Bot")

@client.event
async def on_message(message):
  if message.content.startswith('$hello'):
    await message.channel.send("hello")
  if message.content.startswith('$check mail'):
    mail = Mail("imap.gmail.com", "pratheekvaberike@gmail.com", "oqnjzntlrzvxtmma")
    my_messages = mail.get_inbox()
    for mes in my_messages:
        await message.channel.send(mes['subject'][:2000])
    
client.run('MTA0MDk1MzQ4NjQxMTU3MTI0MA.G4Vmfk.t854O9-sGipXRyHDP8DdrLIwJYuvzymuPtt5_8')