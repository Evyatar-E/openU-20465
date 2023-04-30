# To refresh the compilation and the
# corresponding I/O sample files at once,
# simply run the command:
# ../../refresh.sh >../../refresh.log  2>&1
# or:
# ../../re.sh

make
echo -e "\tM↺\n"

prog_folder="${PWD##*/}"
echo -e ">>================== Input & Output together =================<<" >./IO/_IO.txt
echo -e ">>================== Input together =================>>" >./IO/I.txt
echo -e "<<================== Output together =================<<" >./IO/O.txt
n=0
for n in $(seq 0 7); do
  ./${prog_folder} <./IO/i${n}.txt >./IO/o${n}.txt 2>&1
  #valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./myset < input

  # clean escape chars
  rpl -q '[3;J[H[2J' '
~ a <clear-screen_escape_character> here ~
' ./IO/o${n}.txt >../../refresh.garbage.log 2>&1
  # rm refresh.garbage.log

  echo -e "\n\n>>------- ./IO/i${n}.txt ------->>" | cat >>./IO/I.txt
  cat <./IO/i${n}.txt | cat >>./IO/I.txt
  echo -e "\n\n>>------- ./IO/i${n}.txt ------->>" | cat >>./IO/_IO.txt
  cat <./IO/i${n}.txt | cat >>./IO/_IO.txt

  echo -e "\n\n<<------- ./IO/o${n}.txt -------<<" | cat >>./IO/O.txt
  cat <./IO/o${n}.txt | cat >>./IO/O.txt
  echo -e "\n\t<<------- ./IO/o${n}.txt -------<<" | cat >>./IO/_IO.txt
  cat <./IO/o${n}.txt | cat >>./IO/_IO.txt

  ((n += 1))
done

rm .fuse_hidden*
echo -e "\tF↺\n"

echo -e "Next, use:"
echo "../../refresh.sh >../../refresh.log  2>&1"