################
# Paths and Flags
################
SHELL = /bin/bash
TARGET_PATH = ../bin
TARGET_NAME_OPT = robot
TARGET_NAME_DBG = $(TARGET_NAME_OPT)_dbg
OBJ_PATH = ../obj
INSTALL_LOCATION_INCLUDE ?= /usr/local/include
UNAME = $(shell uname -s)
OPEN_CV = -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core
SDL_CV = -lSDL2 -lSDL2_image
ifeq ($(UNAME),Darwin)
	CFLAGS = -I/opt/local/include -I/usr/local/include -I/sw/include -I../../../src -I$(INSTALL_LOCATION_INCLUDE) -D_THREAD_SAFE -DDARWIN -no-cpp-precomp -std=gnu++11
	DBG_CFLAGS = $(CFLAGS) -g -D_DEBUG $(OPEN_CV)
	OPT_CFLAGS = $(CFLAGS) -O3 $(OPEN_CV)
	LFLAGS = -L/opt/local/lib -L/usr/local/lib -L/sw/lib -L../../../lib -framework AppKit
	DBG_LFLAGS = $(LFLAGS) -lpthread ../../../lib/libGClassesDbg.a $(SDL_CV)
	OPT_LFLAGS = $(LFLAGS) -lpthread ../../../lib/libGClasses.a $(SDL_CV)
else
	CFLAGS = -Wall -Werror -Wshadow -pedantic -I$(INSTALL_LOCATION_INCLUDE) -I../../../src -std=gnu++11
	DBG_CFLAGS = $(CFLAGS) -g -D_DEBUG
	OPT_CFLAGS = $(CFLAGS) -O3
	LFLAGS = -L../../../lib -lpng -ljpeg
	DBG_LFLAGS = $(LFLAGS) -lGClassesDbg -lpthread $(OPEN_CV) $(SDL_CV)
	OPT_LFLAGS = $(LFLAGS) -lGClasses -lpthread $(OPEN_CV) $(SDL_CV)
endif

################
# Source
################

CPP_FILES =\
	main.cpp\
	Styler.cpp\

################
# Lists
################

TEMP_LIST_OPT = $(CPP_FILES:%=$(OBJ_PATH)/opt/%)
TEMP_LIST_DBG = $(CPP_FILES:%=$(OBJ_PATH)/dbg/%)
OBJECTS_OPT = $(TEMP_LIST_OPT:%.cpp=%.o)
OBJECTS_DBG = $(TEMP_LIST_DBG:%.cpp=%.o)
DEPS_OPT = $(TEMP_LIST_OPT:%.cpp=%.d)
DEPS_DBG = $(TEMP_LIST_DBG:%.cpp=%.d)

################
# Rules
################

.DELETE_ON_ERROR:

dbg : $(TARGET_PATH)/$(TARGET_NAME_DBG)

opt : $(TARGET_PATH)/$(TARGET_NAME_OPT)

usage:
	@echo ""
	@echo "Usage:"
	@echo "  make usage   (to see this info)"
	@echo "  make clean   (to delete all the .o files)"
	@echo "  make dbg     (to build a debug version)"
	@echo "  make opt     (to build an optimized version)"
	@echo ""

# This rule makes the optimized binary by using g++ with the optimized ".o" files
$(TARGET_PATH)/$(TARGET_NAME_OPT) : partialcleanopt $(OBJECTS_OPT)
	g++ -O3 -o $(TARGET_PATH)/$(TARGET_NAME_OPT) $(OBJECTS_OPT) $(OPT_LFLAGS)

# This rule makes the debug binary by using g++ with the debug ".o" files
$(TARGET_PATH)/$(TARGET_NAME_DBG) : partialcleandbg $(OBJECTS_DBG)
	g++ -g -o $(TARGET_PATH)/$(TARGET_NAME_DBG) $(OBJECTS_DBG) $(DBG_LFLAGS)

# This includes all of the ".d" files. Each ".d" file contains a
# generated rule that tells it how to make .o files. (The reason these are generated is so that
# dependencies for these rules can be generated.)
-include $(DEPS_OPT)

-include $(DEPS_DBG)

# This rule makes the optimized ".d" files by using "g++ -MM" with the corresponding ".cpp" file
# The ".d" file will contain a rule that says how to make an optimized ".o" file.
# "$<" refers to the ".cpp" file, and "$@" refers to the ".d" file
$(DEPS_OPT) : $(OBJ_PATH)/opt/%.d : %.cpp
	@echo -e "Computing opt dependencies for $<"
	@-rm -f $$(dirname $@)/$$(basename $@ .d).o
	@if [ ! -d "$$(dirname $@)" ]; then mkdir -p "$$(dirname $@)"; fi
	@echo -en "$$(dirname $@)/" > $@
	@g++ $(OPT_CFLAGS) -MM $< >> $@
	@echo -e "	g++ $(OPT_CFLAGS) -c $< -o $$(dirname $@)/$$(basename $@ .d).o" >> $@

# This rule makes the debug ".d" files by using "g++ -MM" with the corresponding ".cpp" file
# The ".d" file will contain a rule that says how to make a debug ".o" file.
# "$<" refers to the ".cpp" file, and "$@" refers to the ".d" file
$(DEPS_DBG) : $(OBJ_PATH)/dbg/%.d : %.cpp
	@echo -e "Computing dbg dependencies for $<"
	@-rm -f $$(dirname $@)/$$(basename $@ .d).o
	@if [ ! -d "$$(dirname $@)" ]; then mkdir -p "$$(dirname $@)"; fi
	@echo -en "$$(dirname $@)/" > $@
	@g++ $(DBG_CFLAGS) -MM $< >> $@
	@echo -e "	g++ $(DBG_CFLAGS) -c $< -o $$(dirname $@)/$$(basename $@ .d).o" >> $@

partialcleandbg :
	@if [ ! -d "$(TARGET_PATH)" ]; then mkdir -p "$(TARGET_PATH)"; fi
	@rm -f $(TARGET_PATH)/$(TARGET_NAME_DBG)

partialcleanopt :
	@if [ ! -d "$(TARGET_PATH)" ]; then mkdir -p "$(TARGET_PATH)"; fi
	@rm -f $(TARGET_PATH)/$(TARGET_NAME_OPT)

clean : partialcleandbg partialcleanopt
	rm -f $(OBJECTS_OPT)
	rm -f $(OBJECTS_DBG)
	rm -f $(DEPS_OPT)
	rm -f $(DEPS_DBG)
