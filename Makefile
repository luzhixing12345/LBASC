
CC = gcc
target ?= part1


part1:
	@python test.py $@

part2:
	@python test.py $@

part3:
	$(MAKE) -C src/part3
	@python test.py $@