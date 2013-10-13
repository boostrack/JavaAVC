
script=cpp_cleaner.py
inc_dir=include
root_header=$(inc_dir)/dir1/header1.h

all: clean header1_res0.h header1_res1.h header1_res2.h

header1_res0.h:
	python $(script) -I $(inc_dir) -o $@ $(root_header)

header1_res1.h:
	python $(script) -I $(inc_dir) -F dir1 -o $@ $(root_header)

header1_res2.h:
	python $(script) -I $(inc_dir) -F dir1 -F dir2 -o $@ $(root_header)

clean:
	rm -rf *.h

