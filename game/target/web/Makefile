CFLAGS = -std=c++11 -I. -I../../src -I../../../engine/src -I../../../vendor -Wall -Wextra -D__WEB__

BUILDDIR ?= build
OUTDIR ?= output
LIBDIRS := ../../../game/src ../../../engine/src
XPLAT_SOURCES_REL := $(shell find $(LIBDIRS) '(' -name '*.c' -or -name '*.cpp' ')' -not -name '*android*' -not -name '*ios*')
XPLAT_SOURCES := $(XPLAT_SOURCES_REL:../../../%=%)
XPLAT_DIRS = $(sort $(dir $(XPLAT_SOURCES) ) )
OUTPUT_DIRS = $(addprefix $(BUILDDIR)/,$(XPLAT_DIRS))

SOURCES = $(XPLAT_SOURCES)
OBJECTS = $(addprefix $(BUILDDIR)/,$(addsuffix .o,$(basename $(SOURCES))))
OBJDEPS=$(OBJECTS:%.o=%.d)

TARGET = $(OUTDIR)/xplat.html

ifeq ($(OS),Windows_NT)
    OPEN := start
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        OPEN := xdg-open
    endif
    ifeq ($(UNAME_S),Darwin)
        OPEN := open
    endif
endif

# Targets start here.
all: $(TARGET)

run: all
	@echo -n [OPEN $(TARGET)]:" " 
	@$(OPEN) $(TARGET)
	@echo done!

$(TARGET): $(OBJECTS)
	@echo -n [PACK $@]:" " 
	@$(CC) $(CFLAGS) -o $@ $(LDFLAGS) $(OBJECTS)
	@echo done!

$(BUILDDIR)/%.o : ../../../%.cpp
	@echo -n [CC $(patsubst ../../../%,%,$<)]:" " 
	@$(CC) $(CFLAGS) -MD -MP $< -o $@
	@echo done!

$(BUILDDIR)/%.o : ../../../%.c
	@echo -n [CC $(patsubst ../../../%,%,$<)]:" " 
	@$(CC) $(CFLAGS) -MD -MP $< -o $@
	@echo done!

$(OBJECTS): | $(OUTPUT_DIRS) $(OUTDIR)

$(OUTPUT_DIRS):
	@echo -n [MKDIR $@]:" " 
	@mkdir -p $@
	@echo done!

$(OUTDIR):
	@echo -n [MKDIR $@]:" " 
	@mkdir -p $@
	@echo done!

clean:
	@echo -n [CLEAN]:" " 
	@$(RM) $(TARGET) $(TARGET:%.html=%.js) $(OBJECTS) $(OBJDEPS)
	@echo done!

# list targets that do not create files (but not all makes understand .PHONY)
.PHONY:	all clean run
-include $(OBJDEPS)
