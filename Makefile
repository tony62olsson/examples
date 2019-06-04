.RECIPEPREFIX = ++

SRC_FILES := $(wildcard src/*.cc)
override RUN := $(subst :, ,$(notdir $(SRC_FILES:.cc=)))
$(info RUN = $(RUN))

.PHONY: all
all: $(RUN)
++ @for p in $^ ; do echo -------------------; echo $$p ; echo ------; ./$$p ; echo ; done

%: src/%.cc
++ g++ -std=c++17 -o $@ $<
