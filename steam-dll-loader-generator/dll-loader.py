import os,fnmatch

def find_dlls(directory, pattern):
    for root, dirs, files in os.walk(directory):
        for basename in files:
            if fnmatch.fnmatch(basename,pattern):
                filename = basename
                yield filename

src = input('Input Path: ')

print('WINEDLLOVERRIDES="', end='')
firstprint = True
for filename in find_dlls(src, '*.dll'):
    if firstprint:
        firstprint = False
    else:
        print(',', end='')
    print(filename, end='')
print('"')
