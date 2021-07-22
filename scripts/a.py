import os

filename = "res.txt"
with open(filename) as file_object:
    lines=file_object.readlines()
for line in lines:
    name=line[:-4]
    print(name)
    mddoc=name+'.md'
    cpp=name+'.cpp'
    indata=name+'.in'
    ansdata=name+'.ans'
    outdata=name+'.out'
    #change the file name to cpp
    cmd="sed -i '1d' "+mddoc
    os.system(cmd)
    cmd="sed -i '$d' "+mddoc
    os.system(cmd)
    os.rename(mddoc,cpp) 
    #compile cpp file and get stdout into file
    cmd='g++ '+cpp+' -o '+name
    os.system(cmd)
    cmd="./"+name+" <"+indata+"> "+outdata
    os.system(cmd)
    cmd='diff -b -B '+outdata+' '+ansdata
    os.system(cmd) 