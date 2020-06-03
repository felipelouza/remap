# remap 

This repository contains a set of methos for reordering the alphabet of a string T\[1,n\].

We investigate the effect of each alphabet reordering on the total number of Lyndon factors.

## Build requirements

An C++ Compiler (e.g. GNU G++)

## Example

**Compilation:**

```sh
make
```

**Available options:**

```sh
-A a	preferred algorithm to use (default 0)
-d D	use the first D documents of the INPUT
-b	read INPUT as binary input 
-f	read INPUT as (default) formatted input (.txt, .fasta or .fastq)
-v	verbose output
-s	compute the number of Lyndon Factors and the maximum length
-o  output converted file
-l  output the lyndon-factors (start positions) to (INPUT.pos)
-L  output the lyndon-factors (substrings) to (INPUT.lyn)
-p P	print the first P Lyndon factors (for debug)
-h	this help message

```
_Notes:_ 
- Supported extensions are _.txt_, _.fasta_ and _.fastq_.

**Algorithms:**

| -A | Algorithm      |         Output           |
|:--:|----------------|--------------------------|
|  0 | None           |    Identity alphabet     |      
|  7 | Random         |    Randomize permutation |      


**Run a test:**

```c
./remap -A 7 -v ../dataset/reads.fastq
```

**Output:**

```c
Command line:
 ./remap -A 7 -v ../dataset/reads.fastq
d = 10000
N = 946583 bytes
sizeof(int) = 4 bytes
## RANDOM ##
A: G
C: N
G: A
N: C
T: T
##
Number of Lyndon factors: 15
Average length: 63105.53
Maximum length: 605983
##
15	63105.53	605983
```

