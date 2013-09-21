CLN_CPP=CPP_Cleaner/cpp_cleaner.py
INC_DIR=include

all: avcodec avdevice avfilter avformat avutil swresample swscale


avcodec avdevice avfilter avformat swresample swscale:
	python $(CLN_CPP) -I $(INC_DIR) -l 2 -o $@.h $(INC_DIR)/lib$@/$@.h


avutil:
	python $(CLN_CPP) -I $(INC_DIR) -l 2 -o $@.h $(INC_DIR)/lib$@/$@.h

clean:
	rm -rf *.h

