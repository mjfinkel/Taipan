# Taipan!
C++ terminal/command line implementation of the 1979 computer game *Taipan!*. Created in XCode with MacOS <br><br>

## Background
*Taipan!* is a turn-based strategy computer game created by Art Canfil in 1979 using a TRS-80 and was originally released on the Apple II in 1982.
<br><br>

## How to play
In this game, the player is a trader in the East. The player travels to 7 different ports and can either buy or sell 4 differnt goods. When traveling or at different ports the player will run into pirates, a crime boss, and merchants.

#### Economy
The prices of goods vary depending on when and where they are being bought. The range of these prices is customizable in the source code. The player can either hold onto their goods, or store them in their warehouse at the first/main port. The player makes money by buying cheap and selling when prices rise. Holding onto too many goods raises the attention of pirates and the crime boss, makes it harder to escape from pirates, and increases chances of ships sinking during storms.

#### Crime/Mob boss
The crime boss will occasionally send a lieutenant requesting the player to return to the main port and donate money to his organization. Paying the crime boss decreases the chance that he sends a lieutenant in the future and increases the chance that the crime organization will help fight off pirates. Refusing to pay increases the chance that the crime organization will send a massive attack at the player.

#### Pirate attacks
The player will randomly be attacked by pirates. Carrying more goods in-house rather than storing at your warehouse increases this chance. When approached, the player has the choice to either fight or flee. The player will be prompted multiple times until they either escape or defeat the pirate fleet. Both options equally damage the fleet's health. Having more ammunition/guns helps take out the priates quicker. Ammunition/guns can be purchased randomly when traveling to ports. If the player chooses to run away, the chance of escape varies depending on how much cargo is being held. The player can throw cargo overboard to increase chances at escape. The player can also be randomly saved by the crime organization.
<br><br>

## Initial setup
```
$ make ./taipan
$ ./taipan
```

## Miscellaneous
- The player can only quit the game when at a port and prompted:
    ```
    Your orders [player name]?
    1. Buy  2. Sell  3. Leave Port
    9. Leave game
    ```
    or prompted at main port:
    ```
    Your orders [player name]?
    1. Buy  2. Sell  3. Leave Port
    4. Visit Bank  5. Transport Cargo
    9. Leave game
    ```
