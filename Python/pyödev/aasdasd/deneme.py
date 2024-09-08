""""
In modern era, managing your project according to customer expectation is crucial. Nowa- days whatever you do is recorded, transformed to a form of data and stored or processed to benefit from you better. In this mini project, you are going to create your own Pokemon game and collect the data from players; then store, process and analyze it. Does that sound ethical? Well, it doesn’t matter in modern world!
How should it look like?
Graphical user interface is a bit detailed in this project, it is going to consist of more than one layout. So let’s advance step by step.
How should it work:
In our Pokemon game, main game flow consists of the battle of two players. If you have ever played any Pokemon game before, it will seem pretty familiar, of course a bit simplified.
In Pokemon games, two Pokemons battle at once, and battles are performed as turn based, which means one player moves first then it becomes the other player’s turn to move, just like in chess.
The picture shows the war screen, which is the scene that battle between two Pokemons 1
 will occur. Two players will choose their Pokemons and after selection player 1 will move first. Players can choose two different attack types, first one is physical, which is the more consistent one, second one is elemental, which is the less consistent but high risk - high reward type of move.
Each Pokemon will have it’s own element type and this element type will matter in battles if players prefer using elemental attacks. Fire is stronger than nature and water is stronger than fire etc.
But before going this far, let’s start from the very beginning, from getting the data of the Pokemons.
1. If you are familiar with the Pokemon culture, there are hundreds of Pokemons in the Pokemon universe. Also every Pokemon has an element, a sub element, generation, some of them are legendary etc. so as you can see there are too many details for a simple child play. In this project, we are going to simplify things a lot and use only the data we needed. So first, see the figure below, which is the Pokemon.csv file that we are going to give you to do some data cleaning on it, we are going to need only 18 of them for this game.
In our game, rules are simple: two Pokemons fight, one that finishes enemy’s health faster wins. So Pokemons are going to have only those attributes: Name, Element type, HP and attack values. From the given Pokemon database, you will drop all
2

 other columns.
Also the 18 Pokemons we are going to use are given below, drop all others:
• Bulbasaur
• Ivysaur
• Venusaur
• Charmander • Charmeleon • Charizard
• Squirtle
• Wartortle • Blastoise • Caterpie • Metapod • Butterfree
3

• Weedle
• Kakuna
• Beedrill
• Pidgey
• Pidgeotto • Pidgeot
After this data cleaning done, your new and clean dataset should seem like this:
Use pandas for this task and write the clean database to a csv file.
You are going to use these Pokemon data in game, when players choose their Pokemons, their attributes will be taken from this file.
4
 
2. After getting the clean dataset, now we are ready to build the GUI for the game flow.
First, players needs to choose their Pokemons, so we are going to need a Pokemon selection screen. Here you can build your own beautiful GUIs but it doesn’t need to be too much detailed, or specifically the same with the selection screen system below, just create something that will do the task, which is just the selection of Pokemons.
Above you see the selection window for Player 1, player 1 will going to choose the name of Pokemon from the ListBox and then see the image of the Pokemon in the question marked place.
Image will change when player click any of the Pokemons in the ListBox. When player 1 decides the Pokemon he wants, then needs to click Choose button and then selection window for player 2 will appear.
5
  
  6

Above figures you see only 6 Pokemons for each player, but cleaned dataset had 18 of them? Where are the rest 12 Pokemons?
If you are not familiar with Pokemon universe, pokemons can evolve as they grow up or fight and get stronger. In the dataset we cleaned actually has 6 different Pokemons, and every Pokemons has their evolution level 2 and 3. In the battles, the Pokemon who won the round will get evolved and both it’s attributes and image will change. So other 12 Pokemon will appear in the next phases of the battles.
After both players choose their Pokemons, battle will begin.
3. Battles are performed turn based, one player hits and after him other player hits. So be sure when it’s one player’s turn, other player has to wait and can not attack.
In the figure as you see, since it’s Player 1’s turn (Player 1 starts the game) buttons of Player 2 are disabled.
Players have two options: physical attack and elemental attack. Difference of physical and elemental attack is like as follows:
• Physical: Can give damage between 75%-100% of Pokemon’s attack value.
• Elemental: Can give damage between 50%-100% of Pokemon’s attack value, if attacker is elementally stronger than defender Pokemon, damage will be doubled with a 80% chance.
Here you need to add the functionality to buttons, they will do the calculations of attack 7
 
and decrease the HP of opponent, and visually represent it on the screen. Health bars of Pokemons will be updated after every attack.
See the sample screenshots of the battles below:
If any of player lose, an infobox should appear: 8
   
  Here you need to implement evolution mechanic, loser will choose a pokemon again but winner will not choose a new pokemon, instead winner will have the same pokemon but evolved version of it. See the example of evolution below:
First Player 1 starts with Squirtle and Player 2 starts with Charmander:
9
 
Then Player 1 wins and gets evolved, since squirtle evolves to Wartortle, now he is Wartortle and player 2 chooses a new pokemon.
Finally in the round 3, since player 1 won again, he got his last evolution and Wartortle became a Blastoise and player 2 choose a new pokemon:
Also see player’s scores, player 1’s score increases every round but player 2’s don’t, when a player wins and gets evolved, his score increases. Who reaches to 3 first wins the whole game.
Here the logic is, winner gets evolved and gets stronger, but if he loses, he loses evolution and again chooses a level 1 pokemon. So if a player wants to be successful, he should be careful that he doesn’t break the win streak, so gets evolved again and again, then win easily. Dont forget we only have 3 levels of pokemons; level 1 we choose from the listbox, if he wins once it gets level 2 and if wins again he gets level 3.
10
  
Before a new round begins, evolved player should revive with %70 of his max health, or it will be impossible to beat evolved pokemon.
When a player reaches score 3, game should end and an infobox should appear:
If game flow seemed confusing, definitely watch the video about the game flow, see how it should be implemented.
4. We assume battles are handled so far. In the last part, we are going to do data analysis. But instead of doing this on some random toy datasets, we are going to create our very own and do data analysis on it.
As Players play the game and do the battles, we are going to collect data from the game and see players’ performances. We will create a dataframe with those data and then do data visualisation on it.
After every attack, collect those data and store in some array or list: 11
  
• Name of the attacker Pokemon
• Dealt damage value to opponent
• Remaining healt value of opponent
• Was attack a critical hit or not (boolean data or 0’s and 1’s)
• Was attack an elemental attack or not (boolean data or 0’s and 1’s)
At the end of the battle, all those data needs to be collected. When battle ends, by using these data, create a dataframe and write it to an excel file. Final excel file should be something like this:
Now we have our very own dataset, now it’s time to do some data visualisation!
5. Finally, in the last part, you are going to come up with the graphics of Damage, Health and Crit columns’ data. Crit graph will be a bar graph and it will show every name of pokemon played in game and how many times did they hit a critical attack.
You can put all the plots in a single window or show them separately, an example of the graphs are given below:
12
 
 Implementation Notes:
• We highly recommend you to use classes in this project, they can lower your burden a lot and make it easier to manage this comprehensive project. For example you can use a pokemon class, a gui class to manage tkinter and other classes that can make it easier to manage the code.
• Images in tkinter can be so annoying and hard to manage and use, so if you face problems when you deal with images, don’t worry, you don’t have to use images at all, but if you do, it will be appreciated.
• Apart from the above, the lecture slides are enough for most parts, still feel free to research and implement. Please provide references if you use outer sources. Tutori- alsPoint, StackOverflow and Effbot might be good starting points, but do not copy codes directly.

"""

