clear
find ./textos -type f > arquivos.txt || exit 1
gcc -g projeto_4.c -o projeto_4 || exit 1
#gdb projeto_4 
./projeto_4 ./arquivos.txt || exit 1