# Read from the file words.txt and output the word frequency list to stdout.
tr -s ' ' '\n' < words.txt | sort | uniq -c | sort -k1,1rn | awk '{print $2, $1}'
