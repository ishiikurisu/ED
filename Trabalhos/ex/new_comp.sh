clear
gcc new_index.c -o new_index || exit 1
./new_index; > outline.txt
#more outline.txt
