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
After downloading the latest release extract it anywhere.
### 2. Build the solution
You will have to use a c++ compiler. Import the extracted folder and press Build and Run button. Alternatively use the provided Makefile (you can also change the optimization flags, see CHANGES IN VERSION 1.1).
### 3. Using the application
Upon building and launching the program you will be presented with a console interface. Input numbers (1 to 4 in the starting menu) to navigate the interface.
## FORMATTING
The program only reads data files that follow the following formatting:
```
Vardas                   Pavarde                    ND1       ND2       ND3      Egz.
Vardas1                 Pavarde1                      8         9         4        10
Vardas2                 Pavarde2                      9         7         9         2
...                                                                                  
```
Vardas and Pavarde refer to Name and Surname values, ND(number) shows the homework mark along with its iterator, Egz. refers to the exam mark. Number of homework marks can be varied indefinitely, yet they cannot be equal to zero. Exam mark is required.
## CHANGES IN VERSION 1.1
The Studentas struct has now been made a separate class, which ensures a more cohesive code structure and covers several undefined behaviour and variable privacy issues. It is overall a more stable release.
Keep in mind however that those changes come with a slight decrease in execution time.
Here are the comparison tables for 100k and 1m sized testing data files with different optimization flags:

|100k Lines Data File | -01 Code Execution Time | -02 Code Execution Time | -03 Code Execution Time |
|--- | --- | --- | ---
|class 1.1 | 1.145s | 1.01s | 1.008s
|struct 1.0 | 1.044s | 0.965s | 1.126s

|1m Lines Data File | -01 Code Execution Time | -02 Code Execution Time | -03 Code Execution Time |
| --- | --- | --- | ---
|class 1.1 | 10.107s | 9.978s | 10.022s
|struct 1.0 | 9.529s | 9.562s | 9.603s

|| -01 Executable Size | -02 Executable Size | -03 Executable Size |
| --- | --- | --- | ---
|class 1.1 | 215KB | 213KB | 223KB
|struct 1.0 | 218KB | 209KB | 218KB
