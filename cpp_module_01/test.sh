c++ -Wall -Werror -Wextra -std=c++98 *.cpp
./a.out | cat -e
./a.out | cat -e > your_output.txt
echo "Richard: This looks like another boring day.$
Richard: I am Richard, the Titled!$
Target Practice Dummy has been fwooshed!$
Richard: My job here is done!$" > right_output.txt
diff your_output.txt right_output.txt > diff.txt
if [ -s diff.txt ]
then
	printf "\033[1;31mKO\033[0m\n"
	cat diff.txt
else
	printf "\033[1;32mOK\033[0m\n"
fi
rm -rf a.out your_output.txt right_output.txt diff.txt