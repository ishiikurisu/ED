clear

rm index
echo "compiling..."
gcc index.c -o index || exit
echo "comṕiled! running app..."

./index
