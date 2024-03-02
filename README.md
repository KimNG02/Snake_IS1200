Snake Game on PIC32
Overview
This project is a PIC32 microcontroller-based implementation of the classic Snake game, utilizing the Uno32 development board and its OLED graphical display for visual output. The game is controlled using the Basic I/O shield buttons, making it a compact and self-contained system for embedded gaming enthusiasts.

Features
OLED display for game visualization
Directional control using Basic I/O shield buttons
Collision detection with walls and self
Apple "eating" to increase the snake's length
Score tracking and display
Getting Started
Prerequisites
Microchip PIC32 microcontroller
Uno32 development board
Basic I/O shield
MPLAB X IDE and XC32 Compiler installed on your computer
Installation
Clone the repository

bash
Copy code
git clone https://github.com/yourgithubusername/snake-game-pic32.git
Open the project in MPLAB X IDE

Navigate to the cloned project directory and open it with MPLAB X IDE.

Configure the project for the XC32 Compiler

Connect the Uno32 board to your computer via USB

Build and upload the project

Use MPLAB X IDE to compile the project and upload it to the Uno32 board.

Usage
Control the snake using the buttons on the Basic I/O shield. The game starts immediately upon loading, with the objective of eating apples and avoiding collisions.

Project Structure
src/: Source code files for the game's logic, display, and control.
include/: Header files for the project's functions and definitions.
docs/: Additional documentation, including design docs and schematics.
Contributing
Contributions are welcome! If you have suggestions for improvements or new features, please feel free to fork the repository, make your changes, and submit a pull request.

License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgments
Microchip Technology for the PIC32 microcontroller and Uno32 development board.
Our project advisors and peers for their support and feedback.
