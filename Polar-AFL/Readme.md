#  Polar-AFL
Polar-AFL is an extension of AFL with framework Polar for ICS protocol. 

Polar-AFL is a fork of AFL that has been shown to outperform AFL 2.52b by function-code aware fuzzing strategy. 



##  Build
Before using Polar-AFL, cJSON should be installed to support function code specification (JSON format)



Linux:

```shell
  $ git clone https://github.com/DaveGamble/cJSON.git
  $ cd cJSON
  $ mkdir build
  $ cd build
  $ cmake .. -DENABLE_CJSON_UTILS=On -DENABLE_CJSON_TEST=Off -DCMAKE_INSTALL_PREFIX=/usr
  $ make
  $ sudo make DESTDIR=$pkgdir install
```



Then, Polar-AFL can be built like:

```shell
$ make
```



As the compiler of program-under-test, `aft-clang-fast` should be built like following(note: `afl-clang-fast` will be built in the above `make`, therefore it is unneccessary to compile it especially): 

```shell
$ cd llvm_mode
$ make AFL_TRACE_PC=1
```





##  Usage

| Polar-AFL flag | Power Schedule             |
| ------------- | -------------------------- |
| `-j funcinfo_dir ` | Using function code aware strategy, funcinfo should  be in the JSON format |
| `-p ` | Assign more energy to seeds exercising vulnerable operations |

*funcinfo* should be in the following  JSON format:

```
{
	"start":	56,
	"end":	63,
	"candidates": [1, 2, 3, 4, 5, 6, 7, 15, 16, 17, 22, 23]
}
```
### Polar Instrumentation
Polar Instrumentation should follow the following form:
```c
__POLAR_INS((1<<16)+ID);  // Polar Instrumentation
```
where `ID` is the `Func_ID` or `Vul_ID` and it starts from 0. (1<<16 is the size of shared memory in base fuzzer(AFL/AFLFast)


Which means the range of function code field in **bit** is [56, 63] (index starts from **0**) , and the candidate values are listed in line 4.


## Demo
There is a demo in folder `demo` which illustrates how to instrument and compile using `afl-clang-fast`. You can run the demo by

```shell
make demo 
```
