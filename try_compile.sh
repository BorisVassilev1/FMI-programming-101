echo Compiling $1: \n
g++ $1 -std=c++2a -Wall -Wextra --pedantic-errors -O3
result=$?
if [ $result -eq 0 ]
	then echo Done!
	else echo Build Failed!
fi
