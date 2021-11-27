import sys
import itertools
import numpy as np

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines


def read_np(dtype=np.int64):
    return np.fromstring(read().decode(), dtype=dtype, sep=' ')


def readline_np(dtype=np.int64):
    return np.fromstring(readline().decode(), dtype=dtype, sep=' ')
