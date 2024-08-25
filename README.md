# Implement a C program called recover that recovers JPEGs from a forensic image.

The program should accept exactly one command-line argument: the name of a forensic image from which to recover JPEGs.
If the program is not executed with exactly one command-line argument, it should remind the user of correct usage, and main should return 1.
If the forensic image cannot be opened for reading, the program should inform the user as much, and main should return 1.
The files generated should each be named ###.jpg, where ### is a three-digit decimal number, starting with 000 for the first image and counting up.
