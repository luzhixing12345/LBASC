
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
	@python src/$@/calc.py src/$@/assignment.txt

part10:
	@python src/$@/calc.py src/$@/test.pas

part11:
	@python src/$@/calc.py src/$@/test.pas

part12:
	@python src/$@/calc.py src/$@/test.pas

part13:
	@python src/$@/calc.py src/$@/test.pas

part14:
	@python src/$@/calc.py src/$@/test.pas

part15:
	-@echo "error1-----------------\n"
	-@python src/$@/calc.py -i src/$@/error1.pas -s
	-@echo "error2-----------------\n"
	-@python src/$@/calc.py -i src/$@/error2.pas -s
	-@echo "error3-----------------\n"
	-@python src/$@/calc.py -i src/$@/error3.pas -s
	-@echo "error4-----------------\n"
	-@python src/$@/calc.py -i src/$@/error4.pas -s

part16:
	@python src/$@/calc.py -i src/$@/test.pas -s

part17:
	@python src/$@/calc.py -i src/$@/test.pas --scope --stack