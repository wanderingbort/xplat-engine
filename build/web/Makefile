MAKEFILE_DIR:=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
CFLAGS = -std=c++11 -O3 --memory-init-file 0 -Igame/src -Iengine/src -Ivendor -Wall -Wextra -D__WEB__

ifndef GAMEDIR
	$(error GAMEDIR is not set!)
endif

SAFE_GAMEDIR := $(GAMEDIR:%/=%)
BUILDDIR ?= $(SAFE_GAMEDIR)/build
OUTDIR ?= $(SAFE_GAMEDIR)/output
XPLAT_SOURCES := $(shell find engine/src '(' -name '*.c' -or -name '*.cpp' ')' -not -name '*android*' -not -name '*ios*')
GAME_SOURCES := $(shell find $(SAFE_GAMEDIR)/src '(' -name '*.c' -or -name '*.cpp' ')' -not -name '*android*' -not -name '*ios*')
GAME_SOURCES_REL := $(patsubst $(SAFE_GAMEDIR)/src/%,%, $(GAME_SOURCES))

XPLAT_DIRS = $(sort $(dir $(XPLAT_SOURCES)))
GAME_DIRS = $(addprefix game/, $(sort $(dir $(GAME_SOURCES_REL))))

XPLAT_OBJECTS = $(addprefix $(BUILDDIR)/,$(addsuffix .o,$(basename $(XPLAT_SOURCES))))
GAME_OBJECTS = $(addprefix $(BUILDDIR)/game/, $(addsuffix .o,$(basename $(GAME_SOURCES_REL))))
OBJECTS = $(XPLAT_OBJECTS) $(GAME_OBJECTS)
OBJECTDIRS = $(addprefix $(BUILDDIR)/,$(XPLAT_DIRS) $(GAME_DIRS))
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

$(BUILDDIR)/game/%.o : $(SAFE_GAMEDIR)/src/%.cpp
	@echo -n [GAME CC $<]:" " 
	@$(CC) $(CFLAGS) -MD -MP $< -o $@
	@echo done!

$(BUILDDIR)/game/%.o : $(SAFE_GAMEDIR)/src/%.c
	@echo -n [CC $<]:" " 
	@$(CC) $(CFLAGS) -MD -MP $< -o $@
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
