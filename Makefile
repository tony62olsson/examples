.RECIPEPREFIX = @

SRC_FILES := $(wildcard src/*.cc)
STD := 17
override RUN := $(notdir $(SRC_FILES:.cc=))
#$(info RUN = $(RUN))

.PHONY: all
all: $(RUN)

list:
@@echo $(RUN)

.PHONY: FORCE
FORCE:

define target
$1: bin/$1
@@echo
@@echo $$@
@@echo -----------------------------
@@$$<
endef
$(foreach t,$(RUN),$(eval $(call target,$t)))

bin/%: src/%.cc
@@mkdir -p bin
@g++ -std=c++$(STD) -o $@ $<
