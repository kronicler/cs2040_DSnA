infile = open("num.txt",'r')
result = 0

for line in infile.readlines():
    temp = line.split("\t")
    first = True
    hi = 0
    lo = 0
    for num in temp:
        if first:
            hi = int(num)
            lo = int(num)
            first = False
        if hi < int(num):
            hi = int(num)
        elif lo > int(num):
            lo = int(num)
    result += (hi - lo)
        
print(result)
    
