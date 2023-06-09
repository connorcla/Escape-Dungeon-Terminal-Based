[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10871820&assignment_repo_type=AssignmentRepo)
 
# Escape Dungeon

 > Authors: \<[Gabriel Vasquez](https://github.com/GoodfellaGabe)\>
	\<[Connor Claborn](https://github.com/connorcla)\>
	\<[Eliot Lee](https://github.com/swooshoo)\>
		\<[Jonathoon Hoang](https://github.com/Janathoon)\>

## Project Description
### General Description
This program is a terminal and text based role playing game in which players can choose their character in order to enter and progress through a dungeon and get out safely. The player will start with minimal equipment and is forced to trek through a mysterious and unknown labyrinth navigating from room to room in order to get to the exit. Through this dungeon, the player will be able to obtain items to increase their chances of survival through tools to navigate through the dungeon better and weapons to face off against enemies that lurk in the dark. The player will have to fight through enemies with items and experience gained in order to travel from room to room, uncovering why they are there and to eventually escape.

### Why it is important or interesting?
A lot of software today is involved in some sort of entertainment with a large market in the realm of digital gaming. These games are defined by unique and complex systems or mechanics that make them stand out from other forms of entertainment in addition to immersion as the player is in full control of their character, acting as they like in game. This will be a project that will bring enjoyment to others as they are able to run and play our program, taking a new path each time they enter the dungeon, and experiencing their adventure once more.

### Languages/Tools/Technologies
**C++**: This is the main language this project will be programmed in.

**VSCode**: Visual Studio Code is the IDE and text editor that will be used to write and test code in.

**Git**: Git allows us to work collaboratively on this project by maintaining a version control system, make and edit branches for new features, and commit to a central repository.  

**GitHub**: GitHub is a central area located on an accessible server to visualize our version control system. This will allow for better organization in our collaboration by creating project boards in order to assign tasks which will be completed individually and added together in the GitHub repository. 

**Valgrind**: Used as a debugging tool, Valgrind helps detect memory leaks, find uninitialized memory, and profile memory usage. With the development of a game project, this is important to manage quickly growing memory and detect unpredictable behavior & crashes.Profiling memory usage allows to identify areas where memory should be optimized or reduced.

**CMake**: Allows us as developers to specify build processes, manage dependencies, and organize our project’s source code. In the context of an RPG game, it could help manage any external libraries we may use and specify build types for debugging purposes. Seeing that the project is also a collaborative project, CMake’s ability to organize the source code into logical modules makes it easier to manage the scale of the project 

### Input/Output of Project?
**Input**: A user will be prompted by Terminal to select menu options (i.e. “1-Talk to the tavern owner, 2 - Open quest log, 3- Open inventory) etc.) The story will progress differently and the user may pick alternate endings depending on the user’s inputs (i.e. failing to use a heal item when needed could result in character death). 

**Output**: The output will be on Terminal such as dialogue, storyline, menu options for the next user input, and maybe even combining symbols to create backgrounds or characters.

### Project Features
Players should be able to select and/or create their character they want to use to navigate through the dungeon. They will be able to view and manage their player’s statistics and choose which skills to increase or level up as the game progresses. Along with this character management, heal and magic counters will be shown to let the player know of any available resources as well as menus showing different options or actions their player can take.

As players navigate through the dungeon, they  will be able to access and view a map of the dungeon including the rooms visited, any significant characters, and any unchecked rooms. Players can choose which direction to explore in and can investigate or use different actions around rooms prompting different responses. By navigating, players can find other characters that can help them on their journey, or give them information about the place they are attempting to escape from.

Through their journey players can obtain and use items that will aid them in fights or navigating through the rooms. Items will be obtained by defeating enemies or finding special rooms and can be viewed in an inventory. These items will be able to be used either in battle against enemies or in the map in order to aid in navigating.

Players will come across enemies during their journey which will be prompted by either entering or performing certain actions in rooms. Fighting enemies will prompt a special battle menu that will provide players several options including attack, defend, or use an item. Players will have to defeat all enemies and will be rewarded upon doing so.


## User Interface Specification

### Navigation Diagram
![Navigation Diagram](Documents/CS100_FinalProject_NavigationDiagram.png)

### Screen Layouts

Document for Screen Layouts: [Link to Screen Layouts](Documents/CS100_FinalProject_ScreenLayout.pdf)

__Main Menu:__
_____________________________________________________________________________________________________________________________
Escape Dungeon

Can you:
<br>Build your arsenal, 
<br>Battle through enemies,
<br>Reach the end before you are stopped?

Enter your name to begin:
_____________________________________________________________________________________________________________________________


<br><br>__Idle Room:__
_____________________________________________________________________________________________________________________________
You find yourself in a damp room and nothing seems to be moving except the flicker of the torches on the walls.

What would you like to do?
1. Look around the room for any items
2. Examine the room
3. View inventory
4. View map
5. Move to the next room

Enter your choice (1-5): 
_____________________________________________________________________________________________________________________________


<br><br>__Map:__
<br>Will update rooms as player progress through the game
_____________________________________________________________________________________________________________________________
Current Map: 
<br>A map that you were gripping when you woke up. 
<pre>
<br>______________________________________________________________________________________________________________
<br>|         |         |         |        |           |           |           |           |           |         |
<br>|  Start  |  Clear  |  Clear  |  Here  |     ?     |     ?     |     ?     |     ?     |     ?     |   Exit? |
<br>|         |         |         |        |           |           |           |           |           |         |
<br>______________________________________________________________________________________________________________
</pre>

<br>Start: Where you woke up and began your journey.
<br>Clear: All enemies have been vanquished from there, there’s no use going back.
<br>Here: You are currently in this room.
<br>?: Unexplored rooms, wonder what lies ahead.
<br>Exit?: Marked as a possible escape, hopefully this map tells the truth.

Enter (b) to stop viewing your map: 
_____________________________________________________________________________________________________________________________


<br><br>__Inventory:__
<br>Item[x] will be replaced with item names. Items will be alphabetically sorted. 
<br>Equip Slots will be filled with the number corresponding to the item that is equipped.
_____________________________________________________________________________________________________________________________
Satchel:
 1. Item[1]     2. Item[2]     3. Item[3]     4. Item[4]     5. Item[5]
 6. Item[6]     7. Item[7]     8. Item[8]     9. Item[9]     10. Item[10]  
  …
Equip Slots:

|  1  |      |  2  |      |  3  |

Enter item number (1-[numItems]) to view that item or enter 0 to see your stats:
_____________________________________________________________________________________________________________________________


<br><br>__Player Stats:__
<br>Numbers will change depending on the player's choices and progress through the game.
_____________________________________________________________________________________________________________________________
Your Current Statistics:

Maximum Health: 50
<br>Maximum Magic: 50
<br>Attack: 10
<br>Defense: 10
<br>Speed: 10
<br>EXP: 35

You can increase any statistic by 1 point by spending 10 EXP.
<br>Enter which statistic you wish to increase (H,M,A,D,S) or enter (b) to go back to satchel: 
_____________________________________________________________________________________________________________________________


<br><br>__Battle Menu:__
<br>Enemy[x] will be replaced with enemy names.
<br>List of enemy actions will appear after the player has made their choice, then the menu will reset and the player will be able to choose their next action depending on the previous actions.
<br>(Optional lines based on player choice)
_____________________________________________________________________________________________________________________________
Monsters block your path:

Enemy[1]     Enemy[2]     Enemy[3]     Enemy[4]
<pre>
___________________________________________________________________
Health: 27/50    Magic: 35/50
___________________________________________________________________
</pre>
What would you like to do? 
1. Attack an enemy
2. Use an item
3. Attempt to flee (return to previous room)

Enter your choice (1-3): 
<br>(1: Which enemy would you like to attack ordered from left to right (1-x): )
<br>(2: UsableItem[1]     UsableItem[2]     UsableItem[3]
     <br>Which item would you like to use (1-x) or go back to the menu (b): )
<br>(3: You can attempt to flee at a certain success rate (50%), do you want to try (y/n): )

List of enemy actions:
<br>EnemyAction[1] 
<br>EnemyAction[2] 
<br>EnemyAction[3] 
<br>EnemyAction[4] 
_____________________________________________________________________________________________________________________________


<br><br>__Game Over Screen:__
_____________________________________________________________________________________________________________________________
GAME OVER

Your health has dropped to 0 and now your progress is lost to the dungeon once more…
<br>Can you find the courage to attempt to escape again?

Enter anything to exit:
_____________________________________________________________________________________________________________________________


<br><br>__Win Screen:__
_____________________________________________________________________________________________________________________________
CONGRATULATIONS!!!

You have overcome the trials and tribulations set before and escaped with only your wits and what you could find! But have you found all the secrets hidden in this dungeon or found every powerful item? Or maybe the dungeon calls once more…

Enter anything to exit:
_____________________________________________________________________________________________________________________________


## Class Diagram
![UML Class Diagram](Documents/CS100_FinalProject_UMLDiagramV2.png)

### Description of the UML CLass Diagram: 
**ScreenManager class**
<br>A class that is created and called when the program starts in order to set up the maps and current rooms loaded in addition to moving between the screens.

This class implements functions that print each screen and determines what will be displayed on those particular screens. When the program is first started, the ScreenManager will be created and display the main menu, awaiting input from the player to move to the next screen depending on the input. Depending on the input, corresponding objects will be created or updated then the next screen will be printed such as the roomIdle screen, battle menu, or inventory. This class will manage the main inputs, prompting the player to input their choice, then take the input and pass it to other classes such as the Map, Room, or Inventory classes.

<br>**Map class**
<br>There is only one Map class present during the program which will contain a vector of Room objects that will be the line of Rooms the player will have to travel through in addition to an index indicating the current Room the player is in. 

This Map class implements functions including displayMap which will be called during a screen transition and will iterate through all Rooms in the Room vector to determine if they are cleared, unknown, or the current room. These states can then be printed to the screen in singular boxes that represent the Rooms. This class also implements a moveRooms function that is called when the player goes to the next or previous room so the currentRoom variable is updated in preparation for the next displayMap call. 

<br>**Room class**
<br>A Room has a vector of Enemy pointers which will contain all the current enemies located in that Room. The Room will also be created with a vector of Item pointers that contains the available items in the Room that the player will be able to find by choosing to look around the Room. Finally, the Room has a clear boolean variable which will indicate if the Room has enemies and is safe or not, and contains a string called roomInfo that contains unique information about the Room that the player can examine. 

The Room will be constructed with an imputed roomInfo as well as a randomly generated number of enemies and items once the player enters the Room. Right after the Room is constructed, startBattle will be called which will create a BattleManager and proceed to the battle menu which will continue until the Enemy pointer vector is empty and the Room will be set to clear. The lookAroundRoom function will randomly select an item from the Item pointer vector and give a success chance for the player to obtain the item. Finally, the getRoomInfo function is implemented by printing the roomInfo string to the screen, then prompting the player for the next choice of action.

<br>**ItemDatabase class**
<br>Only one ItemDatabase is present in the program that will hold all programmed items in the game. All items are contained within a two-dimensional vector, with each row containing a singular item and each column containing a property of that item including the name, description, property, and idNum. 

To access the items in this database, the returnItem function is implemented by taking two integers as parameters, the first indicates the row, or item, and the second indicates the property, or column, which returns a string that can then be converted to other data types when an Item is constructed for the player to obtain. 

<br>**Item base class**
<br>An abstract base class that other items of three types, Weapon, Usable, and Equip, will inherit from and contains basic information that all items will have including its name, description, property, and its idNum.

It has a set of getter functions to return all of these internal values for each item and no setters are required as these values for items should not be changed after the item is constructed.

<br>**Weapon class that inherits from Item**
<br>A Weapon has an integer that represents damage. A Weapon will be constructed similarly to its inherited Item having a name, description, and property which will influence the damage number. 

A Weapon will implement the totalDamage function which takes an Enemy* as an input which will then subtract the damage value from the weapon from that Enemy’s health. A chooseWeapon function will also be implemented so a specific Weapon object is indicated from the inventory so only one Weapon damage is applied. 

<br>**Equip class that inherits from Item**
<br>A Equip has a boolean equipped that will indicate whether that item is equipped to the Player or not and will influence whether the player gets a boosted stat or not.

IncrStat and decrStat functions are implemented that check if the item is equipped to the passed in Player, and if they are, then the incrStat function will increase the corresponding stat and the decrStat function will decrease the corresponding stat. The equipItem and unequipItem functions will set the value of the equipped boolean based on the player inputs in the inventory menu.

<br>**Usable class that inherits from Item**
<br>A Usable will have a statChanged integer in addition to the other variables set by the inherited Item that will indicate which stat will be affected by the item being used. The amount that will be affected is determined by the property integer in the inherited Item class.

The useItem function is implemented by passing in a Player object which will then take the statChanged integer to determine which stat to update on the Player and the value changed will be determined from the property integer.

<br>**Entity base class**
<br>The Entity class is an abstract base class which both the Player class and Enemies will inherit from. This class has both standard variables for statistics such as health, defense, attack, and speed as well as implementations for getter and setter functions for those variables that inherited objects will have. 

The implemented functions will include getters for all individual statistic variables and one setter function that will take in arguments for each of the statistics gathered from player’s choices or equipable times. An updateHealth function will also take an integer as an argument which will be called any time damage is dealt or a heal item is used and will update the Entity’s health accordingly.

<br>**Player class that inherits from Entity**
<br>The Player class has a string name that will be input upon construction of the object in addition to an Inventory that is linked to the Player which they will be able to access through this item. In addition to other statistics, the Player also has maximum and current magic through integers that will be the cost for certain items. 

The Player constructor takes the Player name as the only argument to initialize the Player object. Getter functions are implemented in order to retrieve any extra statistics that would be needed to be used in battle functions and a setter is implemented through the updateStat function which takes two integers as arguments indicating the stat that would be changed and the value that it is changed by. Finally, the chooseAction function is implemented by allowing input for the Player to choose an action from accessing their inventory, to attacking with a weapon, or attempting to flee.

<br>**Enemy abstract class that inherits from Entity**
<br>The Enemy class is an abstract base class that all enemies will inherit from. This class contains the functions and variables that all enemies will need to have. The constructor will accept a name from the player that determines which enemy to fight next.
Each enemy will have its own name (Witch, Spider, Golem, Skeleton, and Boss). Each enemy also contains their own number of actions to execute while fighting the player. The number of actions is determined by the level/area of the dungeon the player is located at. The enemy’s action will be determined by the player’s input. Each enemy will have their own unique “expValue” which is what increases the player’s abilities every time an enemy is defeated. Each enemy gives its own unique “expValue” amount. The higher level the enemy, the more “expValue” the player will receive. 

The implementation functions will be two getter functions and one virtual function that each enemy will uniquely use. Enemies will use the same getter functions to return the enemy’s name and expValue when called. Enemies will use the same “action” virtual function to combat with the player. Action is unique for each enemy.

<br>**Witch class that inherits from Enemy**
<br>The Witch has an integer magic that is initialized from the constructor which takes the maximum magic as an integer argument. 

A Witch has an implementation of the action where it has a certain number of possible actions and one is randomly chosen. Then appropriate damage is applied to the Player with the action being output during the turn output.

<br>**Spider class that inherits from Enemy**
<br>The Spider inherits from the Enemy class which will construct based on the enemy name, numActions, and exp value input.

A Spider has an implementation of the action where it has a certain number of possible actions and one is randomly chosen. Then appropriate damage is applied to the Player with the action being output during the turn output.

<br>**Golem class that inherits from Enemy**
<br>The Golem inherits from the Enemy class which will construct based on the enemy name, numActions, and exp value input.

A Golem has an implementation of the action where it has a certain number of possible actions and one is randomly chosen. Then appropriate damage is applied to the Player with the action being output during the turn output.

<br>**Skeleton class that inherits from Enemy**
<br>The Skeleton inherits from the Enemy class which will construct based on the enemy name, numActions, and exp value input.

A Skeleton has an implementation of the action where it has a certain number of possible actions and one is randomly chosen. Then appropriate damage is applied to the Player with the action being output during the turn output.

<br>**Boss class that inherits from Enemy**
<br>Gets the Boss stats, generates random numbers associated with Boss’s move kit. Could be an attack against the player, something that makes the boss stronger. Then says some dialogue to the player through the implementation of the displayDialogue function which outputs text to the screen. 

A Boss has an implementation of the action where it has a certain number of possible actions and one is randomly chosen. Then appropriate damage is applied to the Player with the action being output during the turn output.

<br>**Inventory class**
<br>The Inventory class has a vector of Item pointers which will be sorted alphabetically in addition to a vector of Equip objects that will represent the currently equipped Items the Player has. The integer max items will be a limit on the size of the inventory, and the current number of items will be stored in the integer numItems. 

The Inventory class displays the players inventory, which will be sorted alphabetically through the implementation of displayInventory which will help print to the screen. Then there will be slots where the player can equip items to bring to battle with them through the selectItem where they can view the descriptions and choose certain items through output on the screen. 

<br>**BattleManager**
<br>The BattleManager class has a vector of Entity pointers which is a list of all Entities (Player and Enemies) currently in battle which are sorted by their speed stat. It also has an integer numTurns to indicate how many turns have passed in the battle.

The startTurn function is implemented by taking the action from the argument Player and going through the list of sorted Entities, performing their actions in that specific order. The getPlayerInput will assist in prompting and printing choices for the player in battle and taking that input and applying it accordingly for actions, inventory, or fleeing.

 
 ## SOLID Modifications
 ![UML Class Diagram](Documents/CS100_FinalProject_UMLDiagramV2.png)
 
 ### Single Responsibility Principle

The single responsibility principle is applied in this new class diagram by moving void display functions out of other classes such as the Map and Inventory classes, and only having the ScreenManager class solely handle any pure output to the screen. Instead of the output and cout statements being located in separate classes, these display functions now manipulate the data and return the needed information as strings which will be used in ScreenManager and output there. This helps in writing better code by only having one class manage outputting to the screen and gather the information from other classes called from that one class. This allows for more module implementation by only manipulating and returning data in called functions so if there is an error in output, then only one class needs to be analyzed and then go into manipulation functions from there after the place where the bug is in output has been identified. 

 ### Liskov’s Substitution Principle

Liskov’s substitution principle is applied in this new class diagram by better defining the abstract Enemy base class and its derived classes of specific Enemy types. During the function of the program a list of Enemies will contain the different types of Enemies that derive from the Enemy base class and will all be expected to act very similarly during function calls. The main function that needs to behave similarly between all derived classes is the action function from the base class which will take in the Player object as a parameter in order to affect it through damage, and return a string depending on the action performed and its flavor text. Even though the actions may yield different damage to the Player or different strings as descriptions of the actions, they should all function with the same input and output types and be replaceable with any one of the derived classes. This helps in better code by allowing derived classes to separate actions of different types of enemies from each other by still accessing the needed data manipulation and information from those actions in the same way.

 ### Interface Segregation Principle

The interface segregation principle was implemented by analyzing the similarities and functions in common between the base class of Entity and its derived classes of Player and Enemy. Before, the Player and Enemy classes had separate variables and getter functions for each of their specific names and exp values. This was done before because it was thought that these variables would be created and used in different and unique applications, however after further deliberation, the only purpose that the name and exp variables need is to store the specific values and need to get their values in order which would then be manipulated by another function. They serve the same purpose between both derived classes so it would make more sense to be in the base class. This is more of an inversion of the interface segregation principle as we are taking two separate variables among derived classes and combining them in the base class because the function is the same over the two classes. However, this does make the code better as we don’t have the same implementation of two variables over two derived classes when we could easily have one implementation in the base class which the two derived classes can still access. 



 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screnshots of the input/output after running your application
 > <img width="795" alt="Screenshot 2023-06-08 at 11 18 49 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/22b407ce-8c74-4add-9a18-e74e0f08efca">
 > <img width="1117" alt="Screenshot 2023-06-08 at 11 20 03 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/7a824592-87ad-43aa-8a92-881394f13296">
 > <img width="1117" alt="Screenshot 2023-06-08 at 11 20 34 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/97bc2528-bceb-434e-8842-4fa965d1b896">
 > <img width="1133" alt="Screenshot 2023-06-08 at 11 22 05 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/6b36b84b-fd2a-4e87-844b-9654a0f30d0e">
 > <img width="1131" alt="Screenshot 2023-06-08 at 11 35 57 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/04d844ed-f871-4c59-928a-6ea1908fa2d2">
 > <img width="1103" alt="Screenshot 2023-06-08 at 11 36 43 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/7175e43a-eea9-4487-b3af-1611dca097f6">
 > <img width="827" alt="Screenshot 2023-06-08 at 11 38 26 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/6b45deb3-f119-4615-b9cc-00f0d8788139">
 > <img width="882" alt="Screenshot 2023-06-08 at 11 49 20 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/7f0ea996-dfdb-439d-9ac5-cce7550a4863">
 > <img width="914" alt="Screenshot 2023-06-08 at 11 51 46 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/62bdd1f7-fbba-478f-9897-762367895044">
 > <img width="539" alt="Screenshot 2023-06-08 at 11 52 45 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/9401b89b-ebcd-4597-a813-f30679f2e266">
 > <img width="1113" alt="Screenshot 2023-06-08 at 11 54 26 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/425985da-c554-42b4-8821-3074c3023b2d">
 ><img width="808" alt="Screenshot 2023-06-08 at 11 54 54 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/d5b946eb-a684-4798-b8c5-c21241c72b67">
 > <img width="1106" alt="Screenshot 2023-06-08 at 11 55 19 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/f870f99c-295e-48ec-b984-cd0b5f2075a2">
 > <img width="797" alt="Screenshot 2023-06-08 at 11 55 40 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/c5c5e688-9e90-4620-9c72-6373aeb36bfb">
 > <img width="457" alt="Screenshot 2023-06-08 at 11 57 16 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/fc83468a-728d-4dc8-9dd4-0fab85c3542e">
 > <img width="895" alt="Screenshot 2023-06-08 at 11 58 50 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/9eefc02f-1f07-4cbe-a45b-dadc3cb5b029">
 > <img width="590" alt="Screenshot 2023-06-08 at 11 59 25 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/ee727bd5-9e0b-4765-95b0-01f0890f12fb">
 > <img width="970" alt="Screenshot 2023-06-08 at 11 59 52 PM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/d4b603b2-9c60-49c4-9afc-eae5183c5705">
 > Once you defeated all enemies in the room, Player is prompt back to the Idle Room Menu. Now, the Player can scan choose any option from the menu to investigate the room. 
 > <img width="1112" alt="Screenshot 2023-06-09 at 12 05 07 AM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/fea9be4d-8fac-4a73-994d-65826c23e1e5">
 > When Player is finished examining the room, pressing [5] again takes player to the next room. The map updates to the next room. 
 > <img width="798" alt="Screenshot 2023-06-09 at 12 06 19 AM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/595dd35d-70a4-4ff6-9292-bf087cfa36b7">
 > In the event the Player looses a fight battle with one of the enemies, a message will display to the Player and the game will end bu asking the Player if they want to play again.
 > <img width="753" alt="Screenshot 2023-06-09 at 12 09 40 AM" src="https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031/assets/32427334/8d5d8f2a-78c1-4ef9-96c6-112228264761">


 ## I![Uploading Screenshot 2023-06-08 at 11.18.49 PM.png…]()
nstallation/Usage
 > Instructions on installing and running your application:
 > Open the terminal in VSCode. 
 > In the terminal, type the following commands:
 > * git clone https://github.com/cs100/final-project-jhoan070-elee-cclab002-gvasq031.git
 > * camke .
 > * make
 > * ./bin/runMain
 > 
 The program will run and the should display in the terminal.  
 ## Testing
 > How was your project tested/validated?
 > 	The project's memcheck was validated through valgrind and the code coverage was validated with g++'s built in gcov and lcov.
 
