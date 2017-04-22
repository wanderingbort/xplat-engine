MAKEFILE_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
CFLAGS = -std=c++11 -I$(MAKEFILE_DIR) -Igame/src -Iengine/src -Ivendor -Wall -Wextra -D__WEB__

BUILDDIR ?= $(MAKEFILE_DIR)/build
OUTDIR ?= $(MAKEFILE_DIR)/output
LIBDIRS := game/src engine/src
XPLAT_SOURCES := $(shell find $(LIBDIRS) '(' -name '*.c' -or -name '*.cpp' ')' -not -name '*android*' -not -name '*ios*')
XPLAT_DIRS = $(sort $(dir $(XPLAT_SOURCES) ) )

SOURCES = $(XPLAT_SOURCES)
OBJECTS = $(addprefix $(BUILDDIR)/,$(addsuffix .o,$(basename $(SOURCES))))
OBJECTDIRS = $(addprefix $(BUILDDIR)/,$(XPLAT_DIRS))
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

$(BUILDDIR)/%.o : %.cpp
	@echo -n [CC $<]:" " 
	@$(CC) $(CFLAGS) -MD -MP $< -o $@
	@echo done!

$(BUILDDIR)/%.o : %.c
	@echo -n [CC $<]:" " 
	@$(CC) $(CFLAGS) -MD -MP $< -o $@
	@echo done!

$(OBJECTS): | $(OBJECTDIRS) $(OUTDIR)

$(OBJECTDIRS):
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
	@$(RM) -rf $(BUILDDIR)
	@echo done!

# list targets that do not create files (but not all makes understand .PHONY)
.PHONY:	all clean run
-include $(OBJDEPS)
