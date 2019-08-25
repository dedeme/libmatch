# libmatch
Utilities to organize matches.

Dependencies:
  - libdmc v. 201909 [https://github.com/dedeme/libdmc] which depends on:

    - libpthread
    - libm
    - libgc (Garbage Collector)

## Compilation

```bash
  mkdir tmp
  cd tmp
  git clone --branch 201909 https://github.com/dedeme/libmatch.git
  cd libmatch
  bash dep
  make
```

Library is in `lib/libmatch.a` and headers in `include`.

Documentation can be found in `include/libmatch_DOC.h`