import pandas as pd
import numpy as np
import random
import tkinter as tk
from tkinter import messagebox

# Read the data
data = pd.read_csv('deneme.csv')

# Drop the unnecessary columns

data = data.drop(['#', 'Type 1', 'Type 2', 'Total', 'HP', 'Attack', 'Defense', 'Sp. Atk', 'Sp. Def', 'Speed', 'Generation', 'Legendary'], axis=1)

# Drop the unnecessary rows

data = data.drop(data.index[18:])
data = data.drop(data.index[6:11])

# Write the clean data to a new csv file

data.to_csv('Pokemon_cleaned.csv', index=False)

# Create the main window

root = tk.Tk()
root.title('Pokemon Game')
root.geometry('800x600')

# Create the selection window

class SelectionWindow:
    def __init__(self, master, player):
        self.master = master
        self.player = player
        self.pokemon_list = data['Name'].tolist()
        self.pokemon = tk.StringVar()
        self.pokemon.set(self.pokemon_list[0])
        self.index = 0
        self.create_widgets()

    def create_widgets(self):
        self.label = tk.Label(self.master, text=f'Player {self.player}, choose your Pokemon:')
        self.label.pack()

        self.listbox = tk.Listbox(self.master, height=6, width=20)
        for pokemon in self.pokemon_list:
            self.listbox.insert(tk.END, pokemon)
        self.listbox.pack()

        self.listbox.bind('<<ListboxSelect>>', self.on_select)

        self.image = tk.Label(self.master, text='?', font=('Arial', 50))
        self.image.pack()

        self.choose_button = tk.Button(self.master, text='Choose', command=self.choose)
        self.choose_button.pack()

    def on_select(self, event):
        self.index = self.listbox.curselection()[0]
        self.pokemon.set(self.pokemon_list[self.index])
        self.show_image()

    def show_image(self):
        self.image.config(text=self.pokemon_list[self.index])

    def choose(self):
        if self.player == 1:
            self.master.destroy()
            selection_window_2 = SelectionWindow(root, 2)
        else:
            self.master.destroy()
            battle_window = BattleWindow(root, selection_window_1.pokemon_list[selection_window_1.index], selection_window_2.pokemon_list[selection_window_2.index])
            
            
