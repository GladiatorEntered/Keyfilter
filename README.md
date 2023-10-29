# Keyfilter
Firstproj

Hi everyone, here's first Gladiator's project in the C language.
Imagine a situation: you are a taxi driver and you have a databaze of addresses on your local device.
You have a keybord which contains standard 7-bit ASCII characters (values 0x0 - 0x7F) and start typing the address you need.
Accidently, you forget the rest of the address... But do not worry! Here you have a program that can help you in this uneasy situation.

HOW IT WORKS

Your databaze should be contained in a text file, perhaps addresses.txt. Open linux command line and type a command:

$ ./keyfilter %address% <addresses.txt

Replace %address% with beginning of the address you need. 
The program will return the keys that could be written just after the beginning of the address, e.g.:

$ cat addresses.txt

Alabama

Alert

$ ./keyfilter al <addresses.txt

Enable: A E


If there is the only address that matches your request, the program will print it:

$ ./keyfilter ala <addresses.txt

Found: Alabama

Enable: B


If there are no matches to your request, the program will print "Not found".

REQUIREMENTS FOR INPUT

Each address in the databaze file should start on a new line.
Any line shouldn't contain more than 100 characters. White space also counts as a character!
Your input line shouldn't contain more then 100 characters.
Your input line nor addresses in your databaze shouldn't contain unprintable characters, such as DEL, backspace, etc.
If your input contains more then one word< it should be written with quotes "".

