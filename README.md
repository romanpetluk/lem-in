# lem-in

This project is a game about ant farm. Its goal is to find the shortest path from start room to the end.

At the beginning from standart output the program recieves information about number of ants had to be leaded through path, room names (can be numbers, words, characters etc.) with coordinates and links. Here is an example:

```
3
##start
r1 1 1
r2 2 2
r3 3 3
r4 4 4
r5 5 5
# another one
r6 6 6
r7 7 7
##end
r8 8 8
r9 9 9
r10 10 10
r11 11 11
r1-r2
r1-r3
r1-r4
# comment
r2-r5
r3-r6
r4-r7
r5-r8
r6-r9
r7-r10
r9-r8
r10-r11
r11-r8
```

Comments "##start" and "##end" are provided to show the start and end room information. We don't care about any other comments.

### Example of output
```
L1-r2 L2-r3
L1-r5 L2-r6 L3-r2
L1-r8 L2-r9 L3-r5
L3-r8 L2-r8
```
