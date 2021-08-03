import os
import sys

filename = "res.txt"
with open(filename) as file_object:
    lines=file_object.readlines()
for line in lines:
    name=name[1:]
    name=line[:-4]
    num=name.rfind('/')
    content=name[:num]
    filename=name[num:]
    #文件名
    cpp=name+'.cpp'
    indata=name+'.in'
    ansdata=name+'.ans'
    outdata=name+'.out'
    cmd='g++ '+cpp+' -o '+name
    #判断CE
    if os.system(cmd)==0 :
        print(cpp+' Successfully compiled')
    else:
        print(cpp+' Compiled Error')
        sys.exit(1)
    #运行程序并重定向输出
    cmd='sudo '+content+'/.'+filename+' <'+indata+'> '+outdata
    os.system(cmd)
    #判断RE
    if os.system(cmd)==0:
        print(cpp+' Run successfully')
    else:
        print(cpp+' Runtime Error')
        sys.exit(1)
    #判断答案
    cmd='diff -b -B '+outdata+' '+ansdata
    if os.system(cmd)==0 :
        print(cpp+' Successfully passed the test')
    else:
        print(cpp+ ' Wrong Answer')
        sys.exit(1)