import subprocess
import sys
import os

libraries = []
executables = []
args = []
subdirectories = []
prefix = ""

def parse_line_for_command(line, prefix):
    # If the line is not empty and is not a comment
    if line[0] != '\n' and line[0] != '#':
        split_data = line.split('(', 1)
        command = split_data[0]
        # The -2 gets rid of the closing bracket and the new line character
        paramaters = split_data[1][0:-2]
        handle_command(command, paramaters, prefix)

def handle_command(command, paramaters, prefix):
    if command == "add_executable" or command == "set" or command == "target_link_libraries" or command == "add_library":
        # Splits the paramaters so Tutorial tutorial.cpp, would be split into Tutorial and tutorial.cpp
        split_paramaters = paramaters.split(' ', 1)
        paramater_pair = (split_paramaters[0], prefix + split_paramaters[1])
        if command == "add_executable":
            executables.append(paramater_pair[0])
            libraries.append((paramater_pair[0], paramater_pair[1]))
        elif command == "set":
            handle_set_args(paramater_pair[0], paramater_pair[1])
        elif command == "add_library":
            libraries.append((paramater_pair[0], paramater_pair[1]))
        
    elif command == "add_subdirectory":
        subdirectories.append(paramaters + "/")

def handle_set_args(paramater, paramater_value):
    if paramater == "CMAKE_CXX_STANDARD":
        args.append("-std=c++" + paramater_value)

def handle_subdirectories():
    if len(subdirectories) == 0:
        return
    else:
        for subdirectory in subdirectories:
            with open((prefix + subdirectory + "cmakelist.txt"), 'r') as file:
                data = file.readlines()
            file.close()
            args.append("-I " + "../" + subdirectory)
            for line in data:
                parse_line_for_command(line, subdirectory)

def generate_makefile():
    with open('Makefile', 'w') as file:
        # Compiler
        file.write("C++ = clang++\n")
        # Compile args
        file.write("C++FLAGS = ")
        for c in args:
            file.write(c + " ")
        file.write("\n")
        # File prefix
        file.write("SRC_PREFIX = " + prefix)
        file.write("\n\n")
        # Final executable
        file.write("main: objects\n")
        file.write("\t")
        file.write("$(C++) $(C++FLAGS) ")
        for a, b in libraries:
            file.write(a + ".o" + " ")
        file.write("-o " + "$(SRC_PREFIX)" + executables[0])
        file.write("\n\n")
        # Object files
        file.write("objects: \n")
        for a, b in libraries:
            file.write("\t")
            file.write("$(C++) $(C++FLAGS) -c " + "$(SRC_PREFIX)" + b + " -o " + a + ".o")
            file.write("\n")
    file.close()

if __name__ == "__main__":
    prefix = os.path.dirname(__file__) + "/" + sys.argv[1] + "/"

    with open((prefix + "cmakelist.txt"), 'r') as file:
        data = file.readlines()

    file.close()

    for line in data:
        parse_line_for_command(line, "")

    handle_subdirectories()
    
    generate_makefile()

    subprocess.run(["make", "--file=MakeFile", "main"])
