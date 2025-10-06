### How to complile
```bash
cmake -B build -S .
cd build
./main
```

### Want to add a file to library?
- make sure to include the file name in the `add_library()` function in the libraries CMakeLists.txt. The process is the same for the main program

### Dynamic or Static linking?
- [STATIC] linking copies the library into the main programs final executable at link time
- [SHARED] linking compiles the library into a separate .so (linux) or .dll (windows) file, loaded at runtime. That file must me shared alongside the executable and has to be in the same directory.

#### Where to change?
- At the library's `add_library()` function, after indicating the library target, the next argument is either [SHARED] or [STATIC]
