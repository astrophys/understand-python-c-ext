# Understanding How to Write C extensions in Python
#### Author : Ali Snedden
#### License: MIT
## Purpose:
The purpose of this code is to test my understanding of how write C extensions to 
Python



## Installation and Dependencies :
1. A modern C compiler
2. Get a copy of this code.
3. Python-3.X


## Installation: 
1. Create a new virtual environment for testing
```$ python3 -m venv /path/to/new/virtualenv/py-ext-test```
2. Activate Environment 
```$ source /path/to/new/virtualenv/py-ext-test/bin/activate```
3. Install Source
```
$ cd src
$ python setup.py install
```

## Discussion : 
I'm running this on OSX 10.15.7. I've seen places (Ref 2) where it is suggested to
compile the C-code directly into a shared library. I was having a bit of difficulty
doing that, so instead the `setup.py` method is used.  


## References
1. [Extending Python with C or C++](https://docs.python.org/3/extending/extending.html)
2. [Inspirational Example by lucasea777](https://gist.github.com/lucasea777/8801440f6b622edd3553c8a7304bf94e)
