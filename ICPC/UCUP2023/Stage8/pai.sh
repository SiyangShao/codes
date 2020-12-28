rm output.txt
rm myoutput.txt
rm shouldoutput.txt
./a.out 100 100 > output.txt
./C < output.txt > myoutput.txt
./D < output.txt > shouldoutput.txt
diff myoutput.txt shouldoutput.txt