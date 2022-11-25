
CC = gcc
target ?= part1


part1:
	@python test.py $@

part2:
	@python test.py $@

part3:
	$(MAKE) -C src/part3
	@python test.py $@

part4:
	@python test.py $@

part5:
	@python test.py $@

part6:
	$(MAKE) -C src/part6
	@python test.py $@

part7:
	@python test.py $@

part8:
	@python test.py $@

part9:
	@python src/part9/calc.py src/part9/assignment.txt

part10:
	@python src/part10/calc.py src/part10/test.pas

part11:
	@python src/part11/calc.py src/part11/test.pas