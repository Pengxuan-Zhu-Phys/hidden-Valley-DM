.PHONY: all clean flags

all: include/microPath.h include/json.h
	$(MAKE) -C CalcHEP_src MICROMEGAS=MICROMEGAS
	$(MAKE) -C sources

include/microPath.h:
	@echo \#define micrO \"$(CURDIR)\" > include/microPath.h

include/json.h:
	ln -s /usr/include/json-c/json.h include/json.h

clean:
	rm -f include/microPath.h include/json.h
	rm -f ._* Packages/._* man/._* include/._*
	rm -f Data/._* Data/*/._* Data/*/*/._*
	rm -fr lib/*.a lib/*.so lib/*.o lib/._* lib/*.dSYM
	$(MAKE) -C $(CURDIR)/CalcHEP_src clean
	$(MAKE) -C $(CURDIR)/sources clean
	./clean

flags:
	$(MAKE) -C CalcHEP_src flags
