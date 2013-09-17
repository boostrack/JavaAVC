
script=cpp_cleaner.py
root_header=header1.h

all: clean header1_res0.h header1_res1.h header1_res2.h

header1_res0.h:
	python $(script) -level 0 -in $(root_header) -out $@

header1_res1.h:
	python $(script) -level 1 -in $(root_header) -out $@

header1_res2.h:
	python $(script) -level 2 -in $(root_header) -out $@

clean:
	rm -rf *_res0.h

