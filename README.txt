Student: Ethan Lew
GNumber: G03729047
Date: 10/03/2016
Project: Project 1
Class: CS 162
Instructor: Li Liang


About
  Grocery Hero is a command based inventory tracker that calculates total cost.
  The program was developed with speed in my accepting easy to type input:

    "add" or "a" add an item
    "delete" or "d" deletes an item
    "edit" or "e" edits an item
    "ls" or "l" prints an inventory list
    "quit", "q", "exit" and "e" exits the program

Roadmap
  Grocery Hero had a short development schedule. Here are features that are
  planned in future releases:
    1. List file saving. Being able to load and save sessions will greatly help
      the user plan shopping trips.
    2. Abstract command parsing. Building a class that can identify options and
      command structure is needed to create a rich feature set. Currently, the
      command parser is not scalable.
    3. Recursive lists. Being able to categorize items by creating sublists will
      greatly impact user experience. This paradigm will also enable vector
      similarity analysis.
    4. List modes. With the addition of sublists and independent lists, being
      able to enter a list mode will greatly improve productivity. This way a
      user can set a list as active and assume all list commands will apply to
      it.

Known Issues
  1. If you edit an item and do not specify a quantity, it will override the
    item's quantity to 1. This is due to the simplistic command parsing flow.
    This issue will be resolved after abstract command parsing is added.
