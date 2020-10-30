# se3800date_ernstn_schultzjf
BUILD DIRECTIONS:
After cloning the repository, open it from the terminal and type g++ main.cpp datecalc.cpp date.cpp and press enter. Then type ./a.out datecalc --help, to see the available commands to use.
TESTING DIRECTIONS:
From the command line within the project folder, type docker build ./ to run the tests, you will then see the Docker build the project and execute the GoogleTests, indicating if they passed or failed
VERSIONS OF C++ AND G++
supports versions 9.3.0 and later
DESCRIPTION
This app has 2 functions. When the -d command is paired with 2 dates, the program will output the difference in days between the dates. When the -w command is paired with a date, the program will output the day of the week for that date. The program will also check for valid date input eg: "10-30-2020" and "2020-2-31" are invalid dates
LIMITATIONS
None have come up so far in our testing!
