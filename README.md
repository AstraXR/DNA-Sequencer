# DNA-Sequencer

DNA Manipulator - A Customizable Sequence Editor
This project implements a command-line program for manipulating DNA and RNA sequences in C++.

Key Features:

Create and manage sequences: Define DNA or RNA sequences and store them in a fixed-size list.
Perform various operations: Insert, remove, print, clip, copy, swap, and transcribe sequences based on user-provided commands.
Handle errors gracefully: The program validates user input and provides informative error messages.
Modular design: Separate classes for sequences and fragment lists promote code maintainability and reusability.
Getting Started

Building the project:

Clone this repository.
Navigate to the project directory.
Run make to compile the program.
Running the program:

The program takes command-line arguments to specify:

-f: Path to the input file containing sequence manipulation commands (required).
-m: Maximum number of sequences allocated (default: 8).
-l: Log detail level (default: 'info').
Example usage:

./dna_manipulator -f commands.txt
This will run the program using the commands specified in the commands.txt file.

Input File Format:

The input file should consist of one command per line. Each command is case-insensitive and has the following format:

Comments (starting with #): Ignored.
Blank lines: Ignored.
Supported Commands:

insert pos type sequence: Inserts a new sequence at the specified position.
remove pos: Removes the sequence at the specified position.
print: Prints all sequences in the list.
print pos: Prints the sequence at the specified position.
clip pos start: Replaces the sequence at the specified position with a clipped version starting from the specified character.
copy pos1 pos2: Copies the sequence from one position to another.
swap pos1 start1 pos2 start2: Swaps the tails of sequences at two positions.
transcribe pos: Transcribes a DNA sequence to RNA or vice versa.
