OBJECTS=classes.o main.o

answer: $(OBJECTS)
	g++ -o answer $(OBJECTS)

.PHONY: clean
clean:
	$(RM) $(OBJECTS) DefaultOutput.txt

distclean: clean
	$(RM) answer DefaultOutput.txt
