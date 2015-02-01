#WhereWasI

Command-line program to help you find out in what period of your life a certain date takes place.

##How to Install?

```
./configure CXXFLAGS=-DNDEBUG
make
make install
```

##How to Uninstall?

```
make uninstall
```

##How to Use?

Create a file in your home directory called ".wherewasi"  
Fill it with your own time periods in the following format:

```
[Starting Date] [Ending Date]
[Description]
```

Example:

```
2012-01-01 2012-12-31
First Year of University
2013-01-01 2013-12-31
Second Year of University
```

*Supports multiple and overlapping periods*

##How to Run?

```
wherewasi [Date]
```

Your can enter the date in the following formats:

```
[YYYY-MM-DD]
[YYYY/MM/DD]
```

Example:
```
wherewasi 2012-04-23
<2012-01-01> First Year of University <2012-12-31>
```
