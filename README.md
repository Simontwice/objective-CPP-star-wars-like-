# objective-CPP-star-wars-like- platform game
The project compiles succesfully in CodeBlocks IDE, it might need some adjustments in other IDEs. It is compatible with C++ 11 version.
A final project for an objective cpp course at uni.
The setting is as follows: Luke Skywalker, Princess Leia and their crew land on an island to confront chancellor Palpatine. The goal 
is to have Leia convince him to give up his evil campaign against the galaxy (or something of that sort).
The game is turn-based, and you have a finite number of turns to complete the objective before an automatic loss.
As a player, you command the characters on a tropical island with diverse landscapes: woods, plains, rivers and mountains. Some of those may prove difficult to move across for
the less fit among your team (especially the Programmers). Different land types can be converted into plains by the soldier units. Your goal is to find Chancellor and have Leia "convince" him (the action coincides with a elimination of a unit in case of other units, but alas)
to give up. That is done by simply stepping on the Chancellor's block, but she cannot do it herself - there needs to be a programmer, or Luke adjacent to Chancellor's block for
the convincing to work.

There are four types of rebel units, and three types of empire units. The rebels are: rebel soldier, Leia (which inherits from the former), Luke and Programmer. 
The empire units, in turn, are the Chancellor himself, Darth Vader and Clones (called robots in the game). Chancellor is physically weak and does not move around the map. All the other units do,
and some of them can elliminate their foes - for example, robots and Vader can eliminate any rebel by stepping on them. The programmer can hack into robots' systems and override their
AI units, rendering them unoperative - again, the mechanics are the same as before. The movement cost on different terrains is unique to each unit and is specified in one of the txt files.

Contents:
txt files:
resources: enemies (which specifies the position of the enemies at the start of the game), movement costs (a matrix that specifies movement costs for each unit), pars (many misc parameters 
such as vision radius for different units, but also game time, number of programmers and soldiers etc, terrain (specifies terrain at every square of the map).

The project is fairly easily expandable and scalable - all it takes is to add a proper class file for the new unit type, and modify the matrices for movement costs. Writing new types of interaction 
would require changing the Game.h and Game.cpp files, as they contain the MoveEngine functions that handle interactions.


