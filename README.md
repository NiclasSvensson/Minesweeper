# Minesweeper

Minesweeper game developed in C++, using the SFML library for GUI. Created as a hobby project to practice my programming ability. Contains all features a minesweeper game should contain apart from a "safe start", where the first click guarantees to hit a square with 0 neighbouring mines.

# Install

Install g++ and SFML. Clone the project and run make.

```console
sudo apt-get install g++
sudo apt-get install libsfml-dev

git clone git@github.com:NiclasSvensson/Minesweeper.git
cd Minesweeper
mkdir build
cd build
cmake ..
make
```

# Run

```console
./app
```

# Explosion animation

The explosion animation is created by Oliver Remund in Piskel and can be found [here](https://www.piskelapp.com/p/agxzfnBpc2tlbC1hcHByEwsSBlBpc2tlbBiAgMDa6NjhCgw/view). All other game art was created by me.

