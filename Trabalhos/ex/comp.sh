rm index
echo "compiling..."
gcc index.c -o index || exit
clear
echo "comṕiled! running app..."

./index