# Create the battle window

class BattleWindow:
    def __init__(self, master, pokemon_1, pokemon_2):
        self.master = master
        self.pokemon_1 = pokemon_1
        self.pokemon_2 = pokemon_2
        self.hp_1 = 100
        self.hp_2 = 100
        self.create_widgets()

    def create_widgets(self):
        self.label_1 = tk.Label(self.master, text=f'{self.pokemon_1} HP: {self.hp_1}')
        self.label_1.pack()

        self.label_2 = tk.Label(self.master, text=f'{self.pokemon_2} HP: {self.hp_2}')
        self.label_2.pack()

        self.button_1 = tk.Button(self.master, text='Physical Attack', command=self.physical_attack)
        self.button_1.pack()

        self.button_2 = tk.Button(self.master, text='Elemental Attack', command=self.elemental_attack)
        self.button_2.pack()

    def physical_attack(self):
        damage = random.randint(75, 100)
        self.hp_2 -= damage
        self.label_2.config(text=f'{self.pokemon_2} HP: {self.hp_2}')
        if self.hp_2 <= 0:
            messagebox.showinfo('Result', f'{self.pokemon_1} wins!')
            self.master.destroy()

    def elemental_attack(self):
        damage = random.randint(50, 100)
        if self.pokemon_1 == 'Fire' and self.pokemon_2 == 'Grass':
            damage *= 2
        elif self.pokemon_1 == 'Grass' and self.pokemon_2 == 'Water':
            damage *= 2
        elif self.pokemon_1 == 'Water' and self.pokemon_2 == 'Fire':
            damage *= 2
        self.hp_2 -= damage
        self.label_2.config(text=f'{self.pokemon_2} HP: {self.hp_2}')
        if self.hp_2 <= 0:
            messagebox.showinfo('Result', f'{self.pokemon_1} wins!')
            self.master.destroy()
            
# Create the selection windows

selection_window_1 = SelectionWindow(root, 1)
root.mainloop()





