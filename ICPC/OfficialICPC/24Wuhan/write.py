import os
# write 5000 numbers into the file
with open('input.txt', 'w') as f:
    f.write('5000\n')
    f.write(' '.join(map(str, range(1, 5001))) + '\n')