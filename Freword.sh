#!/bin/bash

ARGS=1                                        # Number of argument expected from user.
if [ $# -ne "$ARGS" ]                         # To check the number of argument.
then
  echo "Please enter command with filename"   # When the user forgets to enter the file name.
  exit 0
fi
                                             
if [ ! -f "$1" ]                              # Check if file exists.
then
  echo "File \"$1\" does not exist."          # When the file does not exist.
  exit 0
fi
echo "The words and frequencies contained in the file"
cat "$1" | xargs -n1 | \
#  List the file, one word per line. 
tr A-Z a-z | \
#  Uppercase characters to lowercase.
sed -e 's/\.//g'  -e 's/\,//g' -e 's/ /\
/g' | \
#  Filter points and commas, and change space between words to line feed. 
sort | uniq -c | sort -nr
#  Frequency of words and sort numerically.
exit 0
