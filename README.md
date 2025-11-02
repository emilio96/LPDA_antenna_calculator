# C++ LPDA (Log-Periodic Dipole Array) Calculator

This is a simple, lightweight C++ command-line tool for designing a Log-Periodic Dipole Array (LPDA) antenna.

You provide the desired frequency range and two key design parameters ($\tau$ and $\alpha$), and this calculator will generate all the necessary physical dimensions to build the antenna, including:
* The total number of elements.
* The required length of the support boom.
* The precise length of each half-dipole element.
* The exact spacing between each element.

This repository also includes a complete, buildable example project for a 790-2615 MHz antenna, complete with 3D-printable STL files to act as a "skeleton" for construction.


## How to Use the Calculator

### 1. Compile the Code
This is a standard C++ program with no external dependencies. You can compile it with any C++ compiler, such as `g++`:
In the LPDA_code folder you can find also the .exe file ready to be executed.
### Compile the program
g++ LPDA_Calculator.cpp -o LPDA_Calculator

Run the compiled executable from your terminal:
### On Windows
.\LPDA_Calculator.exe
### On macOS / Linux
./LPDA_Calculator

### 3. Enter Your Parameters
The program will prompt you to enter four values:
1. Lower Frequency (MHz): The lowest frequency you want the antenna to receive (e.g., 790).
2. Upper Frequency (MHz): The highest frequency you want the antenna to receive (e.g., 2615).
3. Element Angle ($\alpha$): The angle (in degrees) that the elements make with the central boom. 
    A larger angle results in a shorter antenna with fewer elements. This must be an integer between 4 and 25.
4. Tau ($\tau$): The scaling factor, which controls the "taper" of the antenna.
    This must be a value between 0.84 and 0.98.A small tau (e.g., 0.84) gives a long antenna with few elements.
    A large tau (e.g., 0.98) gives a short antenna with many elements.
    A value between 0.88 and 0.94 is recommended.

The calculator will then print a complete list of all element lengths and their respective spacing, ready for you to start building.

### Project Files
LPDA_Calculator.cpp: The main C++ source code for the calculator.
/3Dfiles/: A folder containing NuovaLPDA.txt, an example output file for a specific antenna (790-2615 MHz), and a 3D-printable .stl file.
This part act as a "skeleton" to: 
1. Hold the two conductive support booms at the correct distance.
2. Provide perfectly angled guides for soldering the copper wire elements.

This makes it much easier to accurately construct the antenna based on the specifications from the calculator.
