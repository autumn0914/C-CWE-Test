#####################################################################  
## file        : test makefile for build current dir .c            ##  
## author      : jernymy                                           ##  
## date-time   : 05/06/2010                                        ##  
#####################################################################  
  
CC      = gcc  
CPP     = g++  
RM      = rm -rf  
#RM      = del /f
  
## debug flag  
DBG_ENABLE   = 1  
  
## source file path  
SRC_PATH   := .  
  
## target exec file name  
TARGET     := test  
  
## get all source files  
#SRCS         += $(wildcard $(SRC_PATH)/*.c)  
SRCS		:= $(wildcard *.c)

  
## all .o based on all .c  
OBJS        := $(SRCS:.c=.o)  
  
  
## need libs, add at here  
LIBS := pthread  
  
## used headers  file path  
INCLUDE_PATH := .  
  
## used include librarys file path  
LIBRARY_PATH := /lib  
  
## debug for debug info, when use gdb to debug  
ifeq (1, ${DBG_ENABLE})   
    CFLAGS += -D_DEBUG -O0 -g -DDEBUG=1  
endif  
  
## get all include path  
#CFLAGS  += $(foreach dir, $(INCLUDE_PATH), -I$(dir))  
  
## get all library path  
LDFLAGS += $(foreach lib, $(LIBRARY_PATH), -L$(lib))  
  
## get all librarys  
LDFLAGS += $(foreach lib, $(LIBS), -l$(lib))  
  
  
all: clean build  
  
build:  
	@echo $(SRCS)
	$(CC) -c $(SRCS)

clean:
	$(RM) $(OBJS) $(TARGET) 
