#!/usr/bin/python


import sys
import os


code_cmd = {
    'cpp': '../cpp/fb_test',
    'python': '../python/fb_test.py',
    'javascript': 'node ../javascript/fb_test.js',
    'java': 'java ../java/fb_test.java',
}


if __name__ == '__main__':

    # Get command line arguments.
    code_dir = sys.argv[1]

    for infile in sorted(os.listdir('.')):
        if infile.endswith('.in'):
            valid_number = infile.split('.')[0]
            outfile = valid_number + '.out'
            fi = open(infile, 'r')
            os.system(code_cmd[code_dir] + ' -v ' + fi.readline().split('\n')[0] + ' > test.out')
            fi.close()
            fo = open(outfile, 'r')
            ft = open('test.out', 'r')
            valid = True
            for outline in fo.readlines():
                testline = ft.readline()
                if outline.split('\n')[0] != testline.split('\n')[0]:
                    valid = False
                    break
            print(valid_number + ' ' + str(valid))
            fo.close()
            ft.close()
