all: EmacsSplitLine TestSplitString

.PHONY: clean $all

EmacsSplitLine: main.cpp
	g++ -o $@ $^

TestSplitString: TestSplitString.cpp
	g++ -o $@ $^

clean:
	rm EmacsSplitLine
	rm TestSplitString
