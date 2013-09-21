
script=cpp_cleaner.py
inc_dir=include
root_header=$(inc_dir)/header1.h

all: clean header1_res0.h header1_res1.h header1_res2.h

header1_res0.h:
	python $(script) -l 0 -I $(inc_dir) -o $@ $(root_header)

header1_res1.h:
	python $(script) -l 1 -I $(inc_dir) -o $@ $(root_header)

header1_res2.h:
	python $(script) -l 2 -I $(inc_dir) -o $@ $(root_header)

clean:
	rm -rf *_res*

