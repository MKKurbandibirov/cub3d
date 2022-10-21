
<h1 align="center">
📦 cub3D
</h1>

### 🗝️ Original in [**Russian**](https://github.com/AYglazk0v/cub3d/blob/main/README.md)

## 💡 About the project:

> _This project is inspired by the world-famous game Wolfenstein 3D, which
was the first in the history of FPS. It will allow you to learn the ray-casting method. Your goal will be to
Create a dynamic view inside a labyrinth in which you have to find your way.._

	The goals of this project are similar to all of the first-year goals: 
	Rigor, use of C language, use of basic algorithms,
	information exploration, etc.
	As a graphic design project, cub3D will allow you to improve your skills in
	Windows, colors, events, filling shapes, etc.
	In conclusion, cub3D is a great playground for learning
	game practical applications of mathematics.
	Applications of mathematics without having to understand the specifics. With the help of
	numerous documents available on the Internet, you will use
	mathematics as a tool to create elegant and efficient algorithms.

More details about the project and the nuances can be found at [**subject**](https://github.com/AYglazk0v/cub3d/blob/main/additionally/Subject.pdf).

## 🛠 Testing and Usage:

	# Clone the project and access the folder
	git clone git@github.com:AYglazk0v/cub3d.git && cd cub3d/
	
	# Before building the project you should check the state of the
	# FLAGS variable in the Makefile, if the project will be tested under Linux you should leave the
	# version of the FLAGS variable with the -DLINUX flag, otherwise this one should be commented out and 
	# uncomment the version without the flag. 
	
	# Build a project for MacOS:
	make
	
	# In order to start the program you have to give one of the maps located in the 
	# in the maps directory, or create your own according to the rules specified in the subject.
	# Example command:
	./cub3d maps/test.cub
	
	# You can clear the output files with
	make fclean

### Managing:

| KEY           | Action        |
| ------------- |:-------------:|
| `ESC`         | Quit the game     |
| `SPACE BAR`   | Open/close door      |
| `A`           | Going left.     |
| `D`           | Going right.  |
| `W`           | Going forward  |
| `S`           | Going backward |
| `→`           | Turn the camera to the right| 
| `←`           | Turn the camera to the left|

### The graphical symbol for constructing a map:
| Value         | Object          |
| -------------  |:-------------:|
| `1`            | Wall         |
| `0`            | Free space         |
| `S`            | Sprite    |
| `N`/`E`/`W`/`S`| Person and direction|

## 🎬 Demonstration(example):
![cub3d](https://github.com/AYglazk0v/cub3d/blob/main/additionally/cub3D.gif)
