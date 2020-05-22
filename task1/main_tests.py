#!/usr/bin/python3

import subprocess

test_cases = [(100,0,100), (10,2,4), (11,2,4), (12,2,4), (13,2,5), (986,16,58)]

for test_case in test_cases:
    cp = subprocess.run(["./task1", str(test_case[0]), str(test_case[1])], capture_output=True, timeout=1)
    output = int(cp.stdout.decode())
    if output != test_case[2]:
        print("Test case failed!")
    else:
        print("OK")
