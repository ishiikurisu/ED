find ./arquivos/*.txt > ./arquivos.txt || exit 1
gcc arquivos.txt projeto_4.c -o projeto_4 || exit 1
./projeto_4