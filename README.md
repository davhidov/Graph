# Graph
This program is designed to plot functions given by arbitrary expressions.

![изображение](https://user-images.githubusercontent.com/62353818/170713796-e9d6fb32-9962-48a3-adda-bf9f4c8c0dc5.png)

Graphs are built in the terminal using ASCI symbols.
Domain of definition - [0; 4 pi]
Range - [-1; 1]

# How it work
1. Reading an expression from the terminal
2. Simplifying the expression (sin is replaced by s, etc.)
3. Translation of the expression into Polish notation using the Dijkstra algorithm whith the stack for ease of calculation
![изображение](https://user-images.githubusercontent.com/62353818/170714776-07e17f6f-9233-4428-98fc-de3bf7715cc5.png)
4. Writing the entire expression written in Polish notation to the stack
5. Calculation of the expression for each point of the domain of definition
6. Drawing a graph

# To Run
The program is written in C. It is assembled using the Makefile with the make command in bask. Compiler GCC 20.04.
