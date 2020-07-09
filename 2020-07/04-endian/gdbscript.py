#!/usr/bin/env python3

import gdb

def config():
  cmd = ['break main',
         'run'];
  list(map(gdb.execute, cmd))

def trace():
  cmd = ['next',
         'next',
         'p/x m',
         'p/x n']
  list(map(gdb.execute, cmd))

if __name__ == '__main__':
  config()
  trace()
