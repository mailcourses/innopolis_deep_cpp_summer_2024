#! /usr/bin/env python3

from setuptools import setup, Extension

def main():
    setup(name="cutils",
          version="0.2",
          author="A.A. Kukhtichev",
          date="09.07.2024",
          ext_modules=[Extension("cutils", ['cutils.cpp'])])

if __name__ == "__main__":
    main()
