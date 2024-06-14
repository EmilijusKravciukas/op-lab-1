# STUDENT MARK EVALUTAION AND SORTING SYSTEM
## DESCRIPTION
Simple console based application that allows the student data (read from file and manual input are both supported) to be sorted in one of several ways. Keep in mind that the current release (v0.4) is for Windows based systems, attempting to run it on a Linux system will cause errors.
## FUNCTIONS
- Sorting of students by their average mark, median, name and surname
- Reading student data from a file, provided it follows the provided format (see FORMATTING section)
- Sorting students into separate files based on their academic provess
- Random student and mark generation for testing purposes
## USAGE GUIDE
### 1. Download the latest release
Download the latest release with setup file. Launch the setup and the installation wizard will walk you through. (Optionally you can still download and build the solution yourself, look for the same version release with source files).
### 2. Using the application
Upon installing and launching the program you will be presented with a console interface. Input numbers (1 to 4 in the starting menu) to navigate the interface.
## FORMATTING
The program only reads data files that follow the following formatting:
```
Vardas                   Pavarde                    ND1       ND2       ND3      Egz.
Vardas1                 Pavarde1                      8         9         4        10
Vardas2                 Pavarde2                      9         7         9         2
...                                                                                  
```
Vardas and Pavarde refer to Name and Surname values, ND(number) shows the homework mark along with its iterator, Egz. refers to the exam mark. Number of homework marks can be varied indefinitely, yet they cannot be equal to zero. Exam mark is required.
## CHANGES IN VERSION 3.0
Created custom Vector container with RoF implementation, tested by Doctest framework.
Optimization comparison table using simple storing variables with push_back script:

|| 100k variables | 1m variables | 10m variables | 100m variables
|--- | --- | --- | --- | ---
| Vector | 1ms | 11ms | 122ms | 1226ms
| std::vector | 0ms | 6ms | 111ms | 1241ms

Code execution time comparison:

|| 100k variables | 1m variables 
|--- | --- | --- 
| Vector (3.0) | 1.093s | 9.869s
| std::vector (2.0) | 1.145s | 9.978s 

