# Snake Game on PIC32

This repository contains the source code for a classic Snake game implemented on the PIC32 microcontroller using the Uno32 development board. This project leverages the board's OLED graphical display for the game's visual output and utilizes the Basic I/O shield for user input.

## Project Objective

The goal was to create a functional Snake game on the PIC32 platform that includes:

- Displaying the game on the OLED screen.
- Enabling snake movement in X and Y directions.
- Implementing collision detection.
- Allowing the snake to "eat" apples to grow in size.
- Displaying the current score.

## Setup and Requirements

### Hardware Requirements

- Microchip PIC32 microcontroller
- Uno32 development board
- Basic I/O shield (for user input handling)

### Software Requirements

- MPLAB X IDE
- XC32 Compiler

## Installation

 Clone this repository to your local machine.
   ```sh
   git clone https://github.com/yourgithubusername/snake-game-pic32.git
   
Open the project in MPLAB X IDE.
Configure your project to use the XC32 Compiler.
Connect your Uno32 board to your computer.
Build the project and upload it to the Uno32 board.

## Usage

- After uploading the game to the Uno32 board, use the buttons on the Basic I/O shield to control the snake's movement.
- The goal is to eat as many apples as possible without colliding with the walls or the snake's tail.

## Project Structure

- `src/`: Contains the source code files for game logic, display rendering, and input handling.
- `include/`: Contains the header files for the project, defining functions and variables.
- `docs/`: Documentation related to the project, including design documents and schematics.

## Contributions

This project is a collaborative effort:

- **Kim Nguyen**
- **Natali Alhallak**

We welcome contributions from the community. Please feel free to fork the repository, make improvements, and submit a pull request.

## License

- This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

- Thanks to Microchip Technology for providing the PIC32 microcontroller and development tools.
- Appreciation to our project advisors and classmates for their valuable feedback.
