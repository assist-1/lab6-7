OBJECTS=classes.o main.o

answer: $(OBJECTS)
	g++ -o answer $(OBJECTS)

.PHONY: clean
clean:
	$(RM) $(OBJECTS) DefaultFile.txt

distclean: clean
	$(RM) answer DefaultFile.txt