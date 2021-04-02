Small utils to help emacs open file at position: 

```bash 
make # to generate the execuable 
```

In .bashrc, add: 
```bash
alias emacs_split_run="path/to/EmacsSplitLine"
function em() {
    file=$(emacs_split_run 0 $1)
    line=$(emacs_split_run 1 $1)
    column=$(emacs_split_run 2 $1)

    if test -z "$file"
    then
        emacs
        return 
    fi
    
    if [ "$line" == "0" ] && [ "$column" == "0" ]
    then
        emacs "$file"
    else
        emacs "+$line:$column" "$file"
    fi
}
```

Then you can use, following types of cmds to open file at position:
```bash
em a.cpp # normal 
em a.cpp:7 # open a.cpp and move the cursor at the begining of row 1 
em a.cpp:7:2 # open a.cpp and put the cursor at row 7, column 2 
em path/to/a.cpp:7:2 # the same as above 
```
