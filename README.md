[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10871820&assignment_repo_type=AssignmentRepo)
 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Escape Dungeon

 > Authors: \<[Gabriel Vasquez](https://github.com/GoodfellaGabe)\>
	\<[Connor Claborn](https://github.com/connorcla)\>
	\<[Eliot Lee](https://github.com/swooshoo)\>
		\<[Jonathoon Hoang](https://github.com/Janathoon)\>

## Project Description
General Description
> This program is a terminal and text based role playing game in which players can choose their character in order to enter and progress through a dungeon and get out safely. The player will start with minimal equipment and is forced to trek through a mysterious and unknown labyrinth navigating from room to room in order to get to the exit. Through this dungeon, the player will be able to obtain items to increase their chances of survival through tools to navigate through the dungeon better and weapons to face off against enemies that lurk in the dark. The player will have to fight through enemies with items and experience gained in order to travel from room to room, uncovering why they are there and to eventually escape.

Why it is important or interesting?
> A lot of software today is involved in some sort of entertainment with a large market in the realm of digital gaming. These games are defined by unique and complex systems or mechanics that make them stand out from other forms of entertainment in addition to immersion as the player is in full control of their character, acting as they like in game. This will be a project that will bring enjoyment to others as they are able to run and play our program, taking a new path each time they enter the dungeon, and experiencing their adventure once more.

Languages/Tools/Technologies
> **C++**: This is the main language this project will be programmed in.

> **VSCode**: Visual Studio Code is the IDE and text editor that will be used to write and test code in.

> **Git**: Git allows us to work collaboratively on this project by maintaining a version control system, make and edit branches for new features, and commit to a central repository.  

> **GitHub**: GitHub is a central area located on an accessible server to visualize our version control system. This will allow for better organization in our collaboration by creating project boards in order to assign tasks which will be completed individually and added together in the GitHub repository. 

> **Valgrind**: Used as a debugging tool, Valgrind helps detect memory leaks, find uninitialized memory, and profile memory usage. With the development of a game project, this is important to manage quickly growing memory and detect unpredictable behavior & crashes.Profiling memory usage allows to identify areas where memory should be optimized or reduced.

> **CMake**: Allows us as developers to specify build processes, manage dependencies, and organize our project’s source code. In the context of an RPG game, it could help manage any external libraries we may use and specify build types for debugging purposes. Seeing that the project is also a collaborative project, CMake’s ability to organize the source code into logical modules makes it easier to manage the scale of the project 

Input/Output of Project?
> Input: A user will be prompted by Terminal to select menu options (i.e. “1-Talk to the tavern owner, 2 - Open quest log, 3- Open inventory) etc.) The story will progress differently and the user may pick alternate endings depending on the user’s inputs (i.e. failing to use a heal item when needed could result in character death). 

> Output: The output will be on Terminal such as dialogue, storyline, menu options for the next user input, and maybe even combining symbols to create backgrounds or characters.

Project Features
> Players should be able to select and/or create their character they want to use to navigate through the dungeon. They will be able to view and manage their player’s statistics and choose which skills to increase or level up as the game progresses. Along with this character management, heal and magic counters will be shown to let the player know of any available resources as well as menus showing different options or actions their player can take.
> 
> As players navigate through the dungeon, they  will be able to access and view a map of the dungeon including the rooms visited, any significant characters, and any unchecked rooms. Players can choose which direction to explore in and can investigate or use different actions around rooms prompting different responses. By navigating, players can find other characters that can help them on their journey, or give them information about the place they are attempting to escape from.
> 
> Through their journey players can obtain and use items that will aid them in fights or navigating through the rooms. Items will be obtained by defeating enemies or finding special rooms and can be viewed in an inventory. These items will be able to be used either in battle against enemies or in the map in order to aid in navigating.
> 
> Players will come across enemies during their journey which will be prompted by either entering or performing certain actions in rooms. Fighting enemies will prompt a special battle menu that will provide players several options including attack, defend, or use an item. Players will have to defeat all enemies and will be rewarded upon doing so.
 
 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
> Draw a diagram illustrating how the user can navigate from one screen to another. Here is an [example](https://creately.com/diagram/example/ikfqudv82/user-navigation-diagram-classic?r=v). It can be useful to label each symbol that represents a screen so that you can reference the screens in the next section or the rest of the document if necessary. Give a brief description of what the diagram represents.

### Screen Layouts
> Include the layout of each of your screens. The layout should describe the screen’s major components such as menus and prompts for user inputs, expected output, and buttons (if applicable). Explain what is on the layout, and the purpose of each menu item, button, etc. If many screens share the same layout, start by describing the general layout and then list the screens that will be using that layout and the differences between each of them.

## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
