import os

os.chdir(r"C:\prog\gitrepos\cp_practice\ABC")
files = os.listdir()

for file in files:
    l = len(file)
    ##print(file[l-3:])
    if(file[:3] ==  "ABC" and file[l-3:]=="cpp"):
        os.renames(file,file[:6]+"\\"+file)