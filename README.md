# IF2110_TB_02_I
Tubes Alstrukdat

## How to Start?
Open config folder to edit the maps, food, and recipe.
#### Maps
Open file "peta.txt"
```
10 10           // Maps with (N x M) size
S#########      // S is the location of simulator
####T##X##      // S is the location of telephone (to buy food)
#M#####X##      // # is an empty space 
#######X##      // X is an obscacle
####XXXX##
#X########
#X######C#      // C is the location for CHOP action
#XXX##F###      // F is the location for FRY action
##########
######B###      // F is the location for BOIL action
.               // . to end map config
```
#### Food
Open file "makanan.txt"
```
3               // Number of food that will be stored
11              // ID of the first food
Ayam Mentah     // Name of the first food
1 0 0           // Days, Hours, Minutes until expired of the first food
0 0 15          // Days, Hours, Minutes of delivery time of the first food
Buy             // Action to obtained the food
0               // Duration of action to obtained the food (not for buy action)
21              // ID of the second food
Ayam Potong     // and so on..
0 2 0
0 0 0
Chop
4
5
Tepung
0 1 0
0 0 30
Buy
10
.               // . to end food config
```
#### Recipe
Open file "resep.txt"
```
3               // Number of recipe
21 1 11         // Food with the ID of 21 can be obtained from 1 other food, by doing an action from food with the ID of 11
31 2 21 10      // Food with the ID of 31 can be obtained from 2 other foods, by doing an action from food with the ID of 21 and 10
37 2 31 15      // Food with the ID of 37 can be obtained from 2 other foods, by doing an action from food with the ID of 31 and 15
.               // . to end recipe config
```

After all of the configuration is complete, type in ./run in terminal and then type in ./main
