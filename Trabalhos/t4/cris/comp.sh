#find ./arquivos -type f > ./arquivos.txt || exit 1
find ./arquivos/*.txt > ./arquivos.txt || exit 1
gcc -d projeto_4.c -o projeto_4 || exit 1
./projeto_4 ./arquivos.txt
