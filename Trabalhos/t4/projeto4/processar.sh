clear
n=`ls ./textos -l | grep -c "^-.*"`
for i in `seq 1 $n`
do
	string=$string`find ./textos/*$i.txt`
	string=$string'\n'
done
echo "$string" > ./arquivos.txt
#find ./textos -type f > arquivos.txt || exit 1
gcc -g projeto_4.c -o projeto_4 || exit 1
#gdb projeto_4 
./projeto_4 ./arquivos.txt || exit 1