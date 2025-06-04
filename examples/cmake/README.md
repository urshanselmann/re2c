This example shows how to integrate re2c with CMake.

Build the `essl_strip_demo` executable by pointing CMake to a re2c binary:

```bash
cmake -B build -DRE2C_EXECUTABLE=/path/to/re2c
cmake --build build
```

Running the executable prints the stripped shader source.
