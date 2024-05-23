# Flappy Bird Console Game Using OOP

This project is a console-based implementation of the popular Flappy Bird game, developed using Object-Oriented Programming principles and the `olcConsoleGameEngine`. The game is written in C++ and provides a basic gameplay experience similar to the original Flappy Bird game.

## Features

- Simple and addictive gameplay
- Randomly generated obstacles
- Score tracking with high score retention
- Collision detection and game reset functionality

## Getting Started

### Prerequisites

To run this project, you will need:
- A C++ compiler that supports C++11 or later
- The `olcConsoleGameEngine` library (included in the repository)

### Installing

1. **Clone the repository:**

    ```sh
    git clone https://github.com/taqihaider110/Flappy-Bird-Game-Using-OOP.git
    cd Flappy-Bird-Game-Using-OOP
    ```

2. **Compile the project:**

    Make sure you have a C++ compiler installed. You can use `g++` on Linux or MinGW on Windows.

    ```sh
    g++ -o FlappyBird FlappyBirdGame.cpp -std=c++11
    ```

    Or, if you're using a different compiler:

    ```sh
    cl /EHsc FlappyBirdGame.cpp
    ```

3. **Run the game:**

    ```sh
    ./FlappyBird
    ```

## Usage

- Use the `SPACE` key to make the bird flap.
- Avoid the obstacles to score points.
- If you collide with an obstacle, the game will prompt you to try again by pressing `SPACE`.

### Code Overview

- `FlappyBirdGame.h`: Contains the `FlappyBird` class which extends the `olcConsoleGameEngine`.
  - Bird and game logic components
  - Game state management
  - User input handling

- `ConsoleApplication1.cpp`: Main entry point for the application.
  - Initializes the game engine
  - Starts the game loop

## Contributing

If you have suggestions or improvements, feel free to fork the repository and submit a pull request. We welcome all contributions!

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a pull request

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- The `olcConsoleGameEngine` by [OneLoneCoder](https://github.com/OneLoneCoder)
- Original Flappy Bird game by Dong Nguyen
