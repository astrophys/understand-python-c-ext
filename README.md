# Understanding How to Write C extensions in Python
#### Author : Ali Snedden
#### License: MIT
## Purpose:
The purpose of this code is to test my understanding of how write C extensions to 
Python



## Dependencies :
1. A modern C compiler
2. Get a copy of this code.
3. Python-3.X


## Installation and Running :
1. Create a new virtual environment for testing
```
$ python3 -m venv /path/to/new/virtualenv/py-ext-test
```
2. Activate Environment 
```
$ source /path/to/new/virtualenv/py-ext-test/bin/activate
```
3. Install Source
```
$ cd src
$ python setup.py install
```
4. Run the code
```
>>> import hellopymod
>>> hellopymod.hello_py_func("Bob")
Hello Bob!
>>> import addpymod
>>> addpymod.add_py_func(9,10,10)
29
```

## Discussion : 
I'm running this on OSX 10.15.7. I've seen places (Ref 2) where it is suggested to
compile the C-code directly into a shared library. I was having a bit of difficulty
doing that, so instead the `setup.py` method is used.  

After glancing throught Ref 3, I've concluded that learning Python's C-API for 
C extensions is probably more effort than it is worth for me to learn at this point.
The biggest issue is figuring out how to step through the C-extensions with `gdb` or
similiar tool.


## Modifications : 
If you are going to modify this code, you MUST remove previous compiled versions before
running `python setup.py install`, e.g. 
```
$ rm -rf addpymod.egg-info/ hellopymod.egg-info/ dist build/
```


## Questions
1. How do I debug C-extensions?


## References
1. [Extending Python with C or C++](https://docs.python.org/3/extending/extending.html)
2. [Inspirational Example by lucasea777](https://gist.github.com/lucasea777/8801440f6b622edd3553c8a7304bf94e)
3. [Debuging Python C Extensions with an IDE](https://pythonextensionpatterns.readthedocs.io/en/latest/debugging/debug_in_ide.html)
