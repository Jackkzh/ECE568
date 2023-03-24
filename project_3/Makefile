TARGETS= hashing

all: $(TARGETS)

hashing: hashing.cpp
	g++ -o hashing hashing.cpp -lcrypto


.PHONY:
	clean
clean:
	rm -rf *.o hashing