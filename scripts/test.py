import os
import sys
import json

annotations = []

def generate_annotations_and_exit():
    with open('annotations.json', 'w') as outfile:
        json.dump(annotations, outfile)
    sys.exit(1)


filename = "res.txt"
with open(filename) as file_object:
    lines = file_object.readlines()
for line in lines:
    name = line[:-5]
    num = name.rfind('/')
    content = name[:num]
    filename = name[num:]
    # 文件名
    cpp = name+'.cpp'
    indata = name+'.in'
    ansdata = name+'.ans'
    outdata = name+'.out'
    indata = indata.replace('code', 'examples')
    outdata = outdata.replace('code', 'examples')
    ansdata = ansdata.replace('code', 'examples')
    cmd = 'g++ '+cpp+' -o '+name
    # 判断CE
    if os.system(cmd) == 0:
        print(cpp+' Successfully compiled')
    else:
        print(cpp+' Compiled Error')
        annotations.append({
            'file': cpp,
            'line': 1,
            'title': "Compiled Error",
            'message': "",
            'annotation_level': "failure"
        })
        generate_annotations_and_exit()
    # 运行程序并重定向输出
    cmd = content+'/.'+filename+' <'+indata+'> '+outdata
    os.system(cmd)
    # 判断RE
    if os.system(cmd) == 0:
        print(cpp+' Run successfully')
    else:
        print(cpp+' Runtime Error')
        annotations.append({
            'file': cpp,
            'line': 1,
            'title': "Runtime Error",
            'message': "",
            'annotation_level': "failure"
        })
        generate_annotations_and_exit()
    # 判断答案
    cmd = 'diff -b -B '+outdata+' '+ansdata
    if os.system(cmd) == 0:
        print(cpp+' Successfully passed the test')
    else:
        print(cpp + ' Wrong Answer')
        annotations.append({
            'file': cpp,
            'line': 1,
            'title': "Wrong Answer",
            'message': "",
            'annotation_level': "failure"
        })
        generate_annotations_and_exit()
