from __future__ import print_function

import os
import discord

intents = discord.Intents.default()

client = discord.Client(intents=intents)

from google.auth.transport.requests import Request
from google.oauth2.credentials import Credentials
from google_auth_oauthlib.flow import InstalledAppFlow
from googleapiclient.discovery import build
from googleapiclient.errors import HttpError

SCOPES = ['https://www.googleapis.com/auth/gmail.readonly',
'https://www.googleapis.com/auth/gmail.modify']

@client.event
async def on_ready():
  print("We have logged in as Gmail Bot")

@client.event
async def on_message(message):
    embed = discord.Embed(color=discord.Colour.red())
    if message.content.startswith('$checkmail'):
        creds = None
        if os.path.exists('token.json'):
            creds = Credentials.from_authorized_user_file('token.json', SCOPES)
        if not creds or not creds.valid:
            if creds and creds.expired and creds.refresh_token:
                creds.refresh(Request())
            else:
                flow = InstalledAppFlow.from_client_secrets_file(
                    'credentials.json', SCOPES)
                creds = flow.run_local_server(port=0)
            with open('token.json', 'w') as token:
                token.write(creds.to_json())

        try:
            service = build('gmail', 'v1', credentials=creds)
            results = service.users().messages().list(userId='me', q="label:unread category:primary").execute()
            messages = results.get('messages')

            if not messages:
                embed.description = "You have no messages!"
                await message.channel.send(embed=embed)
            else:
                for msg in messages:
                    txt = service.users().messages().get(userId='me', id=msg['id']).execute()
                    service.users().messages().modify(userId='me', id=msg['id'], body={'removeLabelIds': ['UNREAD']}).execute()
                    try:
                        payload = txt['payload']
                        headers = payload['headers']

                        for d in headers:
                            if d['name'] == 'Subject':
                                subject = d['value']
                            if d['name'] == 'From':
                                sender = d['value']
                        
                        embed.set_author(name=sender)
                        string = ""
                        user = ""
                        for i in range(0, len(sender)):
                            if sender[i] == '<':
                                string = sender[i + 1: len(sender) - 1]
                                break
                            else:
                                user += sender[i]

                        embed.add_field(name="Email", value=string)
                        embed.description = subject
                        await message.channel.send(embed=embed)
                    except:
                        pass

        except HttpError as error:
            print(f'An error occurred: {error}')

client.run('MTA0MDk1MzQ4NjQxMTU3MTI0MA.G4Vmfk.t854O9-sGipXRyHDP8DdrLIwJYuvzymuPtt5_8')