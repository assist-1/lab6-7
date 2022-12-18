OBJECTS=classes.o main.o

answer: $(OBJECTS)
	g++ -o answer $(OBJECTS)

.PHONY: clean
clean:
	$(RM) $(OBJECTS)

distclean: clean
	$(RM) answer