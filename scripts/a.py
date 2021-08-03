import os
import sys

filename = "res.txt"
with open(filename) as file_object:
    lines=file_object.readlines()
for line in lines:
  print(line)
