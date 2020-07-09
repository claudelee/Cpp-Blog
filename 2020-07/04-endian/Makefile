cc       := clang++
dbg      := gdb
cxxflags  = -g
target   := app.out
main     := client.cpp
script   := gdbscript.py

build: $(main)
	@$(cc) $(cxxflags) -o $(target) $< 

execute: build
	$(dbg) --batch --command=$(script) --args $(target)

clean:
	rm -f *.out 

fmt:
	find . -type f -iname "*.cpp" | xargs clang-format -style=file -i

.PHONY: build execute clean fmt
