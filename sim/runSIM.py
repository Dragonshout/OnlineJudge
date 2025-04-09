# -*- coding: utf-8 -*-
import os
import subprocess

#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import time

from oj.settings import BASE_DIR


def runSIM(mode, argv):
    nowPath = os.path.join(BASE_DIR, "sim")
    nowPath = os.path.join(nowPath, 'SIM')
    fileName = 'sim_' + mode + '.exe'
    nowPath = os.path.join(nowPath, fileName)
    # print(nowPath)
    argv = nowPath + ' ' + argv
    # res = os.popen(argv)
    # res.close()
    #print(argv)
    p = subprocess.Popen(argv, stdin=subprocess.PIPE,
                         stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    p.wait()
    return


def run_sim(file_path, mode, threshold):
    os.chdir(file_path)
    print(os.getcwd())
    argv = '-p -t ' + str(int(threshold * 100))
    argv = argv + ' -o sim_res.txt *.*'
    runSIM(mode, argv)
    argv = '-o sim_res_all.txt *.*'
    runSIM(mode, argv)
