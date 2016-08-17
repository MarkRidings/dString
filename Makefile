all clean string string_ops dstring:
	cd src && $(MAKE) $@

install:
	cp lib/*.so /usr/local/lib64/
	cp src/*.h /usr/local/include/

.PHONY: all clean install
