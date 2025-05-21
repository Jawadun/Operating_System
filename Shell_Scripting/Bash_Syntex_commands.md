1. Script Start
#!/bin/bash
2. Comments
# This is a comment
3. Variables
name="Alice"
echo "Hello, $name"
4. User Input
read name
echo "You entered: $name"
5. Arithmetic
a=5
b=3
sum=$((a + b))
echo "Sum is $sum"
6. String Comparison
if [ "$a" == "$b" ]; then
echo "Equal"
fi
7. Numeric Comparison
[ $a -eq $b ] # equal
[ $a -ne $b ] # not equal[ $a -gt $b ] # greater than
[ $a -lt $b ] # less than
8. Logical Operators
if [ $a -gt 5 ] && [ $a -lt 10 ]; then
echo "a is between 5 and 10"
fi
9. If / Else / Elif
if [ $a -gt $b ]; then
echo "a > b"
elif [ $a -eq $b ]; then
echo "a = b"
else
echo "b > a"
fi
10. Loops
for i in 1 2 3; do
echo $i
done
count=1
while [ $count -le 5 ]; do
echo $count
((count++))
done
11. Case Statementread option
case $option in
1) echo "One";;
2) echo "Two";;
*) echo "Invalid";;
esac
12. Functions
greet() {
echo "Hello $1"
}
greet "Alice"
13. Command Substitution
today=$(date)
echo "Today is $today"
14. File Test Operators
[ -f file.txt ] # file exists
[ -d dir ]# directory exists
[ -r file ]# readable
[ -w file ]# writable
15. Positional Parameters
$0 - script name
$1 - first argument
$2 - second argument16. Redirection
command > file.txt # overwrite
command >> file.txt # append
17. Pipes
ls | grep ".txt"
18. Loop with Range
for i in {1..5}; do
echo $i
done
19. Sleep
sleep 2 # sleep for 2 seconds
20. Exit Status
command
if [ $? -eq 0 ]; then
echo "Success"
fi
