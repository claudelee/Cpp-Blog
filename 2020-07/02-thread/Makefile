cc       := clang++
cxxflags  = -Wall -Wextra -Werror
cxxflags += -g
cxxflags += -O2
cxxflags += -std=c++20
ldflag   := -pthread
target   := app.out
main     := client.cpp

build: $(main)
	@$(cc) $(cxxflags) -o $(target) $< $(ldflag)

execute: build
	@./$(target)

clean:
	rm -f *.out 

fmt:
	find . -type f -iname "*.cpp" | xargs clang-format -style=file -i

.PHONY: build execute clean fmt
