## Usage


**build .a library**

```
$ gcc -c -g -fno-builtin -nostdlib entry.c util.c
$ ar -rs minicrt.a util.o entry.o 
```

**build executable file**

```
$ gcc -c -g -fno-builtin -nostdlib test.c
$ ld -static -e mini_crt_entry test.o minicrt.a -o test
```

**print test.c**

```
$ ./test test.c 
```

实现细节见文章[<实现一个简单的CRT>](https://github.com/chenpengcong/blog/issues/24)
