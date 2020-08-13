# looknsay

An implementation of the look-and-say sequence

## Explanation

The look-and-say sequence is a sequence of integers that proceeds like this:

```
1
11
21
1211
111221
312211
13112221
1113213211
31131211131221
13211311123113112211
11131221133112132113212221
etc.
```

It progresses by `look`ing at an integer, and `say`ing the number of consecutive identical digits from left to right.

```
1 = one 1 = 11
11 = two 1s = 21
21 = one 2, one 1 = 1211
1211 = one 1, one 2, two 1s = 111221
111221 = three 1s, two 2s, one 1 = 312211
etc.
```

[Further information](http://en.wikipedia.org/wiki/Look-and-say_sequence)

## Usage

```bash
Usage: looknsay <start> <iterations>
```

So, to list a sequence of 10 integers starting at `1`:

```bash
looknsay 1 10
```

## Installation

```bash
make && sudo make install
```
